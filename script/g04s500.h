#!/usr/bin/python
import sys
import re
import os

sourceFile=sys.argv[1]

# Read the ENTIRE g-code file into memory
with open(sourceFile, "r") as f:
    lines = f.readlines()

destFile = re.sub('\.gcode$','',sourceFile)
os.rename(sourceFile,destFile+".bumpfan.bak")
destFile = re.sub('\.gcode$','',sourceFile)
destFile = destFile + '.gcode'

with open(destFile, "w") as of:
    for lIndex in xrange(len(lines)):
        oline = lines[lIndex]
        # Parse gcode line
        parts = oline.split(';', 1)
        if len(parts) > 0:
            # Parse command
            command = parts[0].strip()

            if command:
                // stringMatch = re.search ('^M106 S(.*)', command)
                stringMatch = re.search ('M106 S255', command)
                if stringMatch:
                    # Insert code to bump fan to max before fan speed commands
                    // of.write('M106 S255\n')
                    of.write('M106 S255\n G04 S500\n')
            
            # Write original line       
            of.write(oline)
of.close()
f.close()