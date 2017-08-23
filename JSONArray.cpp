#include "JSONArray.h"

JSONArray::JSONArray() {}

void JSONArray::addString(std::string value) {
  m_strings.push_back(value);
}

void JSONArray::addNumber(int value) {
  m_numbers.push_back(value);
}

void JSONArray::addBoolean(bool value) {
  m_booleans.push_back(value);
}

void JSONArray::addArray(JSONArray value) {
  value.updateTabs(1);
  m_arrays.push_back(value);
}

void JSONArray::addObject(JSONObject value) {
  value.updateTabs(1);
  m_objects.push_back(value);
}

void JSONArray::updateTabs(unsigned int num_tabs) {
  updateNumTabSpaces(num_tabs);
  for (unsigned int i = 0; i < m_arrays.size(); i++)
    m_arrays[i].updateTabs(num_tabs + 1);
  for (unsigned int i = 0; i < m_objects.size(); i++)
    m_objects[i].updateTabs(num_tabs + 1);
}


std::string JSONArray::toString() const {
  if (m_strings.size() + m_booleans.size() + m_numbers.size() +
    m_arrays.size() + m_objects.size() < 1)
    return "[]";
  
  std::string result = "[";
  
  std::vector<std::string>::const_iterator str_it = m_strings.begin();
  if (str_it != m_strings.end()) {
    result += "\n\x20\x20" + tab_spaces;
    result += (*str_it == "" ? "null" : getJSONString(*str_it));
    ++str_it;
  }
  for (; str_it != m_strings.end(); ++str_it) {
    result += ",\n\x20\x20" + tab_spaces;
    result += (*str_it == "" ? "null" : getJSONString(*str_it));
  }
  
  std::vector<int>::const_iterator num_it = m_numbers.begin();
  if (num_it != m_numbers.end()) {
    result += "\n\x20\x20" + tab_spaces + getJSONNumber(*num_it);
    ++num_it;
  }
  for (; num_it != m_numbers.end(); ++num_it)
    result += ",\n\x20\x20" + tab_spaces + getJSONNumber(*num_it);
  
  std::vector<bool>::const_iterator bool_it = m_booleans.begin();
  if (bool_it != m_booleans.end()) {
    result += "\n\x20\x20" + tab_spaces + (*bool_it ? "true" : "false");
    ++bool_it;
  }
  for (; bool_it != m_booleans.end(); ++bool_it)
    result += ",\n\x20\x20" + tab_spaces + (*bool_it ? "true" : "false");

  std::vector<JSONArray>::const_iterator arr_it = m_arrays.begin();
  if (m_strings.size() < 1 && arr_it != m_arrays.end()) {
    result += "\n\x20\x20" + tab_spaces + arr_it->toString();
    ++arr_it;
  }
  for (; arr_it != m_arrays.end(); ++arr_it)
    result += ",\n\x20\x20" + tab_spaces + arr_it->toString();
  
  std::vector<JSONObject>::const_iterator obj_it = m_objects.begin();
  if (m_strings.size() < 1 && m_arrays.size() < 1 &&
    obj_it != m_objects.end()) {
    result += "\n\x20\x20" + tab_spaces + obj_it->toString();
    ++obj_it;
  }
  for (; obj_it != m_objects.end(); ++obj_it)
    result += ",\n\x20\x20" + tab_spaces + obj_it->toString();
  
  return result + "\n" + tab_spaces + "]";
}