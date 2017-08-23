#include "JSONArray.h"

JSONArray::JSONArray() {}

void JSONArray::addString(std::string value) {
  m_strings.push_back(value);
}

void JSONArray::addArray(JSONArray value) {
  m_arrays.push_back(value);
}

void JSONArray::addObject(JSONObject value) {
  m_objects.push_back(value);
}

std::string JSONArray::toString() const {
  if (m_strings.size() + m_arrays.size() + m_objects.size() < 1)
    return "[]";
  
  std::string result = "[";
  
  std::vector<std::string>::const_iterator str_it = m_strings.begin();
  if (str_it != m_strings.end()) {
    result += "\n" + getJSONString(*str_it);
    ++str_it;
  }
  for (; str_it != m_strings.end(); ++str_it) {
    result += ",\n" + getJSONString(*str_it);
  }
  
  std::vector<JSONArray>::const_iterator arr_it = m_arrays.begin();
  if (m_strings.size() < 1 && arr_it != m_arrays.end()) {
    result += "\n" + arr_it->toString();
    ++arr_it;
  }
  for (; arr_it != m_arrays.end(); ++arr_it) {
    result += ",\n" + arr_it->toString();
  }
  
  std::vector<JSONObject>::const_iterator obj_it = m_objects.begin();
  if (m_strings.size() < 1 && m_arrays.size() < 1 &&
    obj_it != m_objects.end()) {
    result += "\n" + obj_it->toString();
    ++obj_it;
  }
  for (; obj_it != m_objects.end(); ++obj_it) {
    result += ",\n" + obj_it->toString();
  }
  
  return result + "\n]";
}