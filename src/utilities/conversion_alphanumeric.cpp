/**
 * Utilities package:
 * Module to carry out miscellaneous tasks to facilitate software
 *	development.
 *
 * conversion_alphanumeric class:
 * Class to convert numbers to strings.
 * The C++ STL provides 2 functions to convert strings to numbers.
 * However, the functions for converting numbers to strings are not
 *	provided by the C++ STL (as part of the C++14 standard).
 * Hence, this class provides some functions for converting numbers
 *	to strings.
 * 
 *
 *
 *
 *
 *
 *
 *
 *
 * @author Zhiyang Ong
 * @version 1.0.0
 * @since January 1, 2016
 *
 *
 * The MIT License (MIT)
 *
 * Copyright	(C)	<2010-2016>	<Zhiyang Ong>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * Email address: echo "cukj -wb- 23wU4X5M589 TROJANS cqkH wiuz2y 0f Mw Stanford" | awk '{ sub("23wU4X5M589","F.d_c_b. ") sub("Stanford","d0mA1n"); print $5, $2, $8; for (i=1; i<=1; i++) print "6\b"; print $9, $7, $6 }' | sed y/kqcbuHwM62z/gnotrzadqmC/ | tr 'q' ' ' | tr -d [:cntrl:] | tr -d 'ir' | tr y "\n"		Don't compromise my computing accounts. You have been warned.
 *
 *
 *
 *
 *
 *
 *
 *
 * This Class conversion_alphanumeric allows numbers to be converted
 *	to strings.
 *
 * All the functions in this class are static.
 * This is because I do not want to instantiate any instances of this
 *	class.
 * If I need an instance of this class in another class to convert a
 *	number to a string, I would probably leave a lot of objects
 *	lying around that are not being subjected to any garbage
 *	collection.
 * Hence, to minimize dynamic memory usage, I would prevent the
 *	instantiation of objects of this class.
 */

// Import packages from the software
#include "printer.hpp"

// Import packages from the C++ STL
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// ==================================================================

// Define the static variables of the class conversion_alphanumeric.
bool conversion_alphanumeric::flag = false;

// ==================================================================

// Default constructor.
conversion_alphanumeric::conversion_alphanumeric() {
	string err_msg = "==u	conversion_alphanumeric shouldn't be instantiated!";
	throw new violated_assertion(err_msg);
}


// -----------------------------------------------------

// Functions to convert numbers to strings.

/**
 * Function to determine if mode is debugging or otherwise.
 * @param - None
 * @return - boolean TRUE, if in debugging mode; else, return FALSE.
 */
bool conversion_alphanumeric::num_to_str() {
	if(is_debugging) {
		return true;
	}else{
		return false;
	}
}

