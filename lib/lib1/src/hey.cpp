#include "hey.h"

Hey::Hey(std::string label) : label(label) {

}

std::string Hey::get() const {
  return this->label;
}
