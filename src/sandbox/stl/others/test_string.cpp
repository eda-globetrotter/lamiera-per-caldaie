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
 */

// Import Header files from the C++ STL
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

// Import packages from the software
#include "../../classes/string_node.hpp"


using namespace std;

// =======================================================================

// Start of main function...
int main(int argc, char *argv[]) {
	// seg fault - accessing something that isn't there
	// bus error - accessing some thing (data element) that has been freed

	
	
	string a_str = "An EECS Ph.D. degree is required for research positions at Intel";
	string b_str = "Before you become a research fellow, you must be a research scientist at Intel";
	string duplicate_str = "An EECS Ph.D. degree is required for research positions at Intel";
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
	
	copy_str = "A basketball player is tall.";
	cout << "	copy_str is:::" << copy_str << "===" << endl;
	cout << "	a_str is:::" << a_str << "===" << endl;
	
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
		cout << "	= Insertion operation failed for repeated Psalm 23:5b." << endl;
	}else{
		cout << "	= Insertion operation passed for repeated Psalm 23:5b." << endl;
	}
	// Try to insert string_node object with node ID of string_node object #4.
	set_op_flag
		= set_sn.insert(string_node("Se dovessi camminare in una valle oscura","This is a test string."));
	if(set_op_flag.second) {
		cout << "	= Insertion operation failed for repeated node ID (Psalm 23:4a1)." << endl;
	}else{
		cout << "	= Insertion operation passed for repeated node ID (Psalm 23:4a1)." << endl;
	}
	
	
	
	
	
	// End of main function...
	return 0;
}
