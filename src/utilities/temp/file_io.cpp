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
#include "file_io.h"

// Import packages from the C++ STL
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <map>
#include <utility>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <climits>
/*
#include </Applications/apps/sw_dev_tools-not_gnu/boost_1_48_0/boost>
#include </Applications/apps/sw_dev_tools-not_gnu/boost_1_48_0/boost/filesystem/config.hpp>
#include </Applications/apps/sw_dev_tools-not_gnu/boost_1_48_0/boost/filesystem/convenience.hpp>
#include </Applications/apps/sw_dev_tools-not_gnu/boost_1_48_0/boost/filesystem/exception.hpp>
#include </Applications/apps/sw_dev_tools-not_gnu/boost_1_48_0/boost/filesystem/fstream.hpp>
#include </Applications/apps/sw_dev_tools-not_gnu/boost_1_48_0/boost/filesystem/operations.hpp>
#include </Applications/apps/sw_dev_tools-not_gnu/boost_1_48_0/boost/filesystem/path.hpp>
#include </Applications/apps/sw_dev_tools-not_gnu/boost_1_48_0/boost/filesystem.hpp>
*/

using namespace std;

// =========================================================

// Shortcut to container of strings.
typedef vector<string> str_vec;
// Shortcut to represent a pointer to the container of strings.
typedef vector<string>::iterator str_vec_p;

// ==================================================================

// Initialization of (string) constants.
const string file_io::PERIOD = string(".");
const string file_io::SLASH = string("/");
const string file_io::TEXT = string("txt");

// ==================================================================

// Define the static variables of the class file_io.

// Initialize the logging mode to FALSE.
bool file_io::is_logging = false;
// Initialize the containers of input and/or output filenames to NULL.
/*
str_vec file_io::input_filenames;
str_vec file_io::output_filenames;
str_vec file_io::io_filenames;
*/
// Initialize the filenames of the standard output/error filenames.
string file_io::standard_logfile = "normal_output.txt";
string file_io::error_logfile = "error_output.txt";
// Initialize the string of delimiting characters.
string file_io::delimiters = ". \t";
// Define the location of the benchmarks.
string file_io::location_of_benchmarks="../benchmarks";
// Define the name of the benchmark.
string file_io::name_of_benchmark="simple";
ifstream file_io::verilog_ifs;
ifstream file_io::spef_ifs;
ifstream file_io::sdc_ifs;
ifstream file_io::lib_ifs;
fstream file_io::int_sizes_fs;
fstream file_io::timing_fs;
ofstream file_io::sizes_ofs;
ofstream file_io::std_op_ofs;
ofstream file_io::err_op_ofs;

// ==================================================================

// Default constructor.
file_io::file_io() {
	string err_msg = "==u	file_io shouldn't be instantiated!";
	throw new violated_assertion(err_msg);
}

// -----------------------------------------------------

// Accessor functions.

/**
 * Function to get the filename of the standard output
 * log file.
 * @param - None
 * @return - The filename of the standard output log file
 */
string file_io::get_std_log_filename() {
	return standard_logfile;
}



/**
 * Function to get the filename of the error output
 * log file.
 * @param - None
 * @return - The filename of the error output log file
 */
string file_io::get_err_log_filename() {
	return error_logfile;
}




/**
 * Function to obtain the location of the benchmarks.
 * @param - None
 * @return - The location of the benchmark.
 */
string file_io::get_bmk_loc() {
	return location_of_benchmarks;
}




/**
 * Function to obtain the name of the benchmark.
 * @param - None
 * @return - The name of the benchmark.
 */
string file_io::get_name_of_bmk() {
	return name_of_benchmark;
}




/**
 * Function get the delimiters.
 * @param - None
 * @return - The delimiters.
 */
string file_io::get_delimiters() {
	// Are there any delimiters?
	if(0 == delimiters.size()) {
		// No. Set a default list of delimiters.
		delimiters = ". \t\'\"\\<>,/?:;|!@#$%^&*()=+~`";
	}
	
	return delimiters;
}



/**
 * Function to determine if this character is a delimiter.
 * @param c:	Character to be determined if it is a delimiter.
 * @return - boolean TRUE, if this character is a delimiter; else,
 *	return FALSE.
 */
bool file_io::is_delimiter(const char &c) {
	// For each delimiting character, check if character matches that.
	for(int i=0; i<get_delimiters().size(); i++) {
		// Does character matches current delimiter?
		if(c == delimiters[i]) {
			// Yes.
			return true;
		}
	}
	
	// Character is not a delimiter.
	return false;
}








/**
 * Function to check if a file extension is valid.
 * @param f_extn:	File extension to be validated.
 * @return - boolean TRUE, if file extension is valid; else,
 *	return FALSE.
 */
/*
bool file_io::chk_file_extn(const string &f_extn) {
	if(chk_ip_file_extn(f_extn) || chk_op_file_extn(f_extn)) {
		return true;
	}else{
		return false;
	}
}
*/

/**
 * Function to check if an input file extension is valid.
 * @param f_extn:	Input file extension to be validated.
 * @return - boolean TRUE, if input file extension is valid; else,
 *	return FALSE.
 */

