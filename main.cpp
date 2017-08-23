#include "JSONObject.h"
#include "JSONArray.h"

#include <iostream>
using namespace std;

int main() {
  JSONObject object;
  object.addString("1", "hello");
  object.addString("2", "world");
  JSONArray array;
  array.addString("item one");
  array.addString("item two");
  JSONObject test;
  test.addArray("1", array);
  test.addObject("2", object);
  test.addObject("3", test);
  cout << test.toString() << endl;
  return 0;
}