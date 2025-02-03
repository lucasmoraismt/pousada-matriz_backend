#include "Rental.hpp"
#include <crow/json.h>

crow::json::wvalue Rental::toJson() const {
  crow::json::wvalue json;
  json["id"] = getId();
  json["startDate"] = getStartDate();
  json["endDate"] = getEndDate();
  json["roomId"] = getRoomId();
  json["createdAt"] = getCreatedAt();
  json["updatedAt"] = getUpdatedAt();
  json["deletedAt"] = getDeletedAt();
  return json;
}

Rental Rental::fromJson(const crow::json::rvalue& json) {
  Rental rental;
  rental.setStartDate(json["startDate"].s());
  rental.setEndDate(json["endDate"].s());
  rental.setRoomId(json["roomId"].i());
  return rental;
}
