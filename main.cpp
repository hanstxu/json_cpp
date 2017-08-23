#include "JSONObject.h"
#include "JSONArray.h"

#include <iostream>
using namespace std;

int main() {
  JSONObject object;
  object.addString("1", "hello");
  object.addString("2", "stuff");
  JSONArray array;
  array.addString("what up");
  array.addString("timeout");
  cout << object.toString() << endl;
  cout << array.toString() << endl;
  return 0;
}