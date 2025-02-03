#pragma once
#include <string>
#include <crow/json.h>

class Room {
private:
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

public:
  Room() = default;

  // Getters
  int getId() const { return id; }
  int getNumber() const { return number; }
  int getPrice() const { return price; }
  int getFloor() const { return floor; }
  bool getIsSuite() const { return isSuite; }
  bool getAirConditioner() const { return airConditioner; }
  int getGuestCapacity() const { return guestCapacity; }
  bool getBunkbed() const { return bunkbed; }
  std::string getCreatedAt() const { return createdAt; }
  std::string getUpdatedAt() const { return updatedAt; }
  std::string getDeletedAt() const { return deletedAt; }

  // Setters
  void setId(int id) { this->id = id; }
  void setNumber(int number) { this->number = number; }
  void setPrice(int price) { this->price = price; }
  void setFloor(int floor) { this->floor = floor; }
  void setIsSuite(bool isSuite) { this->isSuite = isSuite; }
  void setAirConditioner(bool airConditioner) { this->airConditioner = airConditioner; }
  void setGuestCapacity(int guestCapacity) { this->guestCapacity = guestCapacity; }
  void setBunkbed(bool bunkbed) { this->bunkbed = bunkbed; }
  void setCreatedAt(const std::string& createdAt) { this->createdAt = createdAt; }
  void setUpdatedAt(const std::string& updatedAt) { this->updatedAt = updatedAt; }
  void setDeletedAt(const std::string& deletedAt) { this->deletedAt = deletedAt; }

  crow::json::wvalue toJson() const;
  static Room fromJson(const crow::json::rvalue& json);
};