bool file_io::chk_ip_file_extn(const string &f_extn) {
	// Are there any valid input and I/O file formats?
	if((0 == ip_file_formats.size())	&&
	   (0 == io_file_formats.size()))	{
		// No.
//cout << "==u	EMpty File ForMaTs"<<endl;;
		return false;
	}
	/**
	 * Enumerate all input file formats to compare their file extensions
	 *	with f_extn.
	 */
	for(str_vec_p iff_p = ip_file_formats.begin(); iff_p < ip_file_formats.end(); iff_p++) {
		/**a
		 * Is the input file extension of currently enumerated string
		 * the same as that of f_extn?
		 */
		if(0 == (*iff_p).compare(f_extn)) {
			// Yes. The file extension is valid.
			return true;
		}
	}
	
	
	/**
	 * Enumerate all I/O file formats to compare their file extensions
	 *	with f_extn.
	 */
	for(str_vec_p ioff_p = io_file_formats.begin(); ioff_p < io_file_formats.end(); ioff_p++) {
		/**
		 * Is the I/O file extension of currently enumerated string
		 * the same as that of f_extn?
		 */
		if(0 == (*ioff_p).compare(f_extn)) {
			// Yes. The file extension is valid.
			return true;
		}
	}
		
	// The input or I/O file extension is invalid.
	return false;
}






/**
 * Function to check if an output file extension is valid.
 * @param f_extn:	Output file extension to be validated.
 * @return - boolean TRUE, if output file extension is valid; else,
 *	return FALSE.
 */
bool file_io::chk_op_file_extn(const string &f_extn) {
	// Are there any valid output or I/O file formats?
	if((0 == op_file_formats.size())	&&
	   (0 == io_file_formats.size()))	{
		// No.
		return false;
	}

	
	/**
	 * Enumerate all output file formats to compare its file extension
	 *	with f_extn.
	 */
	for(str_vec_p off_p = op_file_formats.begin(); off_p < op_file_formats.end(); off_p++) {
		/**
		 * Is the output file extension of currently enumerated string
		 *	the same as that of f_extn?
		 */
		if(0 == (*off_p).compare(f_extn)) {
			// Yes. The file extension is valid.
			return true;
		}
	}
	
	
	
	/**
	 * Enumerate all I/O file formats to compare its file extension
	 *	with f_extn.
	 */
	for(str_vec_p ioff_p = io_file_formats.begin(); ioff_p < io_file_formats.end(); ioff_p++) {
		/**
		 * Is the I/O file extension of currently enumerated string
		 *	the same as that of f_extn?
		 */
		if(0 == (*ioff_p).compare(f_extn)) {
			// Yes. The file extension is valid.
			return true;
		}
	}
	
	
	// The file extension is invalid.
	return false;
}







/**
 * Function to tokenize the string.
 * @param orig_str:	A string to be tokenized.
 * @return - A vector of string tokens.
 */
str_vec file_io::str_tokenizer(string orig_str) {
	// A vector of string tokens.
	str_vec tokens;
	// Current token obtained from the original string.
	string current_token = "";
	// Traverse the length of the string,
	for(int i=0; i<orig_str.length(); i++) {
		// Is this character a delimiting character?
		if(is_delimiter(orig_str[i])) {
			// Yes. Is the current token empty?
			if(!current_token.empty()) {
				// Add this token to the vector of tokens.
//cout<<"current_token is::"<<current_token<<"="<<endl;
				tokens.push_back(current_token);
				current_token = "";
			}
			
		// Is this character alphanumeric, or "-" or "_"?
		}else if(isalnum(orig_str[i]) || ('-' == orig_str[i]) || ('_' == orig_str[i])) {
			// Yes. Append the character to the current token.
			current_token = current_token + orig_str[i];
//cout<<"currently, current_token is::"<<current_token<<"="<<endl;
		}
		// Process the next available token.
	}
	
	// Is the current token empty?
	if(!current_token.empty()) {
		// Add this token to the vector of tokens.
		tokens.push_back(current_token);
	}

	
	return tokens;
}




/**
 * Function to determine the file extension of a filename.
 * @param filename:	The filename of a given file.
 * @return - File extension of this specified filename.
 * @exception violated_precondition: If filename does not contain
 *	at least one token, the violated_precondition will be thrown.
 * @exception violated_postcondition: If tokens_in_fname is empty,
 *	throw the violated_postcondition exception since tokens_in_fname
 *	should contain at least one token.
 * @exception violated_assertion: If the last element of
 *	tokens_in_fname is not a valid file extension, throw the
 *	violated_assertion exception.
 * @exception violated_assertion: If the number of tokens
 *	for a filename with "int.sizes" as the file extension is not 2,
 *	throw the violated_assertion exception.
 */
string file_io::get_file_extn(const string &filename) {
	// Container of tokens in filename.
	str_vec tokens_in_fname;
//cout<<"Check precondition of get_file_extn()::"<<filename<<"=="<<endl;
	/**
	 * Precondition:
	 * Check if filename contains at least one token.
	 * If not, throw the violated_precondition exception.
	 */
	if(filename.empty()) {
		throw new violated_precondition("filename is NULL!!!");
	}else{
		// Tokenize the filename
		tokens_in_fname = str_tokenizer(filename);
//cout<<"tokens_in_fname::"<<tokens_in_fname.size()<<"=="<<endl;
//cout<<"Is file extension valid"<<endl;
		// Check if the file extension is valid.
		if(!chk_file_extn(tokens_in_fname.back())) {
			// No.
			throw new violated_assertion("Invalid file extension!!!");
		}
//cout<<"Determine if there exists 3 tokens in the filename"<<endl;
		// Check if there are three tokens in the filename.
		if(3 == tokens_in_fname.size()) {
			// Yes. Check if the 2nd token is "int".
			if(!tokens_in_fname[1].compare(INTGR)) {
				// Yes. Concatenate the 2nd & 3rd tokens with a period.
				tokens_in_fname[1].append(PERIOD);
				tokens_in_fname[1].append(SIZES);
				// Remove the last token.
				tokens_in_fname.pop_back();
				/**
				 * Assertion:
				 * If tokens_in_fname does not have 2 tokens, throw the
				 *	violated_assertion exception since tokens_in_fname
				 *	should contain 2 tokens (after the removal of the
				 *	last token).
				 */
				if(2 != tokens_in_fname.size()) {
					throw new violated_assertion("filename doesn't have 2 tokens!!!");
				}
			}
			// The file extension is now: "int.sizes".
		}
	}
//cout<<"Check postcondition of get_file_extn()"<<endl;
	/**
	 * Postcondition:
	 * If tokens_in_fname, throw the violated_postcondition exception
	 *	since tokens_in_fname should contains at least one token.
	 */
	if(tokens_in_fname.empty()) {
		throw new violated_postcondition("filename has NO tokens!!!");
	}
	
	// Return the last token of the string container.
	return tokens_in_fname.back();
}




