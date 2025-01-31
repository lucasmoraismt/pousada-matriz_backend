#pragma once
#include <fstream>
#include <cstdlib>
#include <string>

class Env {
public:
  static void load(const std::string& filename);
  static std::string get(const std::string& key);
};
