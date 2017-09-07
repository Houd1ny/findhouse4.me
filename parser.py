#!/usr/bin/env python3

import requests
from bs4 import BeautifulSoup
from lxml import etree
from urllib import parse
import time 
import _pickle as cPickle

def get_list_of_appartmens(html_tree):
    root_search_elem = html_tree.xpath('//*[@id="search_result"]')
    parsed_list = [elem.xpath('.//div/div/div/a/@href') for elem in root_search_elem[0]]
    flat_list = [item for sublist in parsed_list for item in sublist]
    return flat_list

import re
import datetime

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
    m = re.search(r'Оновлено:\s*(\d{2}.\d{2}.\d{4})', appartment_details)
    lastUpdated = m.group(1) if m else "05.09.2017'"
    m = re.search(r'Днів на сайті:\s(\d+)', appartment_details)
    daysOnSite = int(m.group(1)) if m else 0
    return (appart_link, coordinates, lastUpdated, price, daysOnSite)

r = requests.get('https://www.real-estate.lviv.ua/orenda-kvartira/Lviv')
html_tree = etree.HTML(r.text)
count_of_pages = int(html_tree.xpath("//li[@class='last']/a")[0].text)

all_pages_links = ["https://www.real-estate.lviv.ua/orenda-kvartira/Lviv/p_" + str(number) 
                                                for number in range(1, count_of_pages)]

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
import sqlite3

def main():
    conn = sqlite3.connect('appartments.db')
    c = conn.cursor()

    c.execute("DROP TABLE IF EXISTS Appartments")
    c.execute("CREATE TABLE Appartments (link text, coordinates text, lastUpdated text, price int, daysOnSite int)")

    for i in tqdm(range(0, len(all_pages_links))):
        page_link = all_pages_links[i]
        data = get_apparments_data_from_page(page_link)
        for appart in data:
            c.execute("INSERT INTO appartments VALUES ('{}','{}', '{}', {}, {})".
                format(appart[0], appart[1], appart[2], appart[3], appart[4]))
            conn.commit()
    conn.close()


if __name__ == "__main__":
    main()

  




