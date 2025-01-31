#include "Database.hpp"
#include <iostream>
#include <cstdlib>  // For std::getenv

std::string Database::connectionString = "";

void Database::initialize() {
    // Read the DATABASE_URL environment variable
    const char* dbUrl = std::getenv("DATABASE_URL");
    if (!dbUrl) {
        throw std::runtime_error("DATABASE_URL environment variable not found");
    }

    connectionString = dbUrl;
    std::cout << "Using connection string: " << connectionString << std::endl;
}

std::string Database::getConnectionString() {
    if (connectionString.empty()) {
        throw std::runtime_error("Database connection string not initialized");
    }
    return connectionString;
}