/**
 * Function to determine if mode is logging or otherwise.
 * @param - None.
 * @return - boolean TRUE, if in logging mode; else, return FALSE.
 */
bool file_io::is_logging_mode() {
	if(is_logging) {
		return true;
	}else{
		return false;
	}
}


/**
 * Function to check if the location of benchmarks is valid.
 * @param bmk_loc:	Location of the benchmarks.
 * @return - boolean TRUE, if the location is valid; else, return FALSE.
 */
bool file_io::is_bmk_loc_valid(const string &bmk_loc) {
	// Use POSIX/UNIX-based stat struct to determine if directory exists
	struct stat st;
	if(0 == stat(bmk_loc.c_str(), &st)) {
//		cout << "Directory exists." << endl;
		return true;
	}else{
//		cout << "Directory DOES NOT exists." << endl;
		return false;
	}
}




/**
 * Function to check if the benchmark is valid.
 * @param bmk:	Name of the benchmark to be optimized.
 * @return - boolean TRUE, if benchmark is valid; else, return FALSE.
 */
bool file_io::is_bmk_valid(const string &bmk) {
	// Path to the structured Verilog netlist for this benchmark.
	string temp_bmk = get_bmk_loc();
	temp_bmk.append(SLASH);
	temp_bmk.append(bmk);
	temp_bmk.append(SLASH);
	temp_bmk.append(bmk);
	temp_bmk.append(PERIOD);
	temp_bmk.append(VERILOG);
	// Use POSIX/UNIX-based stat struct to determine if file exists
	struct stat st;
	if(0 == stat(temp_bmk.c_str(), &st)) {
//		cout << "File exists." << endl;
//		cout << temp_bmk << endl;
		return true;
	}else{
//		cout << "File DOES NOT exists." << endl;
//		cout << temp_bmk << endl;
		return false;
	}
}


// -----------------------------------------------------

// Mutator functions.


/**
 * Function to enter/exit logging mode.
 * @param logging_mode:	Indicator for entering the logging mode
 *		(when true); false, otherwise.
 * @return - Nothing.
 *
 *
 * ### IMPORTANT ASSUMPTIONS:
 * If the filenames of the standard and error output log files are
 * empty, they shall be set to default values.
 * Else, if these filenames are empty, output file streams cannot
 * be created for these files. This would prevent logging of the
 * standard and error output messages.
 */
void file_io::set_logging_mode(const bool &logging_mode) {
	// Enter the logging mode
	is_logging = logging_mode;
	
	if(get_std_log_filename().empty()) {
		standard_logfile = "normal_output.txt";
	}
	
	if(get_err_log_filename().empty()) {
		error_logfile = "error_output.txt";
	}
	
	if(is_logging_mode()) {
		cout << "==u	In the logging mode" << endl;
	}else{
		cout << "==u	Not in the logging mode" << endl;
	}
	
	return;
}



/**
 * Function to set the filenames of the standard and error output
 * log files.
 * @param op_log_filename:	The filename of the log file for messages
 *		sent to the standard output stream.
 * @param err_log_filename:	The filename of the log file for messages
 *		sent to the standard error stream.
 * @return - Nothing.
 */
void file_io::set_log_filenames(const string &op_log_filename,
						   const string &err_log_filename) {
	
	// Assign the filenames of the log files
	if(!op_log_filename.empty()) {
		standard_logfile = op_log_filename;
	}
	if(!err_log_filename.empty()) {
		error_logfile = err_log_filename;
	}
}


/**
 * Function to set the input and output filenames.
 * @param ip_str_vec:	Container of filenames of the input type.
 * @param op_str_vec:	Container of filenames of the output type.
 * @param io_str_vec:	Container of filenames of the I/O type.
 * @exception violated_postcondition: If filename does not contain
 *	a valid file extension, the violated_postcondition will be thrown.
 * @return - Nothing.
 */
void file_io::set_io_filenames(str_vec ip_str_vec, str_vec op_str_vec, str_vec io_str_vec) {
	/**
	 * If these containers are not empty, assign them to their
	 *	respective containers for filenames.
	 * Else, ignore them.
	 * Assume that if empty containers of filenames are passed as
	 *	parameters, I would ignore them. And avoid calling their
	 *	corresponding functions.
	 */
	if(!ip_str_vec.empty()) {
		input_filenames = ip_str_vec;
	}
	if(!op_str_vec.empty()) {
		output_filenames = op_str_vec;
	}
	if(!io_str_vec.empty()) {
		io_filenames = io_str_vec;
	}
	
	
	// Check if the file extensions of input filenames are valid.
	for(str_vec_p i=ip_str_vec.begin(); i<ip_str_vec.end(); i++) {
		// Is the file extension of this input filename valid?
		if(!chk_file_extn(get_file_extn(*i))) {
			printer::debug_std_err("Input filename's extension is INVALID!!!");
			throw new violated_postcondition("Correct the input file extension.");
		}
	}
	// Check if the file extensions of output filenames are valid.
	for(str_vec_p j=op_str_vec.begin(); j<op_str_vec.end(); j++) {
		// Is the file extension of this output filename valid?
		if(!chk_file_extn(get_file_extn(*j))) {
			printer::debug_std_err("Output filename's extension is INVALID!!!");
			throw new violated_postcondition("Correct the output file extension.");
		}
	}
	// Check if the file extensions of I/O filenames are valid.
	for(str_vec_p k=io_str_vec.begin(); k<io_str_vec.end(); k++) {
		// Is the file extension of this I/O filename valid?
		if(!chk_file_extn(get_file_extn(*k))) {
cout<<"file extn::"<<get_file_extn(*k)<<"="<<endl;
			printer::debug_std_err("I/O filename's extension is INVALID!!!");
			throw new violated_postcondition("Correct the I/O file extension.");
		}
	}
}






