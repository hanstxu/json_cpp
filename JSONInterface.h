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
  void updateNumTabSpaces(int num_tabs) {
    if (num_tabs < 0) {
      tab_spaces = tab_spaces.substr(0, tab_spaces.size() - 2);
      return;
    }
    tab_spaces = "";
    for (int i = 0; i < num_tabs; i++)
      tab_spaces += "\x20\x20";
  }
};

#endif