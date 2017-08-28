#include "JSONObject.h"
#include "JSONArray.h"

#include <iostream>
using namespace std;

int main() {
  // Adding Values to the Two Classes
  JSONArray array;
  array.add<string>("hello world");
  array.add<int>(-2823);
  array.add<bool>(true);
  
  JSONObject object;
  object.add<string>("1", "");  // null is represented as an empty string
  object.add<double>("2", 325.178394);
  object.add<bool>("3", false);
  
  // Printing out the JSON
  cout << "array:" << endl;
  cout << array.toString() << endl << endl;
  cout << "object:" << endl;
  cout << object << endl << endl;
  
  // Recursive Classes
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
  
  // Get and Remove
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
  cout << "everything with only one value:" << endl;
  cout << everything << endl << endl;
  
  // Parsing json
  string json_array = "[[{},[]], \t\n\"hi\", -23.2,\n\n 1202, null]";
  string json_object = "{\"1\": [502,\"json\",{}], \n\t\"wow\":\n\n 42}";
  array = parseJSON<JSONArray>(json_array);
  object = parseJSON<JSONObject>(json_object);
  
  cout << "array:" << endl;
  cout << array << endl << endl;
  cout << "object:" << endl;
  cout << object << endl << endl;
  
  return 0;
}