#!/usr/bin/python

import httplib, urllib
import os, shutil

def printText(txt):
    lines = txt.split('\n')
    for line in lines:
        print line.strip()


inputs = list()

httpServ = httplib.HTTPConnection("localhost", 8080)
httpServ.connect()

path = '../data/load/'

listing = os.listdir(path)

for file in listing:
    
	filename = os.path.join(path, file)
	
	if (os.path.isfile(filename)):
		
		print filename
		linestring = open(filename, 'r').read()
		params = urllib.urlencode({'data': linestring})
		httpServ.request('POST', '/index', params)
		# inputs.append(linestring)
		
		response = httpServ.getresponse()

		# if response.status == httplib.OK:
		print "Output from POST request"
		printText (response.read())

# print "loaded " + str(len(inputs)) + " files"

httpServ.close()

