/**
 * Test/Utilities_t package:
 * Submodule of Test package to test classes in the Utilities package.
 *
 * violated_precondition_ut class:
 * Class that tests the violated_precondition class.
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
#include "violated_precondition_ut.h"
#include "../../utilities/printer.h"

// Import appropriate header files from the C++ STL
#include <iostream>
#include <string>
using namespace std;

violated_precondition_ut::violated_precondition_ut() {
	cerr << "==tu	Don't instantiate the tester for violated_precondition";
	cerr << endl;
}


void violated_precondition_ut::test_violated_precondition() {
	try{
		printer::num_test_cases_eval();
		cout << "==tu	Testing: violated_precondition..." << endl;
		throw new violated_precondition("==tu	>>	Testing: violated_precondition");
	}catch(violated_precondition *err) {
		cout << "==tu	==>	violated_precondition works." << endl;
		printer::num_passed_test_cases_eval();
		cout << endl << endl;
	}
}