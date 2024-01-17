#!/usr/bin/python
# -*- coding:utf-8 -*-

import os
import sys
picdir = os.path.join(os.path.dirname(os.path.dirname(os.path.realpath(__file__))), 'images')
libdir = os.path.join(os.path.dirname(os.path.dirname(os.path.realpath(__file__))), 'lib')
if os.path.exists(libdir):
    sys.path.append(libdir)

#import 
from PIL import ImageDraw
from PIL import ImageFont
from PIL import ImageColor
from PIL import Image
   
from waveshare_epd import waveshare_epd  
from tcp_server import tcp_sver 
import socketserver
import traceback
import threading
import logging
import struct
import signal
import time
import math
import os

from progressbar import *

logging.basicConfig(level=logging.INFO)  

class MyServer(tcp_sver.tcp_sver):
    def handle(self):
        try:
            self.client = self.request
            # get id
            self.Get_ID()
            # unlock if password = 123456
            self.unlock('123456')
            # init epd setting
            epd = waveshare_epd.EPD(4.2)
            # set image size
            self.set_size(epd.width, epd.height)
            # font
            font24 = ImageFont.truetype(os.path.join(picdir, 'Font01.ttc'), 24)
            font18 = ImageFont.truetype(os.path.join(picdir, 'Font01.ttc'), 18)
            font35 = ImageFont.truetype(os.path.join(picdir, 'Font01.ttc'), 35)

            image_files = ['img (1).bmp', 'img (2).bmp', 'img (3).bmp','img (4).bmp', 'img (5).bmp', 'img (6).bmp','img (7).bmp', 'img (8).bmp', 'img (9).bmp','img (10).bmp', 'img (11).bmp', 'img (12).bmp','img (13).bmp', 'img (14).bmp', 'img (15).bmp','img (16).bmp', 'img (17).bmp', 'img (18).bmp','img (19).bmp', 'img (20).bmp', 'img (21).bmp','img (22).bmp', 'img (23).bmp', 'img (24).bmp','img (25).bmp', 'img (26).bmp', 'img (27).bmp','img (28).bmp', 'img (29).bmp', 'img (30).bmp','img (31).bmp', 'img (32).bmp', 'img (33).bmp','img (34).bmp', 'img (35).bmp', 'img (36).bmp','img (37).bmp', 'img (38).bmp', 'img (39).bmp', 'img (40).bmp',]  # Replace with your image filenames

            while True:
                for image_file in image_files:
                    # create new Image and draw the image
                    Himage = Image.open(os.path.join(picdir, image_file))
                    # display
                    self.flush_buffer(epd.getbuffer(Himage))
                    # wait for 30 seconds
                    time.sleep(25)

        except ConnectionResetError:
            self.Wait_write("lose connect.")
        except KeyboardInterrupt:
            self.close()
            os.system("clear")

if __name__ == "__main__":
    picdir = os.path.join(os.path.dirname(os.path.dirname(os.path.realpath(__file__))), 'images')
    ip = tcp_sver.get_host_ip()
    logging.info('{0}'.format(ip))
    socketserver.allow_reuse_address = True
    server = socketserver.ThreadingTCPServer((ip, 6868, ), MyServer)

    try:
        server.serve_forever()
    except KeyboardInterrupt:
        server.shutdown()
        os.system("clear")