/**
 * Function to set the location of the benchmarks.
 * @param bmk_loc:	New location of the benchmarks.
 * @return - Nothing.
 * @exception violated_precondition: If bmk_loc is not a valid
 *	directory, the violated_precondition will be thrown.
 */
void file_io::set_bmk_loc(const string &bmk_loc) {
	if(is_bmk_loc_valid(bmk_loc)) {
		// Get the index of the last character of bmk_loc.
		string a = bmk_loc;
		int idx_last_char = bmk_loc.size() - 1;
		// Is the last character of the location a slash?
		if(0 == SLASH.compare(string(1,bmk_loc[idx_last_char]))) {
			// Remove the slash.
			a.erase(idx_last_char);
		}
		
		location_of_benchmarks = bmk_loc;
	}else{
		throw new violated_precondition("Invalid benchmark directory.");
	}
}




/**
 * Function to set the name of the benchmark.
 * @param nm_bmk:	New name of the benchmark.
 * @return - Nothing.
 * @exception violated_precondition: If nm_bmk is not a valid
 *	benchmark, the violated_precondition will be thrown.
 */
void file_io::set_name_of_bmk(const string &nm_bmk) {
	if(is_bmk_valid(nm_bmk)) {
		name_of_benchmark = nm_bmk;
	}else{
		throw new violated_precondition("Invalid benchmark.");
	}
}




/**
 * Function to set the delimiters.
 * @param delim:	String of delimiting characters.
 * @return - Nothing.
 */
void file_io::set_delimiters(const string &delim) {
	// If the set of delimiting characters is not empty...
	if(0 != delim.size()) {
		// Make it the set of delimiting characters.
		delimiters = delim;
	}
}



// -----------------------------------------------------

// Output functions

/**
 * Function to print message in standard output while
 * in logging mode
 * @param msg:	Message to be printed to standard output
 * @return - Nothing.
 */
void file_io::fileIO_std_op(const string &op_message) {	
	if(is_logging_mode() && std_op_ofs.is_open()) {
//cout<<"==u			In logging mode and std_ofs is open."<<endl;
		std_op_ofs << op_message << endl;
	}
	
//	return;
}



/**
 * Function to print error message in standard error while
 * in logging mode
 * @param msg:	Error message to be printed to standard error
 * @return - Nothing.
 */
void file_io::fileIO_std_err(const string &err_message) {
	if(is_logging_mode() && err_op_ofs.is_open()) {
//cout<<"==u			In logging mode and err_ofs is open."<<endl;
		err_op_ofs << err_message << endl;
	}

//	return;
}

/**
 * Function to generate the output files.
 * @param - None.
 * @return - Nothing.
 */
void file_io::dump_output() {
	// To be fixed...
}




/**
 * Function to read from an input file stream.
 * @param ip_fextn:	File extension of an input or I/O file, which
 *	next available line would be read from.
 * @param ip_str:	Storage of information read from the next available
 *	line of the input or I/O file.
 * @return - Nothing.
 * @exception violated_precondition: If ip_fextn is not a valid file
 *	extension, the violated_precondition will be thrown.
 * @exception violated_postcondition: If no valid input or I/O file
 *	stream can be found for ip_fextn, the violated_postcondition will
 *	be thrown.
 */
void file_io::read_fr_an_input_file_stream(const string &ip_fextn, string & ip_str) {
	// Is ip_fextn a valid input or I/O file extension?
	if(!chk_ip_file_extn(ip_fextn)) {
		// No.
		throw new violated_precondition("Invalid input file extension!!!");
	}
	
	if((0 == VERILOG.compare(ip_fextn)) && (verilog_ifs.is_open())
		&& (!verilog_ifs.eof()) ) {
		// Read from Verilog netlist.
		getline(verilog_ifs, ip_str);
	}else if((0 == SPEF_IP.compare(ip_fextn)) && (spef_ifs.is_open())
		&& (!spef_ifs.eof()) ) {
		// Read from the SPEF file.
		getline(spef_ifs, ip_str);
//		char temp_cstr[1000];
//		spef_ifs.getline(temp_cstr, 1000);
	}else if((0 == SDC_IP.compare(ip_fextn)) && (sdc_ifs.is_open())
		&& (!sdc_ifs.eof()) ) {
		// Read from the SDC file.
		getline(sdc_ifs, ip_str);
	}else if((0 == IP_CELL_LIB.compare(ip_fextn)) && (lib_ifs.is_open())
		&& (!lib_ifs.eof()) ) {
		// Read from the library file.
		getline(lib_ifs, ip_str);
	}else if((0 == INT_SIZES.compare(ip_fextn)) && (int_sizes_fs.is_open())
		&& (!int_sizes_fs.eof()) ) {
		// Read from the int.sizes file.
		getline(int_sizes_fs, ip_str);
	}else if((0 == TIMING.compare(ip_fextn)) && (timing_fs.is_open())
		&& (!timing_fs.eof()) ) {
		// Read from the timing file.
		getline(timing_fs, ip_str);
	}else{
		throw new violated_postcondition("i/p file extn is INVALID!!!");
	}
}






