#! /usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from PIL import Image

im = Image.open(sys.argv[1])
im.thumbnail((80,80))
w, h = im.size

def print2pixels(col1, col2):
    R,G,B=col1
    r,g,b=col2

    return "\033[38;2;%d;%d;%dm" \
           "\033[48;2;%d;%d;%dm▀" % (R,G,B,r,g,b)


ascii_img = ""

for y in range(0,h,2):
    for x in range(w):
        ascii_img += print2pixels(im.getpixel((x, y)),
                                  im.getpixel((x, y + 1)))
    ascii_img += "\n"

print ascii_img

