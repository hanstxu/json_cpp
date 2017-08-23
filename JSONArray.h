#ifndef JSONARRAY_H
#define JSONARRAY_H

#include "JSONInterface.h"
#include <vector>
#include <string>

class JSONArray : public JSONInterface {
public:
  JSONArray();
  void addString(std::string value);
  std::string toString() const;
private:
  std::vector<std::string> m_strings;
};

#endif