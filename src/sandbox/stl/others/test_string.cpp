/**
 * This is written by Zhiyang Ong to test ideas about null pointers.
 *
 * The MIT License (MIT)
 *
 * Copyright	(C)	<2014>	<Zhiyang Ong>
 *
 * Permission is hereby granted, free of charge, to any person
 *	obtaining a copy of this software and associated documentation
 *	files (the "Software"), to deal in the Software without
 *	restriction, including without limitation the rights to use, copy,
 *	modify, merge, publish, distribute, sublicense, and/or sell copies
 *	of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 *	included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *	WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *	DEALINGS IN THE SOFTWARE.
 * 
 * 
 *
 * @author Zhiyang Ong
 *
 *
 *
 *
 * References:
 *	Kurt McMahon, in {\it Northern Illinois University: College of Engineering and Engineering Technology: Department of Computer Science: CSCI 241 Intermediate Programming in C++ (Fall 2015)}, Northern Illinois University, DeKalb, IL, October 28, 2015.
 */

// Include Header files from the C++ STL
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
// Testing operations with the C++ STL set container.
#include <set>
#include <utility>      // std::pair, std::make_pair
// Test string conversion into integers, via stringstream.
#include <sstream>

// Import packages from the software
#include "../../classes/string_node.hpp"


using namespace std;

// =======================================================================

