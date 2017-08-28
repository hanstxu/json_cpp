# simple_json_cpp

A lightweight JSON library for C++.

## How to Build and Link

**TL;DR**: To build the JSON library and the example source code that uses it,
type ` make`.

### Building the Library

To build the json library, just run the following command

```bash
make libjson
```

and this will create the static library **libjson.a**.

### Link the Library to your Program

To add this static library to your program, just add it to your list of
dependencies when you compile your program. That is, treat the library like
any other .cpp or .h file.

```bash
g++ <options> -o <program-name> <source files> libjson.a
```

## Using the Library

You can include one or both of the following two header files.

```c++
#include "JSONArray.h"
#include "JSONObject.h"
```

There are two main classes, JSONArray and JSONObject. You can add the following
primitive data types to a JSONArray or a JSONObject:

```c++
JSONArray array;
array.add<string>("hello world");
array.add<int>(-2823);
array.add<bool>(true);

JSONObject object;
object.add<string>("");  // null is represented as an empty string
object.add<double>(325.178394);
object.add<bool>(false);
```

To see the string representations of the objects you can either the
**toString** function or insert the instances of the classes into a stream.

```c++
cout << array.toString() << endl;
cout << object << endl;
```

Will output the following

```
[
  "hello world",
  -2823,
  true
]
{
  "1": null,
  "2": 325.178394,
  "3": false
}
```



## Miscellaneous

### Notes

* Functionality is complete. The stuff to be implemented are just programming
interface improvements (i.e. syntax, etc.).
* Currently, all decimals are printed with a precision of 6 decimal places.
* Currently, adding multiple values to the same key in JSONObjects will just
overwrite the previous value.
* Currently, all null values are mapped to empty strings in the class
representations and all empty strings are mapped to null in the string
representation.

### Additional Stuff to To Be Implemented Eventually

* Implementing some of the functions to look like to_string (i.e. function
  overloading with different parameters)
* Adding error checking for bad arguments to functions
(i.e. JSONArray::get<T>(size_t n))
* Implementing exponents in the number data type
* Overloading stream insertion operators
* Changing the compilation of the source code into a shared object library
instead of a static library
* Implementing the [] operator with operator overloading (seems pretty hard to
do and might have to look into C++11) and abstract all different data types
away