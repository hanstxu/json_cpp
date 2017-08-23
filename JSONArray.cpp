#include "JSONArray.h"

JSONArray::JSONArray() {}

void JSONArray::addString(std::string value) {
  m_strings.push_back(value);
}

std::string JSONArray::toString() const {
  std::string result = "[";
  
  std::vector<std::string>::const_iterator it = m_strings.begin();
  if (it != m_strings.end()) {
    result += "\n" + getJSONString(*it);
    ++it;
  }
  for (; it != m_strings.end(); ++it) {
    result += ",\n" + getJSONString(*it);
  }
  
  return result + "\n]";
}