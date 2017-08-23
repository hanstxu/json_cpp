#ifndef JSONARRAY_H
#define JSONARRAY_H

#include "JSONInterface.h"
#include <vector>
#include <string>

#include "JSONObject.h"
class JSONObject;

class JSONArray : public JSONInterface {
public:
  JSONArray();
  void addString(std::string value);
  void addNumber(int value);
  void addBoolean(bool value);
  void addArray(JSONArray value);
  void addObject(JSONObject value);
  void updateTabs(unsigned int num_tabs);
  std::string toString() const;
private:
  std::vector<std::string> m_strings;
  std::vector<int> m_numbers;
  std::vector<bool> m_booleans;
  std::vector<JSONArray> m_arrays;
  std::vector<JSONObject> m_objects;
};

#endif