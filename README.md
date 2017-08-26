# simple_json_cpp

A lightweight JSON library for C++.

### Notes

* Functionality is complete. The stuff to be implemented are just programming
interface improvements (i.e. syntax, etc.).
* Currently, all decimals are printed with a precision of 6 decimal places.
* Currently, add multiple values to the same key in JSONObjects will just
overwrite the previous value.

### Additional Stuff to To Be Implemented Eventually

* Build all essentials into a static or dynamic library? (TBD)
* Implementing some of the functions to look like to_string (i.e. function
  overloading with different parameters)
* Adding error checking for bad arguments to functions
(i.e. JSONArray::get<T>(size_t n))
* Implementing exponents in the number data type
* Overloading stream insertion operators
* Implementing the [] operator with operator overloading (seems pretty hard to
do and might have to look into C++11) and abstract all different data types
away