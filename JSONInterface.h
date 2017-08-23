#ifndef JSONINTERFACE_H
#define JSONINTERFACE_H

#include <string>

inline std::string getJSONString(std::string value) {
  return "\"" + value + "\"";
}

class JSONInterface {
public:
  JSONInterface() {};
  virtual std::string toString() const = 0;
};

#endif