/**
 * Utilities package:
 * Module to carry out miscellaneous tasks to facilitate software
 *	development.
 *
 * File_IO class:
 * Class to handle input and output (I/O) file streams and their
 *	operations; i.e., file I/O manager.
 * Call the function "set_up_file_io()" before any other functions.
 *
 * IMPORTANT NOTES:
 * Input and output file streams cannot be placed in containers, since
 *	they cannot be assigned, copied, nor instantiated.
 * Hence, I shall provide a list of I/O functions for each file stream,
 *	and use a switch statement to call the appropriate file stream
 *	for file I/O operations.
 * Therefore, this File_IO class can no longer be generic for all my
 *	software projects. It shall be project dependent.
 * For file streams with input and output operations, they shall be
 *	opened separately due to the requirement for specifying input and
 *	output operations.
 * However, when it comes to closing file streams or performing read
 *	and write operations on file streams, they can be classified
 *	under input or output streams. This will reduce the number of
 *	functions that need to be implemented.
 * That is, I shall define and implement functions either for file
 *	input or output operations, but not for both.
 *
 *
 *
 *
 * How to use the File_IO class?
 *	set up file I/O.
 *	if file I/O operations (other than those for logging) are needed,
 *		set the filenames for file I/O.
 *		get file extensions for each filename.
 *		check file extensions for each filename.
 *	if filenames for logging need to be changed,
 *		customize those filenames.
 *	open I/O filestreams.
 *
 *	find corresponding file stream for valid file extension:
 *		check if the file extension is valid.
 *		
 *	...
 *
 *	to enter/exit logging mode.
 *	to determine if logging mode is enabled.
 *	to print (normal) text and error messages to log files.
 *
 *	generate output files -- do this at the end of the program.
 *	close I/O filestreams -- do this at the end of the program.
 *
 *
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


// Import packages from the software
#include "printer.h"
#include "violated_assertion.h"
#include "violated_precondition.h"
#include "violated_postcondition.h"

// Import packages from the C++ STL
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <map>
#include <utility>
#include <limits.h>			// For std::LONG_MIN

#ifndef __FILE_IO_H
#define __FILE_IO_H
using namespace std;

// =========================================================

// Shortcut to container of strings.
typedef vector<string> str_vec;
// Shortcut to represent a pointer to the container of strings.
typedef vector<string>::iterator str_vec_p;

// =========================================================

// Class definition of the File_IO class
class file_io {
	// Publicly accessible data members, constructors, and functions
	public:
		// Default constructor
		file_io();

		// -----------------------------------------------------
		
		// Define headers for functions...
	
		// Accessor functions.
		
		// Get the container of input filenames.
		static str_vec get_input_filenames();
		// Get the container of output filenames.
		static str_vec get_output_filenames();
		// Get the container of input/output filenames.
		static str_vec get_ip_op_filenames();
	
		// Generate the input filenames.
		static str_vec generate_ip_filenames();
		// Generate the output filenames.
		static str_vec generate_op_filenames();
		// Generate the input/output filenames.
		static str_vec generate_io_filenames();
	
		/**
		 * Function to get the filename of the standard output
		 *	log file.
		 */
		static string get_std_log_filename();
		/**
		 * Function to get the filename of the error output
		 *	log file.
		 */
		static string get_err_log_filename();
	
		// Function to determine the file extension of a filename.
		static string get_file_extn(const string &filename);
		
		// Function to determine if mode is logging or otherwise.
		static bool is_logging_mode();
	
		// Function to check if the location of benchmarks is valid.
		static bool is_bmk_loc_valid(const string &bmk_loc);
		// Function to check if the benchmark is valid.
		static bool is_bmk_valid(const string &bmk);
		// Function to obtain the location of the benchmarks.
		static string get_bmk_loc();
		// Function to obtain the name of the benchmark.
		static string get_name_of_bmk();
	
		// Function to determine if this character is a delimiter.
		static bool is_delimiter(const char &c);
		// Function get the delimiters.
		static string get_delimiters();

		// Function to obtain the "get" pointer of input file stream.
		static long find_get_pointer_position(const string &ip_fextn);
	
		// Function to get put pointer of output file stream.
		static long get_put_pointer_position(const string &op_fextn);
	
		// Function to determine if i/p file stream has reach EOF.
		static bool ip_fstream_at_eof(const string &ip_fextn);
	
		// Function to determine if file stream is open.
		static bool fstream_is_open(const string &fextn);
	
		// -----------------------------------------------------

		// Mutator functions.
		
		// Function to enter/exit logging mode
		static void set_logging_mode(const bool &logging_mode);
		/**
		 * Function to set the filenames of the standard and error
		 * output log files.
		 */
		static void set_log_filenames(const string &op_log_filename,
			const string &err_log_filename);

		// Function to set the input and output filenames.
		static void set_io_filenames(str_vec ip_str_vec, str_vec op_str_vec, str_vec io_str_vec);
	
		// Function to set the location of the benchmarks.
		static void set_bmk_loc(const string &bmk_loc);
		// Function to set the name of the benchmark.
		static void set_name_of_bmk(const string &nm_bmk);
	
		// Function to set the delimiters.
		static void set_delimiters(const string &delim);
	
		// -----------------------------------------------------
	
		// Input and Output functions
	
		/**
		 * Function to write message to an output dump file via
		 *	its standard output file stream.
		 * It shall print messages that are directed from
		 *	standard output.
		 */
		static void fileIO_std_op(const string &op_message);
		/**
		 * Function to write error message to an output dump file
		 *	via its standard error file stream.
		 * It shall print messages that are directed from
		 *	standard output.
		 */
		static void fileIO_std_err(const string &err_message);
	
		// Function to generate the output files.
		static void dump_output();
	
		// Function to read from an input file stream.
		static void read_fr_an_input_file_stream(const string &ip_fextn, string & ip_str);
	
		// Function to restart input file processing.
		static void restart_ip_file_proc(const string &ip_fextn);
	
		// Function to write to an output file stream.
		static void write_to_an_output_file_stream(const string &op_fextn, string & op_msg);
	
		// -----------------------------------------------------
	
		// Other functions.
	
		// Function to open the input and output filestreams.
		static void open_io_streams();
	
		// Function to close the input and output filestreams.
		static void close_io_streams();
	
		// Function to set up the file I/O operations.
		static void set_up_file_io();
		
		// Function to tokenize the string
		static str_vec str_tokenizer(string orig_str);
	
		// Function to check if a file extension is valid.
		static bool chk_file_extn(const string &f_extn);
		// Function to check if an input file extension is valid.
		static bool chk_ip_file_extn(const string &f_extn);
		// Function to check if an output file extension is valid.
		static bool chk_op_file_extn(const string &f_extn);
	
	
	// =========================================================
	
	// Privately accessible data members and functions.
	
	private:
		// Declare (and initialize) constants...
	
		// Types of file formats.
		static const string VERILOG;
		static const string SPEF_IP;
		static const string SDC_IP;
		static const string IP_CELL_LIB;
		static const string TIMING;
		static const string SIZES;
		static const string INT_SIZES;
		static const string INTGR;
		static const string PERIOD;
		static const string SLASH;
		static const string TEXT;
	
		// -----------------------------------------------------
	
		// Declaration of static variables...

		// Flag to indicate that the software is in logging mode
		static bool is_logging;
		
		// Container of input filenames.
		static str_vec input_filenames;
		// Container of output filenames.
		static str_vec output_filenames;
		// Container of input/output filenames.
		static str_vec io_filenames;

		// Input file streams.
		static ifstream verilog_ifs;
		static ifstream spef_ifs;
		static ifstream sdc_ifs;
		static ifstream lib_ifs;

		// Input/Output (I/O) file streams.
		static fstream int_sizes_fs;
		static fstream timing_fs;

		// Output file streams.
		static ofstream sizes_ofs;
		static ofstream std_op_ofs;
		static ofstream err_op_ofs;
		
		// Filename of the standard output log file.
		static string standard_logfile;
		// Filename of the error output log file.
		static string error_logfile;
	
		// String of delimiters.
		static string delimiters;
	
		// Container of input file formats.
		static str_vec ip_file_formats;
		// Container of output file formats.
		static str_vec op_file_formats;
		// Container of I/O file formats.
		static str_vec io_file_formats;
		
	
		// Location of the benchmarks.
		static string location_of_benchmarks;
		// Name of the benchmark.
		static string name_of_benchmark;
	
		// Error message to be printed when exceptions are thrown.
		static string err_msg;
		
		// -------------------------------------------------------
		
		// Define headers for private functions...
		
};
#endif