/**
 * Function to restart input file processing.
 * @param ip_fextn:	File extension of an input or I/O file, which
 *	input file processing shall be restarted from the beginning of
 *	the file.
 * @return - Nothing.
 * @exception violated_precondition: If ip_fextn is not a valid file
 *	extension, the violated_precondition will be thrown.
 * @exception violated_postcondition: If no valid input or I/O file
 *	stream can be found for ip_fextn, the violated_postcondition will
 *	be thrown.
 */
void file_io::restart_ip_file_proc(const string &ip_fextn) {
	// Is ip_fextn a valid input or I/O file extension?
	if(!chk_ip_file_extn(ip_fextn)) {
		// No.
		throw new violated_precondition("InVaLiD InPuT FiLe eXtN!!!");
	}
	
	if((0 == VERILOG.compare(ip_fextn)) && (verilog_ifs.is_open())
	   && (!verilog_ifs.eof()) ) {
		// Reset input file stream for the Verilog file.
		verilog_ifs.seekg(0,ios::beg);
	}else if((0 == SPEF_IP.compare(ip_fextn)) && (spef_ifs.is_open())
			 && (!spef_ifs.eof()) ) {
		// Reset input file stream for the SPEF file.
		spef_ifs.seekg(0,ios::beg);
	}else if((0 == SDC_IP.compare(ip_fextn)) && (sdc_ifs.is_open())
			 && (!sdc_ifs.eof()) ) {
		// Reset input file stream for the SDC file.
		sdc_ifs.seekg(0,ios::beg);
	}else if((0 == IP_CELL_LIB.compare(ip_fextn)) && (lib_ifs.is_open())
			 && (!lib_ifs.eof()) ) {
		// Reset input file stream for the library file.
		lib_ifs.seekg(0,ios::beg);
	}else if((0 == INT_SIZES.compare(ip_fextn)) && (int_sizes_fs.is_open())
			 && (!int_sizes_fs.eof()) ) {
		// Reset input file stream for the int.sizes file.
		int_sizes_fs.seekg(0,ios::beg);
	}else if((0 == TIMING.compare(ip_fextn)) && (timing_fs.is_open())
			 && (!timing_fs.eof()) ) {
		// Reset input file stream for the timing file.
		timing_fs.seekg(0,ios::beg);
	}else{
		throw new violated_postcondition("i/p file extn is INVALID!!!");
	}
}









/**
 * Function to write to an output file stream.
 * @param op_fextn:	File extension of an output or I/O file, which a
 *	message would be written to.
 * @param op_msg:	A message to be written to the output or I/O file.
 * @return - Nothing.
 */
void file_io::write_to_an_output_file_stream(const string &op_fextn, string & op_msg) {
	// Is op_fextn a valid output or I/O file extension?
	if(!chk_op_file_extn(op_fextn)) {
		// No.
		throw new violated_precondition("Invalid output file extension!!!");
	}
//cout<<"==u			op_fextn::"<<op_fextn<<"==="<<endl;
//cout<<"==u			get_name_of_bmk()::"<<file_io::get_name_of_bmk()<<"==="<<endl;
/*
if(sizes_ofs.is_open()) {
cout<<"==u			sizes o/p fstream is open::"<<endl;
}
*/	
	if((0 == SIZES.compare(op_fextn)) && (sizes_ofs.is_open())) {
		// Write to the sizes file.
//cout<<"==u			sizes directory"<<endl;
		sizes_ofs << op_msg << endl;
	}else if((0 == INT_SIZES.compare(op_fextn)) && (int_sizes_fs.is_open())) {
//cout<<"==u			int.sizes directory"<<endl;
		// Write to the "int.sizes" file.
		int_sizes_fs << op_msg << endl;
	}else if((0 == TIMING.compare(op_fextn)) && (timing_fs.is_open())) {
//cout<<"==u			timing directory"<<endl;
		// Write to the timing file.
		timing_fs << op_msg << endl;
	}

//cout<<"==u			No more writing."<<endl;
	// Else, do nothing.
}




/**
 * Function to get put pointer of output file stream.
 * @param op_fextn:	File extension of an output or I/O file, which a
 *	integer representing its put pointer position of its output file
 *	stream is demanded.
 * @return - Put pointer position of the output file stream.
 */
long file_io::get_put_pointer_position(const string &op_fextn) {
	// Is op_fextn a valid output or I/O file extension?
	if(!chk_op_file_extn(op_fextn)) {
		// No.
		throw new violated_precondition("Invalid o/p file extn!!!");
	}
	
	// Is the file extn for an open o/p file stream for the sizes file?
	if((0 == SIZES.compare(op_fextn)) && (sizes_ofs.is_open())) {
		// Yes. Return its put pointer.
		return sizes_ofs.tellp();
	// Is the file extn for an open o/p file stream for the 'int.sizes' file?
	}else if((0 == INT_SIZES.compare(op_fextn)) && (int_sizes_fs.is_open())) {
		// Yes. Return its put pointer.
		return int_sizes_fs.tellp();
	// Is the file extn for an open o/p file stream for the timing file?
	}else if((0 == TIMING.compare(op_fextn)) && (timing_fs.is_open())) {
		// Yes . Return its put pointer.
		return timing_fs.tellp();
	}else{
		// File extension should be invalid. Return an invalid value.
		return LONG_MIN;
	}
}




/**
 * Function to obtain the "get" pointer of input file stream.
 * @param ip_fextn:	File extension of an input or I/O file, which a
 *	integer representing its get pointer position of its input file
 *	stream is demanded.
 * @return - Get pointer position of the input file stream.
 */
