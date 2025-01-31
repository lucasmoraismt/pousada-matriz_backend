#pragma once
#include "../../models/Rental/Rental.hpp"
#include "../../utils/Database.hpp"
#include <pqxx/pqxx>
#include <crow/json.h>

class RentalRepository {
public:
  static crow::response getAllRentals();
  static crow::response getRentalById(int id);
  static crow::response createRental(const crow::request& req);
  static crow::response updateRental(const crow::request& req, int id);
  static crow::response deleteRental(int id);
};
