#!/usr/bin/env python3
import json
import os
import sys
import random
from pathlib import Path

def main(num_objects, output_path):
    """
    :param num_objects: number of json objects to create in the output file
    :param output_path: the path to the output file
    """
    num_objects = int(num_objects)
    with open(output_path, 'w') as outfile:
       outfile.write("[") 
       for index in range(num_objects):
           product = {}
           product['id'] = index
           product['cost'] = random.uniform(0, 100.0)
           product['cost_components'] = []
           num_components = random.randint(0, 100)
           for x in range(num_components):
               product['cost_components'].append(random.uniform(0, 52.5))
           json.dump(product, outfile)
           if (index+1)<num_objects:
               outfile.write(",")
       outfile.write("]") 
    outfile.close()

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 create-json-objects.py #num_objects #output_path")
    else:
        main(*sys.argv[1:])