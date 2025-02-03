#include "Room.hpp"
#include <crow/json.h>

crow::json::wvalue Room::toJson() const {
  crow::json::wvalue json;
  json["id"] = getId();
  json["number"] = getNumber();
  json["price"] = getPrice();
  json["floor"] = getFloor();
  json["isSuite"] = getIsSuite();
  json["airConditioner"] = getAirConditioner();
  json["guestCapacity"] = getGuestCapacity();
  json["bunkbed"] = getBunkbed();
  json["createdAt"] = getCreatedAt();
  json["updatedAt"] = getUpdatedAt();
  json["deletedAt"] = getDeletedAt();
  return json;
}

Room Room::fromJson(const crow::json::rvalue& json) {
  Room room;
  room.setNumber(json["number"].i());
  room.setPrice(json["price"].i());
  room.setFloor(json["floor"].i());
  room.setIsSuite(json["isSuite"].b());
  room.setAirConditioner(json["airConditioner"].b());
  room.setGuestCapacity(json["guestCapacity"].i());
  room.setBunkbed(json["bunkbed"].b());
  return room;
}
