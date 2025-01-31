#include "Env.hpp"

void Env::load(const std::string& filename) {
  std::ifstream file(filename);  // Requires <fstream>
  std::string line;
  
  while (std::getline(file, line)) {
    size_t delimiterPos = line.find('=');
    if (delimiterPos != std::string::npos) {
      std::string key = line.substr(0, delimiterPos);  // Requires <string>
      std::string value = line.substr(delimiterPos + 1);  // Requires <string>
      setenv(key.c_str(), value.c_str(), 1);  // Requires <cstdlib>
    }
  }
}

std::string Env::get(const std::string& key) {
  const char* value = std::getenv(key.c_str());  // Requires <cstdlib>
  return value ? std::string(value) : "";  // Requires <string>
}
