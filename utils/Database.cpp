#include "Database.hpp"

std::string Database::connectionString = "";

void Database::initialize() {
  connectionString = Env::get("DATABASE_URL");
}

std::string Database::getConnectionString() {
  return connectionString;
}
