#include "Rental.hpp"
#include <crow/json.h>

crow::json::wvalue Rental::toJson() const {
  crow::json::wvalue json;
  json["id"] = id;
  json["startDate"] = startDate;
  json["endDate"] = endDate;
  json["roomId"] = roomId;
  json["createdAt"] = createdAt;
  json["updatedAt"] = updatedAt;
  json["deletedAt"] = deletedAt;
  return json;
}

Rental Rental::fromJson(const crow::json::rvalue& json) {
  Rental rental;
  rental.startDate = json["startDate"].s();
  rental.endDate = json["endDate"].s();
  rental.roomId = json["roomId"].i();
  return rental;
}
