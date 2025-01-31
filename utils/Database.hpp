#pragma once
#include <pqxx/pqxx>
#include <string>

class Database {
public:
  static void initialize();
  static std::string getConnectionString();

private:
  static std::string connectionString;
};