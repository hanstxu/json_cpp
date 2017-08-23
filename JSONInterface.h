#ifndef JSONINTERFACE_H
#define JSONINTERFACE_H

#include <string>

inline std::string getJSONString(std::string value) {
  return "\"" + value + "\"";
}

inline std::string getJSONNumber(int value) {
  std::string result;
  int abs_value = (value < 0 ? -value : value);
  while ( abs_value > 0) {
    char c = (abs_value % 10) + '0';
    result = c + result;
    abs_value /= 10;
  }
  
  return (value < 0 ? "-" + result : result);
}

class JSONInterface {
public:
  JSONInterface() { tab_spaces = ""; }
  virtual std::string toString() const = 0;
protected:
  std::string tab_spaces;
  void updateNumTabSpaces(unsigned int num_tabs) {
    tab_spaces = "";
    for (unsigned int i = 0; i < num_tabs; i++)
      tab_spaces += "\x20\x20";
  }
};

#endif