// Start of main function...
int main(int argc, char *argv[]) {
	// seg fault - accessing something that isn't there
	// bus error - accessing some thing (data element) that has been freed

	
	
	string a_str = "An EECS Ph.D. degree is";
//	string a_str = "An EECS Ph.D. degree is required.";
//	string a_str = "An EECS Ph.D. degree is required for research positions at Intel";
	string b_str = "Before you become a research fellow, you must be a research scientist at Intel";
	string duplicate_str = "An EECS Ph.D. degree is required for research positions at Intel";
	string empty_string_1;
	string empty_string_2 = "";
	/**
	 * From \cite{RebbechiWXYZ}, strings are stored as
	 *	automatically managed dynamic storage.
	 * Test some basic string operations.
	 *
	 * ### IMPORTANT NOTES:
	 * size():	Does not necessarily provide the number of
	 *			characters in the string.
	 *			Indicates size in number of bytes used.
	 *			Synonymous with length().
	 * length(): Does not necessarily provide the number of
	 *			characters in the string.
	 *			Indicates size in number of bytes used.
	 *			Synonymous with size().
	 *
	 * A boolean TRUE is "1" and a boolean false is "0".
	 */
	cout << "==============================================" << endl;
	cout << "	The size of a_str is:::" << a_str.size();
	cout << "===" << endl;
	cout << "	Is a_str empty:::" << a_str.empty() << "===" << endl;
	cout << "	Is empty_string_1 empty:::" << empty_string_1.empty();
	cout << "===" << endl;
	cout << "	Is empty_string_2 empty:::" << empty_string_2.empty();
	cout << "===" << endl;
	cout << "==============================================" << endl;
	a_str = "An EECS Ph.D. degree is required for research positions at Intel";
	string copy_str = a_str;
	string *ptr2str = &a_str;
	
	/**
	 * Using "==" to compare two strings checks if the strings
	 *	point to the same position.
	 * Using strcmp to compare two strings checks if the strings
	 *	have the same content.
	 *
	 * To use strcmp, convert C++ string to C string via ".c_str()".
	 *
	 * Alternatively, use the .compare() function from the C++ STL
	 *	string class to compare two C++ strings.
	 */

	if(0 > a_str.compare(b_str)) {
		cout << "	a_str comes before b_str." << endl;
	}else{
		cout << "	a_str DOES NOT come before b_str." << endl;
	}
	
	if(0 < b_str.compare(duplicate_str)) {
		cout << "	b_str comes after duplicate_str." << endl;
	}else{
		cout << "	b_str DOES NOT come after duplicate_str." << endl;
	}
	
	if(0 == a_str.compare(duplicate_str)) {
		cout << "	a_str is equal to duplicate_str." << endl;
	}else{
		cout << "	a_str IS NOT equal to duplicate_str." << endl;
	}
	
	/**
	 * Changing a copy of a string does not affect the original
	 *	string.
	 */
	copy_str = "A basketball player is tall.";
	cout << "	copy_str is:::" << copy_str << "===" << endl;
	cout << "	a_str is:::" << a_str << "===" << endl;
	/**
	 * When you change the contents of the location that a
	 *	pointer is pointing to, you change the contents of
	 *	the original string.
	 * The contents of the pointer is assigned to the
	 *	address/location of a static/instance variable.
	 */
	(*ptr2str) = "I love the NBA.";
	cout << "	*ptr2str is:::" << (*ptr2str) << "===" << endl;
	cout << "	a_str is:::" << a_str << "===" << endl;
	
	// Declaring multiple variables at once. OK.
	string_node node_a, node_b, node_c;
	
	/**
	 * Does not work.
	 * node_d is of the type/class "string_node", and cannot
	 *	be cast into a "string".
	 */
	//string_node node_d = string("Ciao", "Mondo");
	//string_node node_d = string("Ciao".c_str(), "Mondo".c_str());
	//string_node node_d = string(a_str.c_str(), b_str.c_str());
	string_node node_d = string_node(a_str, b_str);
	// The following works.
	string_node node_e = string_node("Ciao", "Mondo");
	string_node node_f = string_node(a_str.c_str(), b_str.c_str());
	
	cout << "==============================================" << endl;
	
	/**
	 * Create a set of string_nodes.
	 * This includes adding duplicates to set the insert operation.
	 */
	set<string_node> set_sn;
	// Insert the string_node object #1.
	pair<set<string_node>::iterator, bool> set_op_flag
		= set_sn.insert(string_node("Il Signore è il mio pastore","non manco di nulla"));
	if(set_op_flag.second) {
		cout << "	= Insertion operation passed for Psalm 23:1." << endl;
	}else{
		cout << "	= Insertion operation failed for Psalm 23:1." << endl;
	}
	// Insert the string_node object #2.
	set_op_flag
		= set_sn.insert(string_node("su pascoli erbosi mi fa riposare","ad acque tranquille mi conduce"));
	if(set_op_flag.second) {
		cout << "	= Insertion operation passed for Psalm 23:2." << endl;
	}else{
		cout << "	= Insertion operation failed for Psalm 23:2." << endl;
	}
	// Insert the string_node object #3.
	set_op_flag
		= set_sn.insert(string_node("Mi rinfranca, mi guida per il giusto cammino","per amore del suo nome"));
	if(set_op_flag.second) {
		cout << "	= Insertion operation passed for Psalm 23:3." << endl;
	}else{
		cout << "	= Insertion operation failed for Psalm 23:3." << endl;
	}
	// Insert the string_node object #4.
	set_op_flag
		= set_sn.insert(string_node("Se dovessi camminare in una valle oscura","non temerei alcun male, perché tu sei con me"));
	if(set_op_flag.second) {
		cout << "	= Insertion operation passed for Psalm 23:4a." << endl;
	}else{
		cout << "	= Insertion operation failed for Psalm 23:4a." << endl;
	}
	// Insert the string_node object #5.
	set_op_flag
		= set_sn.insert(string_node("Il tuo bastone e il tuo vincastro","mi danno sicurezza"));
	if(set_op_flag.second) {
		cout << "	= Insertion operation passed for Psalm 23:4b." << endl;
	}else{
		cout << "	= Insertion operation failed for Psalm 23:4b." << endl;
	}
	// Insert the string_node object #6.
	set_op_flag
		= set_sn.insert(string_node("Davanti a me tu prepari una mensa","sotto gli occhi dei miei nemici"));
	if(set_op_flag.second) {
		cout << "	= Insertion operation passed for Psalm 23:5a." << endl;
	}else{
		cout << "	= Insertion operation failed for Psalm 23:5a." << endl;
	}
	// Insert the string_node object #7.
	set_op_flag
		= set_sn.insert(string_node("cospargi di olio il mio capo","Il mio calice trabocca"));
	if(set_op_flag.second) {
		cout << "	= Insertion operation passed for Psalm 23:5b." << endl;
	}else{
		cout << "	= Insertion operation failed for Psalm 23:5b." << endl;
	}
	// Insert the string_node object #8.
	set_op_flag
		= set_sn.insert(string_node("Felicità e grazia mi saranno compagne","tutti i giorni della mia vita"));
	if(set_op_flag.second) {
		cout << "	= Insertion operation passed for Psalm 23:6a." << endl;
	}else{
		cout << "	= Insertion operation failed for Psalm 23:6a." << endl;
	}
	// Insert the string_node object #9.
	set_op_flag
		= set_sn.insert(string_node("e abiterò nella casa del Signore","per lunghissimi anni"));
	if(set_op_flag.second) {
		cout << "	= Insertion operation passed for Psalm 23:6b." << endl;
	}else{
		cout << "	= Insertion operation failed for Psalm 23:6b." << endl;
	}
	// Try to insert duplicate of string_node object #7.
	set_op_flag
		= set_sn.insert(string_node("cospargi di olio il mio capo","Il mio calice trabocca"));
	if(set_op_flag.second) {
		cout << "	= Repeated insertion operation for Psalm 23:5b: Failed." << endl;
	}else{
		cout << "	= Repeated insertion operation for Psalm 23:5b: Passed." << endl;
	}
	// Try to insert string_node object with node ID of string_node object #4.
	set_op_flag
		= set_sn.insert(string_node("Se dovessi camminare in una valle oscura","This is a test string."));
	if(set_op_flag.second) {
		cout << "	= Repeated insertion operation for Psalm 23:4a1: Failed." << endl;
	}else{
		cout << "	= Repeated insertion operation for Psalm 23:4a1: Passed." << endl;
	}
	// Try to insert string_node object with node label of string_node object #2.
	set_op_flag
		= set_sn.insert(string_node("This is another test string.","ad acque tranquille mi conduce."));
	if(set_op_flag.second) {
		cout << "	= Repeated insertion operation for Psalm 23:2b: Passed." << endl;
	}else{
		cout << "	= Repeated insertion operation for Psalm 23:2b: Failed." << endl;
	}

	
	cout << "== Set operations work for nodes that use a string as the node ID." << endl;
	cout << "==============================================" << endl;
	
	// =======================================================
	
	// Test string concatenation + string-to-number conversion.

	/**
	 * Convert integers to strings.
	 *
	 * A class "stringstream" is a string buffer/stream that
	 *	can "avoid dropping characters".
	 *
	 * Include header file for stringstream: #include <sstream>
	 *
	 * The inheritance hierarchy for stringstream is:
	 *	# ios_base
	 *	# ios
	 *	# istream + ostream
	 *	# stringstream + fstream 
	 *
	 */
	stringstream ss;
	int prefix = 12345;
	// Pipe a number into the stringstream.
	ss << prefix;
	// Convert contents of the stringstream into a string.
	string prefix_str = ss.str();
	int suffix = 6789;
	// Append another number into the stringstream.
	ss << suffix;
	string suffix_str = ss.str();
	string concatenator = "+";
//	concatenator = "+%^*";
//	concatenator = "gduyasghfiwehjfnKNKBUYTFUYIHJLM@#$%^&*()";
//	concatenator = "gduyasghfiwehj34758FUYIHJLM@#$%^&*()";
//	concatenator = "79423gduyasghfiwehj34758FUYIHJLM@#$%^&*()";
	concatenator = "79423gduyasghfiwehj34758FUYIHJLM@#$%^&*()423423";
	/**
	 * The function atoi() requires a C-string/C-style (or simply
	 *	C string) string.
	 *
	 * If the string does not begin with a number, it will be
	 *	converted to 0.
	 * If the string begins with a number, followed by at least
	 *	one non-numeric character, that number will be converted
	 *	to an integer. The character(s) following this number
	 *	will be ignored.
	 */
	int concatenator_int = atoi(concatenator.c_str());
	cout << "concatenator_int is:::"<<concatenator_int<<"###"<<endl;
	string node_ID_str =  prefix_str + concatenator + suffix_str;
	cout << "== Node ID is:::" << node_ID_str << "###" << endl;
	/**
	 * Integers cannot be concatenated to strings using the
	 *	plus operator.
	 */
	// Empty the stringstream (or string buffer).
	cout << "	test_ss1===" << ss.str() << "+++" << endl;
	ss.str("");		// Statement to empty the stringstream.
	string test_ss = ss.str();
	cout << "	test_ss2===" << test_ss << "+++" << endl;
	ss << 234234535.43253485;
	cout << "	test_ss3===" << ss.str() << "+++" << endl;
	ss.flush();		// Flush cannot empty the stringstream.
	cout << "	test_ss4===" << ss.str() << "+++" << endl;
	// Pipe 2 numbers into the stringstream.
	ss.str("");		// Statement to empty the stringstream.
	ss << "12345 67.89$ 297.30125 microarchitecture superscalar processor 736 29324";
	char third_char;
	int first_int, sixth_int, seventh_int;
	double second_double, fourth_double;
	string fifth_A_string, fifth_B_string, fifth_C_string;
	ss >> first_int >> second_double >> third_char >> fourth_double;
//	ss >> fifth_A_string >> sixth_int >> seventh_int;
	ss >> fifth_A_string >> fifth_B_string >> fifth_C_string >> sixth_int >> seventh_int;
	/**
	 * The above two statements imply that if I do not match
	 *	the instance/static variables with the tokens in the
	 *	stringstream properly, I would get garbage assigned
	 *	to those instance/static variables.
	 * Note that the first of the two statements above this
	 *	block comment has been commented out.
	 */
	cout << "	first_int===" << first_int << "+++" << endl;
	cout << "	second_double===" << second_double << "+++" << endl;
	cout << "	third_char===" << third_char << "+++" << endl;
	cout << "	fourth_double===" << fourth_double << "+++" << endl;
	cout << "	fifth_A_string===" << fifth_A_string << "+++" << endl;
	cout << "	fifth_B_string===" << fifth_B_string << "+++" << endl;
	cout << "	fifth_C_string===" << fifth_C_string << "+++" << endl;
	cout << "	sixth_int===" << sixth_int << "+++" << endl;
	cout << "	seventh_int===" << seventh_int << "+++" << endl;
	
	cout << "==============================================" << endl;
	/**
	 * Using the stringstream to convert strings to numbers.
	 *
	 * Number storing the conversion output as a number
	 */
	int op_num;
	// A number-based string to be converted into a number.
	string a_num = "732486";
	/**
	 * Create a stringstream with the text in a string.
	 * That is, use the standard constructor of stringstream
	 *	to instantiate an instance of stringstream to store
	 *	an array of characters that are part of a string.
	 */
	stringstream convert_str_to_num(a_num);
	// Did the stringstream pipe its contents to an integer?
	if(!(convert_str_to_num >> op_num)) {
		// No. Assign op_num to a default value of zero.
		op_num = 0;
	}
	/**
	 *	Else, yes.
	 *	The contents of the stringstream is piped to an integer.
	 *
	 *
	 * The function itoa() is not part of the standard C++ STL.
	 * However, it is supported by some compilers.
	 */
	cout << "op_num:::"<<op_num<<"==="<<endl;
	cout << "==============================================" << endl;
	
	/**
	 * Test function that converts numbers into strings.
	 *	# int
	 *	# long
	 *	# long long
	 *	# unsigned
	 *	# unsigned long
	 *	# unsigned long long
	 *	# float
	 *	# double
	 *	# long double
	 *
	 * This to_string() function may be part of C++11 standard,
	 *	and is not supported by compilers not fully compliant
	 *	to the C++11 standard.
	 */
	string a = to_string(19283.7465);
	cout << "#	:::" << a << "+++" << endl;
	a = to_string(918273645);
	cout << "#	:::" << a << "+++" << endl;
	// This works.



	/**
	 * Test other functions to convert strings to numbers.
	 *
	 * Test the strtol() function from the C Standard General
	 *	Utilities Library, <cstdlib> (stdlib.h).
	 */
	char str_arr[] = "123456789";
	char *str_arr_end;
	long int l_i = strtol(str_arr,NULL,10);
	l_i = l_i - 6789;
	cout << "	===" << to_string(l_i) << "+++" << endl;
	unsigned long long int ulli = strtoul(str_arr,NULL,10);
	ulli = ulli - 3000000;
	cout << "	===" << to_string(ulli) << "+++" << endl;
	char str_arr1[] = "9821317.654343253453421";
	double dxx = strtod(str_arr1,NULL);
	cout << "	===" << to_string(dxx) << "+++" << endl;
	int an_int = stoi("657483921",nullptr);
	cout << "	===" << to_string(an_int) << "+++" << endl;
	unsigned long long int an_ulli = stoull("6572348375921",nullptr);
	cout << "	===" << to_string(an_ulli) << "+++" << endl;
	long double a_ld = stold("743208.483752921",nullptr);
	cout << "	===" << to_string(a_ld) << "+++" << endl;
	/**
	 * Alternate solutions to convert numbers into strings
	 *	include "lexical_cast" from Boost C++ Libraries.
	 */
// To be completed.

	cout << "==============================================" << endl;
	cout << "Test string-to-number conversion." << endl;
	string str_start = "7364";
	string str_end;
	int int_start = 92834;
	int int_end;
	stringstream convert_bw_str_int;
	// atoi() requires C++ string to be converted to C string first.
	int_end = atoi(str_start.c_str());
	cout << "	atoi() result:::" << int_end << "===" << endl;
	// Using the stringstream option.
	convert_bw_str_int << str_start;
	if(!(convert_bw_str_int >> int_end)) {
		int_end = 0;
	}
	cout << "	stringstream() result:::" << int_end << "===" << endl;

	cout << "Test number-to-string conversion." << endl;
	// Using the stringstream option.
	convert_bw_str_int << int_start;
	str_end = convert_bw_str_int.str();
	cout << "	stringstream() result:::" << str_end << "===" << endl;
	/**
	 * Use the to_string() function.
	 *
	 * This to_string() function may be part of C++11 standard,
	 *	and is not supported by compilers not fully compliant
	 *	to the C++11 standard.
	 */
	str_end = to_string(int_start);
	cout<<"	to_string():::"<<str_end<<"==="<<endl;
	










	cout << "==============================================" << endl;

	
	/**
	 * Test string concatenation operation.
	 *
	 * Mattia Basaglia, "Cxx-MiscLib," in {\it GitHub: Mattia Basaglia}
	 *	Available online at: \url{http://www.cplusplus.com/forum/articles/9645/};
	 *	last accessed on November 13, 2015.
	 *
	 * Do not proceed.
	 */

	
	
	// End of main function...
	return 0;
}
