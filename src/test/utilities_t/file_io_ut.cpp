/**
 * Test/Utilities_t package:
 * Submodule of Test package to test classes in the Utilities package.
 *
 * file_io_ut class:
 * Class that tests the file_io class.
 * The constructors and functions of the file_io class shall be tested.
 *
 *
 *
 * Copyright	(C)	<2010-2011>	<Zhiyang Ong>
 * @author Zhiyang Ong
 * @version 1.0.0
 * @since January 1, 2011
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// Import Header files from the other modules of lamiera-per-caldaie.
#include "file_io_ut.hpp"

// Import appropriate header files from the C++ STL

// ===========================================================

// Default constructor of the unit test for the class file_io
file_io_ut::file_io_ut() {
	cerr << "==tu	Don't instantiate the tester for file_io";
	cerr << endl;
	string err_msg = "==tu	Don't use file_io's default constructor";
	throw new violated_assertion(err_msg);
}

// ===========================================================

// Function to test the constructor and functions of file_io
void file_io_ut::test_file_io() {
	cout << "==tu	Testing: file_io..." << endl;
	/**
	 * Function to test the default constructor of the class
	 *	file_io.
	 */
	test_file_io_constructor();

	// Function to test the logging mode
	test_logging_mode();
	// Function to test functions to access/modify filenames.
	test_log_filenames();

/*

	// Functions to test the output write functions
	test_file_io_std_op_fn();
	test_file_io_std_err_fn();No

	// Function to test the opening of I/O file streams
	void test_open_io_fs();
	// Function to test the closing of I/O file streams
	void test_close_io_fs();
*/
	cout << endl;
}




/**
 * Function to test the default constructor of the class file_io.
 * @param - None
 * @return - Nothing
 */
void file_io_ut::test_file_io_constructor() {
	// Check if file_io should not be instantiated.
	try {
		printer::num_test_cases_eval();
		cout << "==tu	>>	Testing: default constructor." << endl;
		file_io *my_file_io = new file_io();
	}catch (violated_assertion *va_ex) {
		cout << "==tu	==>	default constructor works." << endl;
		printer::num_passed_test_cases_eval();
	}
}




/**
 * Function to test the logging mode.
 * @param - None.
 * @return - Nothing.
 */
void file_io_ut::test_logging_mode() {
	// Check if the default debugging mode is FALSE.
	cout << "==tu	>>	Is the default debugging mode FALSE?";
	printer::num_test_cases_eval();
	if(!file_io::is_logging_mode()) {
		cout << "		Yes." << endl;
		printer::num_passed_test_cases_eval();
	}else{
		cout << "		NO!!!" << endl;
	}
	// Set the debugging mode to TRUE.
	file_io::set_logging_mode(true);
		// Check if the debugging mode is now set to TRUE.
	cout << "==tu	>>	Is program in debugging mode?";
	printer::num_test_cases_eval();
	if(file_io::is_logging_mode()) {
		cout << "			Yes." << endl;
		printer::num_passed_test_cases_eval();
	}else{
		cout << "			NO!!!" << endl;
	}

	// Check if the logging mode is TRUE.
	if(file_io::is_logging_mode()) {
		// Yes. Set it to FALSE.
		file_io::set_logging_mode(false);
	}
	// Logging mode is FALSE.
	cout << "==tu	>>	Can logging mode be set to FALSE?";
	printer::num_test_cases_eval();
	if(!file_io::is_logging_mode()) {
		cout << "		Yes." << endl;
		printer::num_passed_test_cases_eval();
	}else{
		cout << "	NO!!!" << endl;
	}
	// Set the debugging mode to TRUE again.
	file_io::set_logging_mode(true);
}




/**
 * Function to test functions to get/set filenames for
 *	log files.
 */
void file_io_ut::test_log_filenames() {
	// Check if default filename for standard output is empty.
	cout << "==tu	>>	Default filename for std o/p isn't empty?";
	printer::num_test_cases_eval();
	if(!file_io::get_std_log_filename().empty()) {
		cout << "	Yes." << endl;
		printer::num_passed_test_cases_eval();
	}else{
		cout << "		NO!!!" << endl;
	}
	// Check if default filename for standard error is empty.
	cout << "==tu	>>	Default filename for std err isn't empty?";
	printer::num_test_cases_eval();
	if(!file_io::get_err_log_filename().empty()) {
		cout << "	Yes." << endl;
		printer::num_passed_test_cases_eval();
	}else{
		cout << "		NO!!!" << endl;
	}
	string temp_std_op_fname = file_io::get_std_log_filename();
	string temp_std_err_fname = file_io::get_err_log_filename();
	// Set up the default filenames for standard output/error.
	file_io::set_up_file_io();

}
