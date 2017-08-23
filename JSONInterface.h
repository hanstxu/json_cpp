#ifndef JSONINTERFACE_H
#define JSONINTERFACE_H

#include <string>

inline std::string getJSONString(std::string value) {
  return "\"" + value + "\"";
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