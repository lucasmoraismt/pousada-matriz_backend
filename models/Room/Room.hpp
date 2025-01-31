#pragma once
#include <string>
#include <crow/json.h>

class Room {
public:
  int id;
  int number;
  int price;
  int floor;
  bool isSuite;
  bool airConditioner;
  int guestCapacity;
  bool bunkbed;
  std::string createdAt;
  std::string updatedAt;
  std::string deletedAt;

  Room() = default;

  crow::json::wvalue toJson() const;
  static Room fromJson(const crow::json::rvalue& json);
};
