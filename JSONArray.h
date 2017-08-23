#ifndef JSONARRAY_H
#define JSONARRAY_H

#include <vector>
#include <string>

class JSONArray {
public:
  JSONArray();
  std::string to_string() const;
private:
  std::vector<std::string> m_strings;
};

#endif