long file_io::find_get_pointer_position(const string &ip_fextn) {
	// Is ip_fextn a valid input or I/O file extension?
	if(!chk_ip_file_extn(ip_fextn)) {
		// No.
		throw new violated_precondition("Invalid i/p file extn!!!");
	}
	
	// Is the file extn for an open i/p file stream for the Verilog file?
	if((0 == VERILOG.compare(ip_fextn)) && (verilog_ifs.is_open())) {
		// Yes. Return its get pointer.
		return verilog_ifs.tellg();
		// Is the file extn for an open i/p file stream for the SPEF file?
	}else if((0 == SPEF_IP.compare(ip_fextn)) && (spef_ifs.is_open())) {
		// Yes. Return its get pointer.
		return spef_ifs.tellg();
		// Is the file extn for an open i/p file stream for the SDC file?
	}else if((0 == SDC_IP.compare(ip_fextn)) && (sdc_ifs.is_open())) {
		// Yes. Return its get pointer.
		return sdc_ifs.tellg();
		// Is the file extn for an open i/p file stream for the LIB file?
	}else if((0 == IP_CELL_LIB.compare(ip_fextn)) && (lib_ifs.is_open())) {
		// Yes. Return its get pointer.
		return lib_ifs.tellg();
		// Is the file extn for an open i/p file stream for the 'int.sizes' file?
	}else if((0 == INT_SIZES.compare(ip_fextn)) && (int_sizes_fs.is_open())) {
		// Yes. Return its get pointer.
		return int_sizes_fs.tellg();
		// Is the file extn for an open i/p file stream for the timing file?
	}else if((0 == TIMING.compare(ip_fextn)) && (timing_fs.is_open())) {
		// Yes . Return its get pointer.
		return timing_fs.tellg();
	}else{
		// File extension should be invalid. Return an invalid value.
		return LONG_MIN;
	}
}



/**
 * Function to determine if file stream is open.
 * @param ip_fextn:	File extension of an input or I/O file.
 * @return - boolean TRUE, if file stream is open; else, return FALSE.
 * @exception violated_precondition: If fextn is not a valid file
 *	extension, the violated_precondition will be thrown.
 *
 * This function is only for file streams associated with the
 *	benchmark files. It does not check file streams for the logging
 *	files.
 */
bool file_io::fstream_is_open(const string &fextn) {
	// Is fextn a valid file extension?
	if(!chk_file_extn(fextn)) {
		// No.
//cout<<endl<<"==u		fextn is::"<<fextn<<"=="<<endl;
		throw new violated_precondition("Invalid file eXtenSION!!!");
	}
	
	
	// Is the file extn referring to an open Verilog file stream?
	if((0 == VERILOG.compare(fextn)) && (verilog_ifs.is_open())) {
		// Yes.
		return true;
	// Is the file extn referring to an open SPEF file stream?
	}else if((0 == SPEF_IP.compare(fextn)) && (spef_ifs.is_open())) {
		// Yes.
		return true;
	// Is the file extn referring to an open SDC file stream?
	}else if((0 == SDC_IP.compare(fextn)) && (sdc_ifs.is_open())) {
		// Yes.
		return true;
	// Is the file extn referring to an open LIB file stream?
	}else if((0 == IP_CELL_LIB.compare(fextn)) && (lib_ifs.is_open())) {
		// Yes.
		return true;
	// Is the file extn referring to an open int.sizes file stream?
	}else if((0 == INT_SIZES.compare(fextn)) && (int_sizes_fs.is_open())) {
		// Yes.
		return true;
	// Is the file extn referring to an open timing file stream?
	}else if((0 == TIMING.compare(fextn)) && (timing_fs.is_open())) {
		// Yes.
		return true;
	// Is the file extn for an open o/p file stream for the sizes file?
	}else if((0 == SIZES.compare(fextn)) && (sizes_ofs.is_open())) {
		// Yes.
		return true;
	}else{
		return false;
	}	
}



/**
 * Function to determine if i/p file stream has reach EOF.
 * @param ip_fextn:	File extension of an input or I/O file.
 * @return - boolean TRUE, if input file extension has reached EOF;
 *	else, return FALSE.
 * @exception violated_precondition: If ip_fextn is not a valid file
 *	extension, the violated_precondition will be thrown.
 * @exception violated_postcondition: If no valid input or I/O file
 *	stream can be found for ip_fextn, the violated_postcondition will
 *	be thrown.
 */
bool file_io::ip_fstream_at_eof(const string &ip_fextn) {
	// Is ip_fextn a valid input or I/O file extension?
	if(!chk_ip_file_extn(ip_fextn)) {
		// No.
		throw new violated_precondition("Invalid i/p file extn!!!");
	}
	
	// Is the file extn referring to an open Verilog file stream?
	if((0 == VERILOG.compare(ip_fextn)) && (verilog_ifs.is_open())) {
		// Yes. Determine if Verilog file stream has reached EOF.
		return verilog_ifs.eof();
	// Is the file extn referring to an open SPEF file stream?
	}else if((0 == SPEF_IP.compare(ip_fextn)) && (spef_ifs.is_open())) {
		// Yes. Determine if Verilog file stream has reached EOF.
		return spef_ifs.eof();
	// Is the file extn referring to an open SDC file stream?
	}else if((0 == SDC_IP.compare(ip_fextn)) && (sdc_ifs.is_open())) {
		// Yes. Determine if Verilog file stream has reached EOF.
		return sdc_ifs.eof();
	// Is the file extn referring to an open LIB file stream?
	}else if((0 == IP_CELL_LIB.compare(ip_fextn)) && (lib_ifs.is_open())) {
		// Yes. Determine if Verilog file stream has reached EOF.
		return lib_ifs.eof();
	// Is the file extn referring to an open int.sizes file stream?
	}else if((0 == INT_SIZES.compare(ip_fextn)) && (int_sizes_fs.is_open())) {
		// Yes. Determine if Verilog file stream has reached EOF.
		return int_sizes_fs.eof();
	// Is the file extn referring to an open timing file stream?
	}else if((0 == TIMING.compare(ip_fextn)) && (timing_fs.is_open())) {
		// Yes. Determine if Verilog file stream has reached EOF.
		return timing_fs.eof();
	}else{
		throw new violated_postcondition("i/p file extn should be invalid!!!");
	}
}




