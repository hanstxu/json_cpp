#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include "JSONInterface.h"
#include <map>
#include <string>

class JSONObject : public JSONInterface {
public:
  JSONObject();
  void addString(std::string key, std::string value);
  std::string toString() const;
private:
  std::map<std::string,std::string> m_strings;
};

#endif