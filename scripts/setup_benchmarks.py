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


	Notes:
		The solution from [Damian2010] manually enumerates all files
			and directories in the specified directory. This is slow
			and inefficient compared to the use of functions from
			"The Python Standard Library".


	References:
	[Damian2010]
		Kristian Damian, answer to the question ``How to count the number of files in a directory using Python?,'' Stack Exchange Inc., New York, NY, April 13, 2010. Available online from {\it Stack Exchange Inc.: Stack Overflow: Questions} at: \url{http://stackoverflow.com/a/2632298/1531728}; March 31, 2016 was the last accessed date.
	[Lowis2009]
		Martin v. L{\"{o}}wis, answer to the question ``Count number of files with certain extension in Python,'' Stack Exchange Inc., New York, NY, August 24, 2009. Available online from {\it Stack Exchange Inc.: Stack Overflow: Questions} at: \url{http://stackoverflow.com/a/1320744/1531728}; March 31, 2016 was the last accessed date.
	[Luke2011]
		Luke, answer to the question ``How to count the number of files in a directory using Python?,'' Stack Exchange Inc., New York, NY, November 29, 2011. Available online from {\it Stack Exchange Inc.: Stack Overflow: Questions} at: \url{http://stackoverflow.com/a/8311376/1531728}; March 31, 2016 was the last accessed date.
	[Miranda2015]
		Guillermo Pereira Miranda, answer to the question ``How to count the number of files in a directory using Python?,'' Stack Exchange Inc., New York, NY, July 8, 2015. Available online from {\it Stack Exchange Inc.: Stack Overflow: Questions} at: \url{http://stackoverflow.com/a/31297262/1531728}; edited on July 8, 2015; March 31, 2016 was the last accessed date.
	[okobaka2012]
		okobaka, answer to the question ``How to count the number of files in a directory using Python?,'' Stack Exchange Inc., New York, NY, May 30, 2012. Available online from {\it Stack Exchange Inc.: Stack Overflow: Questions} at: \url{http://stackoverflow.com/a/10812604/1531728}; March 31, 2016 was the last accessed date.



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
from os import listdir, chdir, makedirs, walk
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

#	Preamble.
current_working_directory = "."
path_to_benchmark_repository = "../benchmarks/"
path_to_ISPD_2013_contest_benchmark = "../benchmarks/ispd2013"


#	=============================================================
#	Function definitions

#	None at the moment.


#	=============================================================

#	Print the header banner for the script.

print "============================================================="
print "==	Begin setting up the benchmark repository for the boilerplate code base."

"""
	Firstly, it checks if the benchmark repository exists.
		If not, create a directory for the benchmark repository.
"""
print "	==>	Checks if the benchmark repository exists."
if not isdir(path_to_benchmark_repository):
	print "		>>	Create a directory for the benchmark repository."
	makedirs(path_to_benchmark_repository)
else:
	print "		>>	The benchmark repository exists."



#	--------------------------------------------------------

print "	==>	Checks if the ISPD 2013 contest benchmark directory exists."
if not isdir(path_to_ISPD_2013_contest_benchmark):
	print "		>>	Create a directory for the ISPD 2013 contest benchmarks."
	makedirs(path_to_ISPD_2013_contest_benchmark)
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
#	os.listdir(dir_in)
#	os.getcwd()

"""
#	Methods for counting the number of files.
#	From [Luke2011].
dirpath, dirnames, filenames = walk(path_to_ISPD_2013_contest_benchmark).next()
print "Number of regular files in ISPD benchmark subdirectory [Luke2011]:", len(filenames)
#	From [Miranda2015], which is a modification of [Luke2011].
filenames = next(walk(path_to_ISPD_2013_contest_benchmark))[2]
print "Number of regular files in ISPD benchmark subdirectory [Miranda2015]:", len(filenames)
#	From [okobaka2012], which is a modification of [Luke2011] and [Miranda2015].
print "Number of regular files in ISPD benchmark subdirectory [okobaka2012]:", len(walk(path_to_ISPD_2013_contest_benchmark).next()[2])
"""
#	From 
#	Is there any regular file in the ISPD 2013 contest benchmark directory?
if not 0 < len(walk(path_to_ISPD_2013_contest_benchmark).next()[2]):
	print "		>>	No regular file in the ISPD 2013 contest benchmark directory."
	print "		>>	Download the ISPD 2013 contest benchmarks."








"""
	Thirdly, parse the benchmarks to validate the benchmarks.
	That is, check if the benchmarks are valid. 
"""
print "	==>	Call the check_benchmark feature of the parser."
print "		... Call check_benchmark feature of parser!"







#	============================================================

print "============================================================="
print "==	Finished setting up the benchmark repository for the boilerplate code base."
