#include "JSONObject.h"
#include "JSONArray.h"

#include <iostream>
using namespace std;

void check_functionality() {
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
  /*
  JSONArray arr_test;
  arr_test.add<JSONArray>(array);
  arr_test.add<JSONObject>(test);
  cout << arr_test.toString() << endl;
  */
  
  /*
  cout << (object.get<bool>("3")) << endl;
  cout << object.get<string>("1") << endl;
  cout << test.get<int>("4") << endl;
  cout << test.get<JSONArray>("1").toString() << endl;
  cout << test.get<JSONObject>("2").toString() << endl;
  cout << test.toString() << endl;
  */
  
  object.remove<string>("1");
  test.remove<int>("4");
  object.remove<double>("5");
  object.remove<bool>("3");
  test.remove<JSONArray>("1");
  test.remove<JSONObject>("2");
  cout << object.toString() << endl;
  cout << test.toString() << endl;
}

int main() {
  //check_functionality();
  
  string test = "[true, \"hello world\", null, -12341.234, .21923444, -1272,";
  test += "87]";
  cout << parseJSON<JSONArray>(test).toString() << endl;
  
  test = "{\"1\":true,\"2\":  \"hello world\", \"3\": null,";
  test += "\"4\": -12341.234, \"5\": .21923444 + \"6\": -1272, \"7\":87";
  test += "}";
  cout << parseJSON<JSONObject>(test).toString() << endl;
  
  return 0;
}