/**
 * Test/Utilities_t package:
 * Submodule of Test package to test classes in the Utilities package.
 *
 * utilities_mt class:
 * Class that tests the utilities class.
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


// Import Header files from the other modules of lamiera-per-caldaie.
#include "utilities_mt.hpp"
//#include "../../utilities/printer.hpp"


// Import appropriate header files from the C++ STL



/**
 * Default constructor.
 *
 * Do NOT allow people to use it.
 */
utilities_mt::utilities_mt() {
	cerr << "==tm	Don't instantiate utilities_mt!";
	cerr << endl;
}




/**
 * Function to test different classes in the Utilities package.
 * @param None
 * @return Nothing
 */
void utilities_mt::test_utilities() {
	// Testing the utilities package
	cout << "--------------------------------------------------------" << endl;
	cout << "		TESTING the Utilities package" << endl << endl << endl;
	// Test the class violated_assertion
	violated_assertion_ut::test_violated_assertion();
	// Test the class violated_precondition
	violated_precondition_ut::test_violated_precondition();
	// Test the class violated_postcondition
	violated_postcondition_ut::test_violated_postcondition();
	// Test the class printer
	printer_ut::test_printer();
	// Test the class file_io
	file_io_ut::test_file_io();
}
