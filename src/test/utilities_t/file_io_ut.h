/**
 * Test/Utilities_t package:
 * Submodule of Test package to test classes in the Utilities package.
 *
 * File_io_ut class:
 * Class that tests the File_IO class.
 * The constructors and functions of the File_IO class shall be tested.
 * 
 * IMPORTANT NOTE:
 * As of Jan 7, 2012 at 1706 hrs, the function [dump_output()] would
 *	not be tested in this test suite since it has yet to be implemented.
 * This function shall be tested upon the completion of the software
 *	at a later date.
 * 
 *
 *
 * Copyright	(C)	<2010-2011>	<Zhiyang Ong>
 * @author Zhiyang Ong
 * @version 1.0.0
 * @since January 1, 2011
 *
 * This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// Import Header files from the other modules of Tiramisu.
#include "../../utilities/file_io.h"
#include "../../utilities/violated_assertion.h"

// Import appropriate header files from the C++ STL
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#ifndef __FILE_IO_UT_H
#define __FILE_IO_UT_H
using namespace std;

// ==================================================================

class file_io_ut {
//	private:
//		string ex_msg;

	// --------------------------------------------------------------
	
	public:
		// Default constructor
		file_io_ut();

		// ----------------------------------------------------------

		// Function to test the constructor and functions of file_io
		static void test_file_io();
	
		/**
		 * Function to test the default constructor of the class
		 * printer.
		 */
		static void test_file_io_constructor();

		/**
		 * Function to test the accessor functions for getting the
		 * filenames of the standard and error output log files.
		 */
		static void test_get_log_filenames();
		
		/**
		 * Function to test the mutator function for assigning the
		 * filenames of the standard and error output log files.
		 */
		static void test_set_log_filenames();
	
		// Function to test the logging mode
		static void test_logging_mode();
	
		// Function to test the file output print functions
		static void test_file_op_print_fn();
	
		/**
		 * Function to test the functions for reading from input
		 *	file streams and writing to output file streams.
		 * It also tests if these file streams can be opened and
		 *	closed.
		 */
		static void test_file_IO_fn();
		
		/**
		 * Function to test the miscellaneous functions for file_io.
		 * This includes functions concerning determining and
		 *	validating file extensions, string tokenization, and
		 *	standard/error file output.
		 * It also tests functions concerning the name and location
		 *	of benchmarks.
		 * In addition, it tests the initialization [set_up_file_io()]
		 *	function of file_io.
		 */
		static void test_misc_fn();
};
#endif