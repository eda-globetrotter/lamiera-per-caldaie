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
 * Categories of numbers are:
 *	=>	integers:
 *		>>	signed integers:
 *				> int
 *				> long long int
 *		>>	unsigned integers:
 *				> unsigned int
 *				> unsigned long long int
 *	=>	floating-point numbers:
 *		>>	double
 *		>>	long double
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


// === Signed integers

/**
 * Function to convert a signed integer to a string.
 * @param a_num:	An int to be converted to a string.
 * @return string representation of a_num, the integer.
 */
//string conversion_alphanumeric::num_to_str(int an_int) {
string conversion_alphanumeric::int_to_str(int an_int) {
	return to_string(an_int);
}



/**
 * Function to convert a large signed integer to a string.
 *
 */
string conversion_alphanumeric::int_to_str(long long int an_int) {
	return to_string(an_int);
}



// === Unsigned integers
/**
 * Function to convert an unsigned integer to a string.
 *
 */
string conversion_alphanumeric::int_to_str(unsigned int an_int) {
	return to_string(an_int);
}



/**
 * Function to convert a large unsigned integer to a string.
 * @param
 */
string conversion_alphanumeric::int_to_str(unsigned long long int an_int) {
	return to_string(an_int);
}



// === Floating-point numbers.
/**
 * Function to convert a floating-point number to a string.
 *
 */
string conversion_alphanumeric::double_to_str(double a_fp_num) {
	return to_string(a_fp_num);
}


		
/**
 * Function to convert a large floating-point number to a
 *	string.
 */
string conversion_alphanumeric::long_double_to_str(long double a_fp_num) {
	return to_string(a_fp_num);
}