// -----------------------------------------------------

// Other functions.


/**
 * Function to set up the file I/O operations.
 * @param - None.
 * @return - Nothing.
 */
void file_io::set_up_file_io() {
	/**
	 * Add the list of file extensions to ip_file_formats,
	 *	op_file_formats, or io_file_formats.
	 * Before adding each file extension, check to see if the pair
	 *	exists in the container. If so, don't add it. Else, add
	 *	the pair.
	 */

	// Add Verilog file extension
	if(!chk_ip_file_extn(VERILOG)) {
		ip_file_formats.push_back(VERILOG);
	}
	// Add Standard Parasitic Exchange Format (SPEF) file extension
	if(!chk_ip_file_extn(SPEF_IP)) {
		ip_file_formats.push_back(SPEF_IP);
	}
	// Add Synopsys Design Constraints (SDC) file extension
	if(!chk_ip_file_extn(SDC_IP)) {
		ip_file_formats.push_back(SDC_IP);
	}
	// Add input standard cell library (LIB) file extension
	if(!chk_ip_file_extn(IP_CELL_LIB)) {
		ip_file_formats.push_back(IP_CELL_LIB);
	}
	// Add intermediary timing file extension
	if((!chk_ip_file_extn(TIMING)) && (!chk_op_file_extn(TIMING))) {
		ip_file_formats.push_back(TIMING);
		op_file_formats.push_back(TIMING);
	}
	// Add intermediate sizes file extension
	if((!chk_ip_file_extn(INT_SIZES)) && (!chk_op_file_extn(INT_SIZES))) {
		ip_file_formats.push_back(INT_SIZES);
		op_file_formats.push_back(INT_SIZES);
	}
	// Add output sizes file extension
	if(!chk_op_file_extn(SIZES)) {
		op_file_formats.push_back(SIZES);
	}
	// Add output text file extension
	if(!chk_op_file_extn(TEXT)) {
		op_file_formats.push_back(TEXT);
	}
	
	
	/**
	 * Define the default filenames for the standard output and
	 *	standard error log files.
	 */
	if(!get_std_log_filename().empty()) {
		standard_logfile = "normal_output.txt";
	}
	if(!get_err_log_filename().empty()) {
		error_logfile = "error_output.txt";
	}
}







/**
 * Function to open the input and output filestreams.
 * @param - None.
 * @return - Nothing.
 */
void file_io::open_io_streams() {
	// Are the input and/or output fil streams already open?
	if(verilog_ifs.is_open()
	   && spef_ifs.is_open()
	   && sdc_ifs.is_open()
	   && lib_ifs.is_open()
	   && int_sizes_fs.is_open()
	   && timing_fs.is_open()
	   && sizes_ofs.is_open()
	   && std_op_ofs.is_open()
	   && err_op_ofs.is_open() ) {
		// Yes. Exit the function.
//cout<<"==u			File streams are already opened."<<endl;
		return;
	}else{
		if(verilog_ifs.is_open()) {
			cout << "==u		Verilog is open."<<endl;
		}
		if(spef_ifs.is_open()) {
			cout << "==u		SPEF is open."<<endl;
		}
		if(sdc_ifs.is_open()) {
			cout << "==u		SDC is open."<<endl;
		}
		if(lib_ifs.is_open()) {
			cout << "==u		LIB is open."<<endl;
		}
		if(int_sizes_fs.is_open()) {
			cout << "==u		int.sizes is open."<<endl;
		}
		if(timing_fs.is_open()) {
			cout << "==u		Timing is open."<<endl;
		}
		if(sizes_ofs.is_open()) {
			cout << "==u		Sizes is open."<<endl;
		}
		if(std_op_ofs.is_open()) {
			cout << "==u		Standard output is open."<<endl;
		}
		if(err_op_ofs.is_open()) {
			cout << "==u		Standard error is open."<<endl;
		}
	}

//cout<<"==u			Open the file streams."<<endl;


	
	
	// Path for the benchmark... Get the path for the benchmarks.
	string temp_path=get_bmk_loc();
	
	// Get the filename for the technology/cell library file.
	temp_path.append(SLASH);
	string temp_fname = temp_path;
	temp_fname.append("contest");
	temp_fname.append(PERIOD);
	temp_fname.append(IP_CELL_LIB);
//cout << "==u		Filename of library::"<<temp_fname<<"="<<endl;
	lib_ifs.open(temp_fname.c_str(),ifstream::in);
	
	
	
	// Append the SLASH character to get to its benchmark subdirectory.
	temp_path.append(SLASH);
	// Append the name of the benchmark to get to its subdirectory.
	temp_path.append(get_name_of_bmk());
	// Append the SLASH character to get to the benchmark files.
	temp_path.append(SLASH);
	// Append the name of the benchmark to get to the benchmark files.
	temp_path.append(get_name_of_bmk());
	// Append a period to get to the benchmark files.
	temp_path.append(PERIOD);
	// Filename for corresponding file stream.
	temp_fname=temp_path;
	
	// ----------------------------------------------------
	
	// Open input file streams.
	
	// Get the filename for the structured Verilog netlist.
	temp_fname.append(VERILOG);
	verilog_ifs.open(temp_fname.c_str(),ifstream::in);	
	temp_fname=temp_path;
	// Get the filename for the SPEF file.
	temp_fname.append(SPEF_IP);
	spef_ifs.open(temp_fname.c_str(),ifstream::in);
	temp_fname=temp_path;
	// Get the filename for the SDC file.
	temp_fname.append(SDC_IP);
	sdc_ifs.open(temp_fname.c_str(),ifstream::in);
	temp_fname=temp_path;
	
	// ----------------------------------------------------
	
	// Open output file streams.
	
	// Open output file streams for the log files.
	std_op_ofs.open(get_std_log_filename().c_str(),ofstream::out);
	err_op_ofs.open(get_err_log_filename().c_str(),ofstream::out);
	// Get the filename for the sizes file.
	temp_fname = get_name_of_bmk();
	temp_fname.append(PERIOD);
	temp_fname.append(SIZES);
//cout<<"==u		Filename of sizes::"<<temp_fname<<"=="<<endl;
	sizes_ofs.open(temp_fname.c_str(),ofstream::out);
	temp_fname=temp_path;
	
	// ----------------------------------------------------	
	
	// Open I/O file streams.
	
	// Get the filename for the "int.sizes" file.
	temp_fname = get_name_of_bmk();
	temp_fname.append(PERIOD);
	temp_fname.append(INT_SIZES);
//cout << "==u		Filename of int.sizes::"<<temp_fname<<"="<<endl;
//	int_sizes_fs.open(temp_fname.c_str(), fstream::in | fstream::out);
//	int_sizes_fs.open(temp_fname.c_str());
//	int_sizes_fs.open(temp_fname.c_str(), ios_base::in | ios_base::out);
	int_sizes_fs.open(temp_fname.c_str(), fstream::in | fstream::out | fstream::app);
	
	temp_fname = get_name_of_bmk();
	// Get the filename for the timing file.
	temp_fname.append(PERIOD);
	temp_fname = temp_fname.append(TIMING);
//cout << "==u		Filename of timing::"<<temp_fname<<"="<<endl;
	timing_fs.open(temp_fname.c_str(), fstream::in | fstream::out | fstream::app);
}






