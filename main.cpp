#include "JSONObject.h"
#include "JSONArray.h"

#include <iostream>
using namespace std;

int main() {
  JSONObject object;
  object.addString("1", "hello");
  object.addString("2", "world");
  object.addBoolean("3", true);
  object.addBoolean("4", false);
  JSONArray array;
  array.addString("item one");
  array.addString("item two");
  array.addBoolean(true);
  array.addBoolean(false);
  JSONObject test;
  test.addArray("1", array);
  test.addObject("2", object);
  test.addObject("3", test);
  cout << test.toString() << endl;
  return 0;
}