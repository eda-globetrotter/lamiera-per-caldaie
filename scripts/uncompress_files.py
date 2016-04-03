#!/usr/bin/python

"""
	This Python script is written by Zhiyang Ong to archiving and
		unarchiving (i.e., unpacking archive files), and compressing
		and uncompressing, files in the following data compression
		techniques (and associated file formats):
		- TAR (Tape ARchive), or tar balls.
		- tar balls in Gzip'ed (or gzipped) format; .tar.gz or tgz.
			Or, GZIP Compressed Tar Archive files.
		- bzip2 compressed files.
		- bzip2 tar balls

	Approaches, which I have considered, to do this:
		- Use UNIX commands via "system call"s to archive/unarchive 
			and compress/uncompress files.
		- Use Python functions to archive/unarchive and
			compress/uncompress files.











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
from os import listdir, chdir, makedirs, walk, remove
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
#import subprocess, sys, glob
import subprocess, glob
from sys import argv

"""
	Use the extensible library for WWW access, authentication, and
		other access operations.
	Import function from this library to download a web page or a
		file.
"""
from urllib import urlopen


#	=============================================================

#	Preamble.

#	Names of archived and/or compressed files. 
ispd2013_contest_benchmarks_most = "ispd2013.tgz"
ispd2013_contest_benchmarks_netcard = "netcard.tgz"
ispd2013_contest_benchmarks_final = "ispd2013_final.tar.bz2"

#	Relative paths to directories.
boilerplate_code_dir = "/Applications/apps/others/comune/lamiera-per-caldaie/binaries"
current_working_directory = "."
path_to_benchmark_repository = "../benchmarks/"
ispd_2013_contest = "ispd2013"
path_to_ISPD_2013_contest_benchmark = path_to_benchmark_repository + ispd_2013_contest
benchmark_subdir_in_boilerplate_code_dir = "/Applications/apps/others/comune/lamiera-per-caldaie/benchmarks/extra/"

#	=============================================================

#	Print the header banner for the script.
print "============================================================="
print "==	Uncompress and unarchive selected benchmarks for the"
print "	boilerplate code base."

#	Go to the directory where the benchmarks are located.
chdir(benchmark_subdir_in_boilerplate_code_dir)

#	Check if the archived/compressed files are in the directory.
if not isfile(ispd2013_contest_benchmarks_most):
	print "	==>	The set of most benchmarks for the ISPD 2013 contest"
	print "		isn't available in this directory."
if not isfile(ispd2013_contest_benchmarks_netcard):
	print "	==>	The netcard benchmark for the ISPD 2013 contest is not"
	print "		available in this directory."
if not isfile(ispd2013_contest_benchmarks_final):
	print "	==>	The final set of benchmarks for the ISPD 2013 contest"
	print "		is not available in this directory."

































#	============================================================

print "============================================================="
print "==	Finished uncompress and unarchive selected benchmarks"
print "	for the boilerplate code base."
