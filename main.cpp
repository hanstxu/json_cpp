#include "JSONObject.h"
#include "JSONArray.h"

#include <iostream>
using namespace std;

void check_functionality_of_classes() {
  JSONObject object;
  object.add<string>("1", "hello");
  object.add<string>("2", "world");
  object.add<bool>("3", true);
  object.add<bool>("4", false);
  object.add<double>("5", 234.1233);
  JSONArray array;
  array.add<string>("item one");
  array.add<string>("");
  array.add<bool>(true);
  array.add<bool>(false);
  array.add<int>(17);
  array.add<int>(-23);
  array.add<double>(-733.3411111);
  JSONObject test;
  test.add<JSONArray>("1", array);
  test.add<JSONObject>("2", object);
  test.add<JSONObject>("3", test);
  test.add<int>("4", 18);
  test.add<int>("5", -20);
  cout << test.toString() << endl;

  JSONArray arr_test;
  arr_test.add<JSONArray>(array);
  arr_test.add<JSONObject>(test);
  cout << arr_test.toString() << endl;
  
  /*
  cout << (object.get<bool>("3")) << endl;
  cout << object.get<string>("1") << endl;
  cout << test.get<int>("4") << endl;
  cout << test.get<JSONArray>("1").toString() << endl;
  cout << test.get<JSONObject>("2").toString() << endl;
  cout << test.toString() << endl;
  */
  
  /*
  object.remove<string>("1");
  test.remove<int>("4");
  object.remove<double>("5");
  object.remove<bool>("3");
  test.remove<JSONArray>("1");
  test.remove<JSONObject>("2");
  cout << object.toString() << endl;
  cout << test.toString() << endl;
  */
  
  cout << array.get<std::string>(0) << endl;
  cout << array.get<int>(0) << endl;
  cout << array.get<double>(0) << endl;
  cout << array.get<bool>(0) << endl;
  cout << arr_test.get<JSONArray>(0).toString() << endl;
  cout << arr_test.get<JSONObject>(0).toString() << endl;
}

void check_functionality_of_parsing() {
  string object = "{\"1\":true,\"2\":  \"hello world\", \"3\": null,";
  object += "\"4\": -12341.234, \"5\":\n\t .21923444 + \"6\": -1272, \"7\":87,";
  object += "\"8\": { \"A\":{\"a\":\n\t{-5021},\"b\":\"what is going on\", \"c\":false} }";
  
  string array = "[true, \"hello world\", null, -12341.234, .21923444, -1272,";
  array += "87, [[" + object + ",[]]]]";
  unsigned int index = 1;
  cout << parseJSON<JSONArray>(index, array).toString() << endl;
  
  object = "{\"1\":true,\"2\":  \"hello world\", \"3\": null,";
  object += "\"4\": -12341.234, \"5\":\n\t\t\t\t\n\n\n\n\n .21923444 + \"6\": -1272, \"7\":87,";
  object += "\"8\": { \"A\":{\"a\":\n\t{-5021},\"b\":\"what is going on\", \"c\":";
  object += array + " } }";
  index = 0;
  cout << parseJSON<JSONObject>(index, object).toString() << endl;
}

int main() {
  check_functionality_of_classes();
  //check_functionality_of_parsing();
  
  
  
  return 0;
}