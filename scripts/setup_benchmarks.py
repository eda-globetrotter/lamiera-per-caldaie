#!/usr/bin/python

"""
	This Python script is written by Zhiyang Ong to set up the
		benchmark repository.
	
	Firstly, it checks if the benchmark repository exists.
		If not, create a directory for the benchmark repository.

	Secondly, it checks if the set of benchmarks are there.
	If not, download the set of benchmarks to the benchmark
		repository.

	Thirdly, parse the benchmarks to validate the benchmarks.
	That is, check if the benchmarks are valid. 







	References:
	???






	The MIT License (MIT)

	Copyright (c) <2016> <Zhiyang Ong>

	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

	Email address: echo "cukj -wb- 23wU4X5M589 TROJANS cqkH wiuz2y 0f Mw Stanford" | awk '{ sub("23wU4X5M589","F.d_c_b. ") sub("Stanford","d0mA1n"); print $5, $2, $8; for (i=1; i<=1; i++) print "6\b"; print $9, $7, $6 }' | sed y/kqcbuHwM62z/gnotrzadqmC/ | tr 'q' ' ' | tr -d [:cntrl:] | tr -d 'ir' | tr y "\n"		Don't compromise my computing accounts. You have been warned.
"""





#	=============================================================

#	Import packages and functions from the Python Standard Library.

#	To access contents of a directory or switch directories.
#from os import listdir, system, chdir
from os import listdir, chdir
"""
	To perform operations related to absolute/relative paths,
		directory names, and file types.
"""
#from os.path import isfile, join, splitexts
from os.path import dirname, abspath, isfile, join, isdir
"""
	To perform system calls and process input arguments to this
		script ; see the "library reference manual" for more details
		\cite[The Python Standard Library - Python 2.7.11 Documentation: 28.1. sys - System-specific parameters and functions]{DrakeJr2014}.
	"argv" is a container/list of input arguments that are provided
		to this script when executed at the command line.
"""
import subprocess, sys
from sys import argv


#	=============================================================

#	Print the header banner for the script.

print "============================================================="
print "==	Begin setting up the benchmark repository for the boilerplate code base."

"""
	Firstly, it checks if the benchmark repository exists.
		If not, create a directory for the benchmark repository.
"""
print "	==>	Checks if the benchmark repository exists."
if not isdir("../benchmarks/"):
	print "		>>	Create a directory for the benchmark repository."
else:
	print "		>>	The benchmark repository exists."

#	--------------------------------------------------------

print "	==>	Checks if the ISPD 2013 contest benchmark directory exists."
if not isdir("../benchmarks/ispd2013"):
	print "		>>	Create a directory for the ISPD 2013 contest benchmarks."
else:
	print "		>>	The ISPD 2013 contest benchmark directory exists."





"""
	Secondly, it checks if the complete set of benchmarks for the
		ISPD 2013 contest is there.
	If not, download the set of benchmarks to the benchmark
		repository.
"""
print "	==>	Check if ISPD 2013 contest benchmark directory is complete."
print "		... Checking!"	







"""
	Thirdly, parse the benchmarks to validate the benchmarks.
	That is, check if the benchmarks are valid. 
"""
print "	==>	Call the check_benchmark feature of the parser."
print "		... Call check_benchmark feature of parser!"







#	============================================================

print "============================================================="
print "==	Finished setting up the benchmark repository for the boilerplate code base."
