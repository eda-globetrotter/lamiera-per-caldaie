#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <math.h>
#include <climits>
#include <cfloat>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

//#include "../../elements/trivial_template.hpp"
//#include "../../elements/merged_template.hpp"
#include "../../elements/double_template.cpp"

using namespace std;

int main(int argc, char *argv[]) {
	cout << "	###" << merged_template<int>::is_non_negative(493) << "===" << endl;
	merged_template<int> *a_ptr;
	cout << "	###" << a_ptr->square_given_number(5) << "===" << endl;
	// 0.25^2 = 0.0625
	merged_template<long double> *b_ptr;
	cout << "	###" << b_ptr->square_given_number(-0.25) << "===" << endl;
	// 16.25^2 = 164.0625
	cout << "	###" << b_ptr->square_given_number(-16.25) << "===" << endl;
	return 0;
}
