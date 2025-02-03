#pragma once
#include <pqxx/pqxx>
#include <string>

class Database {
private:
  static std::string connectionString;

public:
  static void initialize();
  static std::string getConnectionString();
};
