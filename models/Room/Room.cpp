#include "Room.hpp"
#include <crow/json.h>

crow::json::wvalue Room::toJson() const {
  crow::json::wvalue json;
  json["id"] = id;
  json["number"] = number;
  json["price"] = price;
  json["floor"] = floor;
  json["isSuite"] = isSuite;
  json["airConditioner"] = airConditioner;
  json["guestCapacity"] = guestCapacity;
  json["bunkbed"] = bunkbed;
  json["createdAt"] = createdAt;
  json["updatedAt"] = updatedAt;
  json["deletedAt"] = deletedAt;
  return json;
}

Room Room::fromJson(const crow::json::rvalue& json) {
  Room room;
  room.number = json["number"].i();
  room.price = json["price"].i();
  room.floor = json["floor"].i();
  room.isSuite = json["isSuite"].b();
  room.airConditioner = json["airConditioner"].b();
  room.guestCapacity = json["guestCapacity"].i();
  room.bunkbed = json["bunkbed"].b();
  return room;
}
