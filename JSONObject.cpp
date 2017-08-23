#include "JSONObject.h"

JSONObject::JSONObject() {}

void JSONObject::addString(std::string key, std::string value) {
  m_strings[key] = value;
}

std::string JSONObject::toString() const {
  std::string result = "{";
  
  std::map<std::string,std::string>::const_iterator it = m_strings.begin();
  if (it != m_strings.end()) {
    result += "\n" + getJSONString(it->first);
    result += ": " + getJSONString(it->second);
	++it;
  }
  for (; it != m_strings.end(); ++it) {
    result += ",\n" + getJSONString(it->first);
    result += ": " + getJSONString(it->second);
  }
  
  return result + "\n}";
}