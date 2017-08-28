# simple_json_cpp

A lightweight JSON library for C++.

The most important files are: *JSONInterface.h*, *JSONArray.h*,
*JSONObject.h*, *JSONArray.cpp*, *JSONObject.cpp*.

*Makefile* contains commands to build those files into a linux static library.
*example.cpp* is a sample program that showcases how to use the library.

If you don't use linux or want to use your own IDE, you can just add the five
files at the top to integrate the library.

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

### Headers

You can include one or both of the following two header files.

```c++
#include "JSONArray.h"
#include "JSONObject.h"
```

### Adding Values to the Two Classes

There are two main classes, JSONArray and JSONObject. You can add the following
primitive data types to a JSONArray or a JSONObject:

**Code**
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

### Printing out the JSON

To see the string representations of the objects you can either the
**toString** function or insert the instances of the classes into a stream.

**Code**
```c++
cout << "array:" << endl;
cout << array.toString() << endl << endl;
cout << "object:" << endl;
cout << object << endl << endl;
```

**Output**
```
array:
[
  "hello world",
  -2823,
  true
]

object:
{
  "1": null,
  "2": 325.178394,
  "3": false
}
```

### Recursive Classes

Accordingly, you can add JSONObject and JSONArrays to JSONObjects and JSONArrays.

**Code**
```c++
JSONArray nested_array;
nested_array.add<JSONArray>(JSONArray());
nested_array.add<JSONObject>(JSONObject());
  
cout << "nested_array:" << endl;
cout << nested_array << endl << endl;
  
JSONObject everything;
everything.add<JSONArray>("array", array);
everything.add<JSONObject>("object", object);
everything.add<JSONArray>("nested_array", nested_array);
  
cout << "everything:" << endl;
cout << everything << endl << endl;
```

**Output**
```
nested_array:
[
  [],
  {}
]

everything:
{
  "object": {
    "1": null,
    "2": 325.178394,
    "3": false
  },
  "array": [
    "hello world",
    -2823,
    true
  ],
  "nested_array": [
    [],
    {}
  ]
}
```

### Get and Remove

There are also remove and get functions, where you need to specify the
type. For JSONArrays, the argument that you pass in is the index. For
JSONObjects, the argument that you pass in is the key value.

**Code**
```c++
cout << "get examples:" << endl;
cout << object.get<double>("2") << endl;
cout << array.get<string>(0) << endl;
cout << nested_array.get<JSONArray>(0) << endl << endl;
  
array.remove<int>(0);
array.remove<bool>(0);
  
cout << "array with 2 values removed:" << endl;
cout << array << endl << endl;
  
everything.remove<JSONArray>("array");
everything.remove<JSONArray>("nested_array");
cout << "everything with only one JSONObject:" << endl;
cout << everything << endl << endl;
```

**Output**
```
get examples:
325.178
hello world
[]

array with 2 values removed:
[
  "hello world"
]

everything with only one value:
{
  "object": {
    "1": null,
    "2": 325.178394,
    "3": false
  }
}
```

*Note that the get functions only return copies of the values, not an actual
reference to the values. This means that something like
object.get<JSONArray>("1").remove<int>(2) will not actually remove
anything from the object. It will actually remove the 3rd value from a
copy of the JSONArray mapped to the "1" key in object.*

### Parsing json

If you have a string containing valid json, you can use the following two functions to parse those strings into a JSONArray or JSONObject.

**Code**
```c++
string json_array = "[[{},[]], \t\n\"hi\", -23.2,\n\n 1202, null]";
string json_object = "{\"1\": [502,\"json\",{}], \n\t\"wow\":\n\n 42}";
array = parseJSON<JSONArray>(json_array);
object = parseJSON<JSONObject>(json_object);

cout << "array:" << endl;
cout << array << endl << endl;
cout << "object:" << endl;
cout << object << endl << endl;
```

**Output**
```

array:
[
  "hi",
  null,
  1202,
  -23.200000,
  [
    [],
    {}
  ]
]

object:
{
  "wow": 42,
  "1": [
    "json",
    502,
    {}
  ]
}
```

*Right now, if you pass in invalid JSON strings to the parsing function,
there's undefined behavior.*

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

### Additional stuff to do when I come back to this project

* Parsing exponents (i.e. e, e+, e-, E, E+, E-)
* Error handling for get, remove, and parsing functions
* Overloading stream insertion operators (i.e. cin >> object)
* Figuring out how to_string works and trying to implement that into some
of the functions (i.e. [read later](https://stackoverflow.com/questions/33399594/making-a-user-defined-class-stdto-stringable))
* Changing the compilation of the source code into a shared object library
instead of a static library
* Implementing the [] operator with operator overloading (seems pretty hard to
do and might have to look into C++11) to abstract all different data types
away