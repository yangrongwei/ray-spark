Introduction of Spark -- C++ plugin wrapper for GCC (focus on GENERIC)

Project **spark** is a student project for studying gcc plugin. The purpose of **spark** is trying to put a thin C++ class/object wrapper for gcc GENERIC intermediate representation. If it works, it will be very natural for contemporary programmers to manipulate GENERIC **tree** class/object hierarchy in C++, not the strange gcc object-in-C way, which is macro call. 

The working version is based-on GCC 4.6.1. Future version will be switched to GCC 4.7 when it (spark or gcc) is stable. The project is initialized in early March 2012. Since it is a student project, there is no clear plan for its path. Roughly, we should have a working release with demo/test code in May 2012. The code name _spark_ is chosen because I like the word. 

The license of **spark** (code/documents) is _GNU General Public License, version 3_ and _GNU Free Documentation License, version 1.3_. I do not understand the license problem, since GCC chooses it, I choose it, too.

Current working focus is wrapping GENERIC, and sample/test code for demoing/checking the use. The applicability for wrapping GIMPLE intermediate representation will be studied later when the GENERIC wrapper is finished. There is no plan for wrapping RTL intermediate representation.

The major inspired/referencing projects are:
* [GCC Python Plugin](https://fedorahosted.org/gcc-python-plugin/) Python plugin wrapper for GCC.
* [ODB](http://www.codesynthesis.com/products/odb/) object-relational mapping (ORM) system for C++. 
* [Dehydra](https://developer.mozilla.org/en/Dehydra) JavaScripts plugin wrapper for GCC.

All these plugins can be found in [GCC plugin wiki](http://gcc.gnu.org/wiki/plugins). Hope this project can be listed in the page someday when it is stable and has a reasonable users.

For others who has the wrapping interest in his/her favorite programming language, I suggest to study **GCC Python Plugin** first, it is self-contained and has many useful example/test code as well as valuable supplemental document for GCC plugin spread in its code comments. **ODB** is noticed because its author have written a nice _GCC pulgin How to_ series in his/her blog, **Parsing C++ with GCC plugins** [Part 1](http://www.codesynthesis.com/~boris/blog/2010/05/03/parsing-cxx-with-gcc-plugin-part-1/) [Part 2](http://www.codesynthesis.com/~boris/blog/2010/05/10/parsing-cxx-with-gcc-plugin-part-2/) [Part 3](http://www.codesynthesis.com/~boris/blog/2010/05/17/parsing-cxx-with-gcc-plugin-part-3/). NOTICE, the sample code listed in _Part 1_ cannot be compiled in GCC 4.6.1 because the header path is changed, I remember I found this reason in _GCC Python Plugin_ code comments. **Dehydra** is just a cross-reference for me. I do not enjoy the project, both for its stange name, I cannot pronounce it and it is hard to remember, and for its stange JavaScript purpose, furthermore, I felt it is not self-contained. Other plugins can be found in _GCC plugin wiki_, they are not checked because I flet they are too large for me in this student project.

Beside code, **spark** may work out some documents/notes to introduce _How to_ write gcc plugin. Since my native language is Chinese, these documents/notes most probably are Chinese (Simplified).
