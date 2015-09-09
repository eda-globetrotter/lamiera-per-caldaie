# lamiera-per-caldaie


Boilerplate code for my open source software projects. It will include implementations of common data structures and algorithms, including those for electronic design automation (such as AND-Inverter Graphs and Binary Decision Diagrams)



## Currently Implemented Data Structures and Algorithms
- Stack













## Organization of the Repository
- benchmarks: Benchmarks (synthetic) or otherwise
- binaries: Build and run software here.
- docs:
	* Automatically generated API (using *Doxygen*) for software in *HTML*.
- notes:
	* Software license(s).
	* Software documentation for project, written in *LaTeX*.
	* Guidelines for collaborating on open source software and/or hardware projects.
	* *BibTeX* database for the documentation.
- README.md: Readme file to describe the software project, and organization of the repository.
- scripts: Scripts to perform miscellaneous tasks for the software project.
- src: Source code of the software project, including test suites for automated regression testing.







## Building Static Binaries for Boilerplate Code

UNIX command for determining if a binary is statically linked: ldd <binary>. If dynamic libraries show up, the binary/software is not statically linked. 

Produce statically linked binaries to meet requirements of research contests.

Statically linked binaries:
- Advantages:
	* Can optimize library code that is not available via pre-compiled object files.
	* guarantee
- Disadvantages:
	* S

Dynamically linked binaries:
- Advantages:
	* "Reduce total resource consumption" for sharing libraries with multiple processes. The resources include: disk space, RAM, and cache space.
	* Enable bug fixes and library upgrades to propagate without requiring actions from the developers.
- Disadvantages:
	* Risk of suffering in DLL hell (dependency hell for dynamic link libraries).
- Required by plugins.


http://stackoverflow.com/questions/1993390/static-linking-vs-dynamic-linking

http://stackoverflow.com/questions/5563906/compiling-c-into-portable-linux-binaries
http://stackoverflow.com/questions/37398/how-do-i-make-a-fully-statically-linked-exe-with-visual-studio-express-2005
http://www.trilithium.com/johan/2005/06/static-libstdc/
https://en.wikipedia.org/wiki/Static_library
http://tschottdorf.github.io/linking-golang-go-statically-cgo-testing/
http://www.systutorials.com/5217/how-to-statically-link-c-and-c-programs-on-linux-with-gcc/


https://www.google.com/search?sourceid=chrome-psyapi2&ion=1&espv=2&ie=UTF-8&q=c%2B%2B%20statically%20linked%20binary%20compilation&oq=c%2B%2B%20statically%20linked%20binary%20compilation&aqs=chrome..69i57.17967j0j7



















### References:  
Stack Overflow contributors, "Static linking vs dynamic linking," in *Stack Overflow*, Stack Exchange Inc., New York, NY, February 12, 2015. Available from *Stack Exchange: Stack Overflow* at: http://stackoverflow.com/questions/1993390/static-linking-vs-dynamic-linking; last viewed on July 7, 2015.

	References:
	Stack Overflow contributors, "Static linking vs dynamic linking," in *Stack Overflow*, Stack Exchange Inc., New York, NY, February 12, 2015. Available from *Stack Exchange: Stack Overflow* at: http://stackoverflow.com/questions/1993390/static-linking-vs-dynamic-linking; last viewed on July 7, 2015.






References:
http://stackoverflow.com/editing-help
http://daringfireball.net/projects/markdown/syntax
https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet
https://help.github.com/articles/markdown-basics/
https://help.github.com/articles/github-flavored-markdown/
https://help.github.com/articles/writing-on-github/


http://markdown-guide.readthedocs.org/en/latest/basics.html
http://scottboms.com/downloads/documentation/markdown_cheatsheet.pdf




https://github.com/eda-globetrotter/lamiera-per-caldaie