/**
 * Function to close the input and output filestreams.
 * @param - None.
 * @return - Nothing.
 */
void file_io::close_io_streams() {
//cout << "==fio		Close input file streams." << endl;
	// For each available input file stream, close it.
	verilog_ifs.close();
	spef_ifs.close();
	sdc_ifs.close();
	lib_ifs.close();

//cout << "==fio		Close output file streams." << endl;
	// For each available output file stream, close it.
	sizes_ofs.close();
/*
	std_op_ofs.close();
	err_op_ofs.close();
*/	
//cout << "==fio		Close I/O file streams." << endl;
	// For each available I/O file stream, close it.
	int_sizes_fs.close();
	timing_fs.close();
}






/**
 * Function to generate the input filenames.
 * @param - None.
 * @return - The container of input filenames.
 */
str_vec file_io::generate_ip_filenames() {
	// Container of generated input filenames
	str_vec gen_ip_fnames;
	
	// Path to the benchmark files.
	string temp_bmk_path = get_bmk_loc();
	// (Temporary) input filename.
	string ip_fname = temp_bmk_path;
	
	ip_fname.append(SLASH);
	ip_fname.append(get_name_of_bmk());
	ip_fname.append(SLASH);
	ip_fname.append(get_name_of_bmk());
	ip_fname.append(PERIOD);
	// Path to different files of the same benchmark.
	temp_bmk_path = ip_fname;
	// Get the filename of the structured Verilog netlist
	ip_fname.append(VERILOG);
	// Add the Verilog filename to the list of input filenames.
	gen_ip_fnames.push_back(ip_fname);
	ip_fname = temp_bmk_path;
	// Get the filename of the SPEF file.
	ip_fname.append(SPEF_IP);
	// Add the SPEF filename to the list of input filenames.
	gen_ip_fnames.push_back(ip_fname);
	ip_fname = temp_bmk_path;
	// Get the filename of the SDC file.
	ip_fname.append(SDC_IP);
	// Add the SDC filename to the list of input filenames.
	gen_ip_fnames.push_back(ip_fname);
	ip_fname = temp_bmk_path;
	// Get the filename of the library file.
	ip_fname.append(IP_CELL_LIB);
	// Add the library filename to the list of input filenames.
	gen_ip_fnames.push_back(ip_fname);
	
	return gen_ip_fnames;
}




/**
 * Function to generate the output filenames.
 * @param - None.
 * @return - The container of output filenames.
 */
str_vec file_io::generate_op_filenames() {
	// Container of generated output filenames
	str_vec gen_op_fnames;
	
	// (Temporary) output filename.
	string op_fname = get_name_of_bmk();
	op_fname.append(PERIOD);
	// Get the filename of the sizes file.
	op_fname.append(SIZES);
	// Add the SIZES filename to the list of output filenames.
	gen_op_fnames.push_back(op_fname);
	
	return gen_op_fnames;
}





/**
 * Function to generate the input/output (I/O) filenames.
 * @param - None.
 * @return - The container of I/O filenames.
 */
str_vec file_io::generate_io_filenames() {
	// Container of generated I/O filenames
	str_vec gen_io_fnames;
	
	// (Temporary) I/O filename.
	string io_fname = get_name_of_bmk();
	io_fname.append(PERIOD);
	string temp_io_fname = io_fname;
	// Get the filename of the "int.sizes" file.
	io_fname.append(INT_SIZES);
	// Add the "int.sizes" filename to the list of I/O filenames.
	gen_io_fnames.push_back(io_fname);
	// Get the filename of the timing file.
	temp_io_fname.append(TIMING);
	// Add the timing filename to the list of I/O filenames.
	gen_io_fnames.push_back(io_fname);
	
	return gen_io_fnames;
}
