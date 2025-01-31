#pragma once
#include "../../models/Room/Room.hpp"
#include "../../utils/Database.hpp"
#include <pqxx/pqxx>
#include <crow/json.h>

class RoomRepository {
public:
  static crow::response getAllRooms();
  static crow::response getRoomById(int id);
  static crow::response createRoom(const crow::request& req);
  static crow::response updateRoom(const crow::request& req, int id);
  static crow::response deleteRoom(int id);
};
