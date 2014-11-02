/**
 * Test/Utilities_t package:
 * Submodule of Test package to test classes in the Utilities package.
 *
 * violated_assertion_ut class:
 * Class that tests the violated_assertion class.
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

// Import Header files from the other modules of Tiramisu.
#include "violated_assertion_ut.h"
#include "../../utilities/printer.h"

// Import appropriate header files from the C++ STL
#include <iostream>
#include <string>
using namespace std;

violated_assertion_ut::violated_assertion_ut() {
	cerr << "==tu	Don't instantiate the tester for violated_assertion";
	cerr << endl;
}


void violated_assertion_ut::test_violated_assertion() {
	try{
		printer::num_test_cases_eval();
		cout << "==tu	Testing: violated_assertion..." << endl;
		throw new violated_assertion("==tu	>>	Testing: violated_assertion");
	}catch(violated_assertion *err) {
		cout << "==tu	==>	violated_assertion works." << endl;
		cout << endl << endl;
		printer::num_passed_test_cases_eval();
	}
}