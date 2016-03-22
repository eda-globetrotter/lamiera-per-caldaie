# To-Do List for Developing my Boilerplate Code Base


- Refactor the Utility package
	+ Update and copy comments in the preamble for the class
		*simple_template*.
		Copy these comments from the header file to the
		implementation file.
	+ Add "const" to all the accessor functions in the classes.
		Add "const" at the end of the function declaration
		(in the header file).
	+ Clean up the class for converting numbers to strings.
	+ Test the performance measurement class to determine which
		method is better for measure the temporal performance of
		the implemented methods.
		That is, try different ways to determine how long does it
		take to implement each function.
		Report which method is the best way of measuring the
		temporal performance of the implemented methods.
	+ Do code inspection of all mutator methods to determine if
		the mutator methods are implemented correctly.
	+ Clean up comments for *make template*.
	+ Keep these
		- make template
	+ Remove these
		- make template1
		- *Other test suites for C++ templates*, and their associated
			classes that are not used by other/useful test suites.



- Test graph module.
- Test parser module.
	+ Use ISPD contest parser.
	+ Implement with:
		- flex++ (part of flex???)/bison (also, try bison++, or bisonc++)
		- Boost parser framework, *Spirit Parser Framework* (Spirit2???)
		- Boost parser framework, *AXE*
		- Ragel???
		- ANTLR3, which supports C++. ANTLR4 doesn't support C++.
		- lex/yacc
		- Quex???
		- lexertl???
		- APG???
		- Dragon??? GPL-based.
		- PEGTL???
		- Some other parser generator
		- Ignore *Java*-based parser generator, such as ???ant???
		- LLVM??? No.
- Do initial testing with stub classes.

- Refactor other packages.
	+ Add "const" to all the accessor functions in the classes.












- Develop STA and SSTA code in the boilerplate code base.
- Fork the code base for the STA and SSTA into separate repositories.
	+ The code base for the STA and SSTA timers should be dependent
		on the boilerplate code base.
- Finish the robust linear programming test cases.
	- Finish the testing linear programming engine.



- Implement gate sizing, threshold voltage assignment, and
	adaptivitiy assignment engine.



- **Whenver I commit code, I should do automated regression testing.**
- Use *make test* for automated regression testing.
- Use *make torture* for automated regression testing of the EDA tool,
	the boilerplate code that the EDA tool uses, and the "micro" test
	suites in the *sandbox*.



