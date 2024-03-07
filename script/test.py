#!/usr/bin/python
import sys
import re
import os
import sys

sourceFile = sys.argv[1]

# Read the ENTIRE g-code file into memory
with open(sourceFile, "r") as f:
    lines = f.read()

type_expresion = r'(;TYPE:(.*))'
lines = re.sub(type_expresion, r"\1\nM117 Printing: \2", lines)

with open(sourceFile, "w") as of:
    of.write(lines)
    
of.close()
f.close()