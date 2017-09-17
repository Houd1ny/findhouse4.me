#!/usr/bin/env python3
import schedule
import time

import parser

schedule.every().day.at("02:00").do(parser.main)

while True:
    schedule.run_pending()
    time.sleep(60) # wait one minute