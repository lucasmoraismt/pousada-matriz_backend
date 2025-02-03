#pragma once
#include <string>
#include <crow/json.h>

class Rental {
private:
  int id;
  std::string startDate;
  std::string endDate;
  int roomId;
  std::string createdAt;
  std::string updatedAt;
  std::string deletedAt;

public:
  Rental() = default;

  // Getters
  int getId() const { return id; }
  std::string getStartDate() const { return startDate; }
  std::string getEndDate() const { return endDate; }
  int getRoomId() const { return roomId; }
  std::string getCreatedAt() const { return createdAt; }
  std::string getUpdatedAt() const { return updatedAt; }
  std::string getDeletedAt() const { return deletedAt; }

  // Setters
  void setId(int id) { this->id = id; }
  void setStartDate(const std::string& startDate) { this->startDate = startDate; }
  void setEndDate(const std::string& endDate) { this->endDate = endDate; }
  void setRoomId(int roomId) { this->roomId = roomId; }
  void setCreatedAt(const std::string& createdAt) { this->createdAt = createdAt; }
  void setUpdatedAt(const std::string& updatedAt) { this->updatedAt = updatedAt; }
  void setDeletedAt(const std::string& deletedAt) { this->deletedAt = deletedAt; }

  crow::json::wvalue toJson() const;
  static Rental fromJson(const crow::json::rvalue& json);
};
