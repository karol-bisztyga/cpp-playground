#pragma once

#include <string>

class Hey {
  std::string label;
public:
  Hey(std::string label);
  std::string get() const;
};
