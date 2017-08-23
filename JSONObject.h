#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include "JSONInterface.h"
#include <map>
#include <string>

#include "JSONArray.h"
class JSONArray;

class JSONObject : public JSONInterface {
public:
  JSONObject();
  void addString(std::string key, std::string value);
  void addNumber(std::string key, int value);
  void addBoolean(std::string key, bool value);
  void addObject(std::string key, JSONObject value);
  void addArray(std::string key, JSONArray value);
  void updateTabs(unsigned int num_tabs);
  std::string toString() const;
private:
  std::map<std::string, std::string> m_strings;
  std::map<std::string, int> m_numbers;
  std::map<std::string, bool> m_booleans;
  std::map<std::string, JSONObject> m_objects;
  std::map<std::string, JSONArray> m_arrays;
};

#endif