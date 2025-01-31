#pragma once
#include <string>
#include <crow/json.h>

class Rental {
public:
  int id;
  std::string startDate;
  std::string endDate;
  int roomId;
  std::string createdAt;
  std::string updatedAt;
  std::string deletedAt;

  Rental() = default;
  
  crow::json::wvalue toJson() const;
  static Rental fromJson(const crow::json::rvalue& json);
};
