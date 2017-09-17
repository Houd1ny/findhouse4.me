#!/usr/bin/env python3

import requests
from bs4 import BeautifulSoup
from lxml import etree
from urllib import parse 
import re

def get_list_of_appartmens(html_tree):
    root_search_elem = html_tree.xpath('//*[@id="search_result"]')
    parsed_list = [elem.xpath('.//div/div/div/a/@href') for elem in root_search_elem[0]]
    flat_list = [item for sublist in parsed_list for item in sublist]
    return flat_list



def get_appartment_data(appart_link):
    r = requests.get(appart_link)
    html_tree = etree.HTML(r.text)
    google_map_url = html_tree.xpath('//iframe/@src')[0]
    parsed = parse.urlparse(google_map_url)
    coordinates = parse.parse_qs(parsed.query)['q'][0] 
    appartment_details_node = html_tree.xpath("//*[@class='row row-dense block-list-square font-size-16']")[0]
    appartment_details = etree.tostring(appartment_details_node, encoding='utf-8').decode() 
    m = re.search(r'Ціна:\s*(.*?)\s*грн', appartment_details)
    price = int(m.group(1).replace(" ", "")) if m else 0
    m = re.search(r'\/(\d+)-', appart_link)
    appart_id = int(m.group(1))
    m = re.search(r'Днів на сайті:\s(\d+)', appartment_details)
    days_on_site = int(m.group(1)) if m else 0
    return {'appart_id': appart_id, 'appart_link': appart_link, 
    'coordinates': coordinates, 'price': price, 'days_on_site':days_on_site}

r = requests.get('https://www.real-estate.lviv.ua/orenda-kvartira/Lviv')
html_tree = etree.HTML(r.text)
count_of_pages = int(html_tree.xpath("//li[@class='last']/a")[0].text)

all_pages_links = ["https://www.real-estate.lviv.ua/orenda-kvartira/Lviv/p_" + str(number) 
                                                for number in range(1, count_of_pages+1)]

def get_apparments_data_from_page(page_link):
    r = requests.get(page_link)
    html_tree = etree.HTML(r.text)
    parsed_relative_links = get_list_of_appartmens(html_tree)
    absolute_links = ["https://www.real-estate.lviv.ua" + link for link in parsed_relative_links]
    parsed_list = []
    for appar_link in absolute_links:
        try:
            parsed_list.append(get_appartment_data(appar_link))
        except:
            print("error was here", appar_link)
    return parsed_list  


from tqdm import tqdm
import psycopg2
import configparser

def main():
    config = configparser.ConfigParser()
    config.read("parser_config")
    password = config['findhouse4.me']['password']
    user = config['findhouse4.me']['user']
    dbname = config['findhouse4.me']['dbname']
    connect_str = "dbname='{}' user='{}' host='localhost' password='{}'".format(dbname, user, password)
    conn = psycopg2.connect(connect_str)
    c = conn.cursor()

    c.execute("DROP TABLE IF EXISTS appartments_new")
    c.execute("""CREATE TABLE appartments_new (appart_id integer PRIMARY KEY NOT NULL, appart_link text, 
                                               coordinates text, price int, days_on_site int)""")

    for i in tqdm(range(0, len(all_pages_links))):
        page_link = all_pages_links[i]
        data = get_apparments_data_from_page(page_link)
        for appartment in data:
            c.execute("""
                        INSERT INTO appartments_new VALUES ({appart_id}, '{appart_link}', '{coordinates}', {price}, {days_on_site})
                        ON CONFLICT (appart_id) DO UPDATE 
                            SET coordinates = excluded.coordinates, 
                                price = excluded.price,
                                days_on_site = excluded.days_on_site;
                      """.format(**appartment))
            conn.commit()
    
    c.execute("ALTER TABLE appartments RENAME TO appartments_old")
    c.execute("ALTER TABLE appartments_new RENAME TO appartments")
    conn.commit()
    c.execute("DROP TABLE IF EXISTS appartments_old")
    conn.commit()
    conn.close()


if __name__ == "__main__":
    main()

  




