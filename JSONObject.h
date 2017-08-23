#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include <map>
#include <string>

class JSONObject {
public:
  JSONObject();
  std::string to_string() const;
private:
  std::map<std::string, std::string> m_strings;
};

#endif