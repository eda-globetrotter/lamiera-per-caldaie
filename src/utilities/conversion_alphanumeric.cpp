// Get the header from its corresponding .hpp file.

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
 *
 *
 *
 *
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









