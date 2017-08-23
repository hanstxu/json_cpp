#include "JSONObject.h"

JSONObject::JSONObject() {}

void JSONObject::addString(std::string key, std::string value) {
  m_strings[key] = value;
}

void JSONObject::addNumber(std::string key, int value) {
  m_numbers[key] = value;
}

void JSONObject::addBoolean(std::string key, bool value) {
  m_booleans[key] = value;
}

void JSONObject::addObject(std::string key, JSONObject value) {
  value.updateTabs(1);
  m_objects[key] = value;
}

void JSONObject::addArray(std::string key, JSONArray value) {
  value.updateTabs(1);
  m_arrays[key] = value;
}

void JSONObject::updateTabs(unsigned int num_tabs) {
  updateNumTabSpaces(num_tabs);
  std::map<std::string, JSONObject>::iterator obj_it;
  for (obj_it = m_objects.begin(); obj_it != m_objects.end(); ++obj_it)
    obj_it->second.updateTabs(num_tabs + 1);
  std::map<std::string, JSONArray>::iterator arr_it;
  for (arr_it = m_arrays.begin(); arr_it != m_arrays.end(); ++arr_it)
    arr_it->second.updateTabs(num_tabs + 1);
}

std::string JSONObject::toString() const {
  if (m_strings.size() + m_booleans.size() + m_numbers.size() +
    m_objects.size() + m_arrays.size() < 1)
    return "{}";

  std::string result = "{";
  
  std::map<std::string, std::string>::const_iterator str_it = m_strings.begin();
  if (str_it != m_strings.end()) {
    result += "\n\x20\x20" + tab_spaces + getJSONString(str_it->first) + ": ";
    result += (str_it->second == "" ? "null" : getJSONString(str_it->second));
	++str_it;
  }
  for (; str_it != m_strings.end(); ++str_it) {
    result += ",\n\x20\x20" + tab_spaces + getJSONString(str_it->first) + ": ";
    result += (str_it->second == "" ? "null" : getJSONString(str_it->second));
  }
  
  std::map<std::string, int>::const_iterator num_it = m_numbers.begin();
  if (num_it != m_numbers.end()) {
    result += "\n\x20\x20" + tab_spaces + getJSONString(num_it->first);
    result += ": " + getJSONNumber(num_it->second);
    ++num_it;
  }
  for (; num_it != m_numbers.end(); ++num_it) {
    result += ",\n\x20\x20" + tab_spaces + getJSONString(num_it->first);
    result += ": " + getJSONNumber(num_it->second);
  }
  
  std::map<std::string, bool>::const_iterator bool_it = m_booleans.begin();
  if (bool_it != m_booleans.end()) {
    result += "\n\x20\x20" + tab_spaces + getJSONString(bool_it->first) + ": ";
    result += (bool_it->second ? "true" : "false");
	++bool_it;
  }
  for (; bool_it != m_booleans.end(); ++bool_it) {
    result += ",\n\x20\x20" + tab_spaces + getJSONString(bool_it->first) + ": ";
    result += (bool_it->second ? "true" : "false");
  }
  
  std::map<std::string, JSONObject>::const_iterator obj_it = m_objects.begin();
  if (m_strings.size() < 1 && obj_it != m_objects.end()) {
    result += "\n\x20\x20" + tab_spaces + getJSONString(obj_it->first);
    result += ": " + obj_it->second.toString();
    ++obj_it;
  }
  for (; obj_it != m_objects.end(); ++obj_it) {
    result += ",\n\x20\x20" + tab_spaces + getJSONString(obj_it->first);
    result += ": " + obj_it->second.toString();
  }
  
  std::map<std::string, JSONArray>::const_iterator arr_it = m_arrays.begin();
  if (m_strings.size() < 1 && m_objects.size() < 1 &&
    arr_it != m_arrays.end()) {
    result += "\n\x20\x20" + tab_spaces + getJSONString(arr_it->first);
    result += ": " + arr_it->second.toString();
    ++arr_it;
  }
  for (; arr_it != m_arrays.end(); ++arr_it) {
    result += ",\n\x20\x20" + tab_spaces + getJSONString(arr_it->first);
    result += ": " + arr_it->second.toString();
  }
  
  return result + "\n" + tab_spaces + "}";
}