#!/usr/bin/python

"""
	This Python script is written by Zhiyang Ong to torture the
		boilerplate code.
	
	It does this by running a set of test cases on the boilerplate.
	
	To ensure that the boilerplate code can also run on the current
		software platform, including the operating system and software
		development libraries (e.g., Boost C++) as well as external
		tools for optimization, verification, validation, and testing.
	That is, test all the miscellaneous test code to try out various
		C++ concepts, C++ libraries, C++ -based tools, and hybrid
		integration of C++ code with code in other computer languages.
	E.g., test the use of integrating C++ and Python using
		Boost Python and SWIG, separately.
	E.g., test the use of using Scala to (partially) automate parser
		generation (or compiler generation).

	Also, as a precautionary measure, ensure that all LaTeX documents
		in the boilerplate code base can be typeset, so that users of
		the boilerplate code base can typeset the documents and view
		the result PDF documents for further information.

	Lastly, it shall remove all temporary files generated in the
		process.










	References:
	[Li2010]	Lihan Li, ``Good way to append to a string,'' Stack Exchange Inc., New York, NY, December 14, 2010. Available online from {\it Stack Exchange Inc.: Stack Overflow: Questions} at: \url{http://stackoverflow.com/questions/4435169/good-way-to-append-to-a-string} and \url{http://stackoverflow.com/q/4435169}; edited by Pratyush Nalam on March 16, 2013; March 16, 2016 was the last accessed date.






	The MIT License (MIT)

	Copyright (c) <2016> <Zhiyang Ong>

	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

	Email address: echo "cukj -wb- 23wU4X5M589 TROJANS cqkH wiuz2y 0f Mw Stanford" | awk '{ sub("23wU4X5M589","F.d_c_b. ") sub("Stanford","d0mA1n"); print $5, $2, $8; for (i=1; i<=1; i++) print "6\b"; print $9, $7, $6 }' | sed y/kqcbuHwM62z/gnotrzadqmC/ | tr 'q' ' ' | tr -d [:cntrl:] | tr -d 'ir' | tr y "\n"		Don't compromise my computing accounts. You have been warned.
"""

#	=============================================================

#	Import packages and functions from the Python Standard Library.
from os import listdir, system, chdir
#from os.path import isfile, join, splitexts
from os.path import isfile, join
import subprocess

#	=============================================================

#	Print the header banner for the script.

print "============================================================="
print "==	Begin torturing the boilerplate code base."




#	Path to the boilerplate code base.
boilerplate_code_dir = "/Applications/apps/others/comune/lamiera-per-caldaie"

"""
#	String appending exercise.

#	This style of printing a set of strings introduces a space character in between strings.
print "boilerplate_code_dir is:::", boilerplate_code_dir, "==="
print "boilerplate_code_dir is###",boilerplate_code_dir,"+++"
#	[Li2010, answer by John Kugelman, December 14, 2010]
temp_str = "boilerplate_code_dir is###"
temp_str += boilerplate_code_dir
temp_str += "+++"
print temp_str
temp_str = []
temp_str.append('boilerplate_code_dir is###')
temp_str.append(boilerplate_code_dir)
temp_str.append('+++')
#		This statement prints a list of tokens instead: print temp_str.
print "".join(temp_str)
"""

temp_str = []
temp_str.append('boilerplate_code_dir is###')
temp_str.append(boilerplate_code_dir)
temp_str.append('+++')
print "".join(temp_str)

#	Path to the boilerplate code base's sandbox.
sandbox_dir = "/Applications/apps/others/comune/lamiera-per-caldaie/src/sandbox"
#	Path to the boilerplate code base's LaTeX report.
boilerplate_LaTeX_report = "/Applications/apps/others/comune/lamiera-per-caldaie/notes/report"
#	Path to the boilerplate code base's LaTeX guidelines.
boilerplate_LaTeX_guidelines = "/Applications/apps/others/comune/lamiera-per-caldaie/notes/guidelines"

#	=============================================================

"""
	Make system calls to test the boilerplate code and the code in
		its sandbox.
"""


#subprocess.call('make')
subprocess.call('pwd')
subprocess.call('date')




















#	============================================================

print "============================================================="
print "==	End of torture."
