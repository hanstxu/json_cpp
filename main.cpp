#include "JSONObject.h"
#include "JSONArray.h"

#include <iostream>
using namespace std;

int main() {
  JSONObject object;
  object.add<string>("1", "hello");
  object.add<string>("2", "world");
  object.add<bool>("3", true);
  object.add<bool>("4", false);
  JSONArray array;
  array.add<string>("item one");
  array.add<string>("");
  array.add<bool>(true);
  array.add<bool>(false);
  array.add<int>(17);
  array.add<int>(-23);
  JSONObject test;
  test.add<JSONArray>("1", array);
  test.add<JSONObject>("2", object);
  test.add<JSONObject>("3", test);
  test.add<int>("4", 18);
  test.add<int>("5", -20);
  JSONArray arr_test;
  arr_test.add<JSONArray>(array);
  arr_test.add<JSONObject>(test);
  cout << arr_test.toString() << endl;
  
  cout << (object.get<bool>("3") == true) << endl;
  cout << object.get<string>("1") << endl;
  cout << test.get<int>("4") << endl;
  cout << test.get<JSONArray>("1").toString() << endl;
  cout << test.get<JSONObject>("2").toString() << endl;
  
  return 0;
}