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
 *
 *
 *
 *
 * References:
 *	CplusplusCom2015. cplusplus.com, "Reference: C++ Reference," Version 3.1, cplusplus.com, 2015. Available online at: \url{http://www.cplusplus.com/reference/}; November 2, 2015 was the last accessed date.
 *
 *
 *
 *
 */

// Import packages from the software
#include "conversion_alphanumeric.hpp"

// Import packages from the C++ STL
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// ==================================================================

// Define the static variables of the class conversion_alphanumeric.
//bool conversion_alphanumeric::flag = false;

// ==================================================================

// Default constructor.
conversion_alphanumeric::conversion_alphanumeric() {
	string err_msg = "==u	conversion_alphanumeric shouldn't be instantiated!";
	throw new violated_assertion(err_msg);
}


// -----------------------------------------------------

/**
 * Functions to convert numbers to strings.
 *
 * From \cite[C library: cfloat]{CplusplusCom2015}, C++ does not have
 *	fixed-point numbers.
 *
 * Reference:
 *	\cite[C library: cfloat]{CplusplusCom2015}
 *
 *
 *
 * Comments:
 *	For processors without a floating-point unit, fixed-point
 *		computation can be faster and use less memory than
 *		floating-point computation.
 *	While fixed-point computation can be faster and use less memory
 *		than floating-point computation, I would have to implement
 *		fixed-point computation using integers.
 *	My implementation for fixed-point computation may not be that
 *		efficient.
 *	Hence, any theoretical gains of fixed-point computation over
 *		floating-point computation may not be realized in my
 *		implementation.
 *
 *	In C++, I can change the format in which floating-point
 *		numbers are represented.
 *
 *
 *
 *
 *
 *	From \cite[pp. 444-445]{Stephens2006},
 *		Fixed-point numbers (and floating-point) numbers are
 *			approximate representations of real numbers. [pp. 444]
 *		
 *		Floating-point representation/format:
 *			# mantissa (m),
 *			# exponent (e),
 *			# base (b) - constant,
 *			# m^(b)^e. [pp. 444]
 *
 *		Fixed-point representation/format:
 *			# mantissa (m),
 *			# exponent (e) - constant,
 *			# base (b) - constant,
 *			# m^(b)^e. [pp. 444]
 *
 *		When integer representations of fixed-point numbers is
 *			used for arithmetic operations, the performance of
 *			arithmetic computation (especially addition/subtraction)
 *			is better than floating-point computation. [pp. 444]
 *		Comparing fixed-point computation with floating-point
 *			computation, fixed-point computation can only represent
 *			a small range of values. [pp. 444]
 *
 *		To implement the addition/subtraction of fixed-point numbers,
 *			add/subtract the underlying representations.
 *		To implement the multiplication/division of fixed-point
 *			numbers, add/subtract the underlying representations
 *			and shift the mantissa left/right to adjust for the
 *			binary point. [pp. 444]
 *
 *
 *
 *
 *
 *
 */


/**
 * For C++11 (and other C++1y) compliant compilers.
 *
 * The following functions can be used:
 *	string to_string (int val);
 *	string to_string (long val);
 *	string to_string (long long val);
 *	string to_string (unsigned val);
 *	string to_string (unsigned long val);
 *	string to_string (unsigned long long val);
 *	string to_string (float val);
 *	string to_string (double val);
 *	string to_string (long double val);
 *
 * Reference:
 *	\cite[string: to_string]{CplusplusCom2015}
 *	\cite[C library: cfloat]{CplusplusCom2015}
 *
 *
 *
 */


/**
 * Function to convert an int to a string.
 * @param a_num:	An int to be converted to a string.
 * @return string representation of a_num, the integer.
 */
//string conversion_alphanumeric::num_to_str(int a_num) {
string conversion_alphanumeric::int_to_str(int a_num) {
	return to_string(a_num);
}









