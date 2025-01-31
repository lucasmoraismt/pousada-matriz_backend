#include <crow.h>
#include "RoomRepository.hpp"
#include "../../models/Room/Room.hpp"

crow::response RoomRepository::getAllRooms() {
  try {
    pqxx::connection conn(Database::getConnectionString());
    pqxx::work txn(conn);
    pqxx::result result = txn.exec("SELECT * FROM rooms WHERE deletedAt IS NULL");

    crow::json::wvalue json;
    int index = 0;
    for (auto row : result) {
      json[index]["id"] = row["id"].as<int>();
      json[index]["number"] = row["number"].as<int>();
      json[index]["price"] = row["price"].as<int>();
      json[index]["floor"] = row["floor"].as<int>();
      json[index]["isSuite"] = row["isSuite"].as<bool>();
      json[index]["airConditioner"] = row["airConditioner"].as<bool>();
      json[index]["guestCapacity"] = row["guestCapacity"].as<int>();
      json[index]["bunkbed"] = row["bunkbed"].as<bool>();
      json[index]["createdAt"] = row["createdAt"].as<std::string>();
      json[index]["updatedAt"] = row["updatedAt"].as<std::string>();
      index++;
    }
    return crow::response{json};
  } catch (const std::exception& e) {
    return crow::response(500, e.what());
  }
}

crow::response RoomRepository::getRoomById(int id) {
  try {
    pqxx::connection conn(Database::getConnectionString());
    pqxx::work txn(conn);
    pqxx::result result = txn.exec_params(
      "SELECT * FROM rooms WHERE id = $1 AND deletedAt IS NULL",
      id
    );

    if (result.empty()) {
      return crow::response(404, "Room not found");
    }

    auto row = result[0];
    crow::json::wvalue json;
    json["id"] = row["id"].as<int>();
    json["number"] = row["number"].as<int>();
    json["price"] = row["price"].as<int>();
    json["floor"] = row["floor"].as<int>();
    json["isSuite"] = row["isSuite"].as<bool>();
    json["airConditioner"] = row["airConditioner"].as<bool>();
    json["guestCapacity"] = row["guestCapacity"].as<int>();
    json["bunkbed"] = row["bunkbed"].as<bool>();
    json["createdAt"] = row["createdAt"].as<std::string>();
    json["updatedAt"] = row["updatedAt"].as<std::string>();

    return crow::response{json};
  } catch (const std::exception& e) {
    return crow::response(500, e.what());
  }
}

crow::response RoomRepository::createRoom(const crow::request& req) {
  try {
    auto json = crow::json::load(req.body);
    if (!json) {
      return crow::response(400, "Invalid JSON");
    }

    Room room = Room::fromJson(json);

    pqxx::connection conn(Database::getConnectionString());
    pqxx::work txn(conn);

    txn.exec_params(
      "INSERT INTO rooms (number, price, floor, isSuite, airConditioner, guestCapacity, bunkbed) "
      "VALUES ($1, $2, $3, $4, $5, $6, $7)",
      room.number,
      room.price,
      room.floor,
      room.isSuite,
      room.airConditioner,
      room.guestCapacity,
      room.bunkbed
    );
    txn.commit();

    return crow::response(201);
  } catch (const std::exception& e) {
      return crow::response(500, e.what());
  }
}

crow::response RoomRepository::updateRoom(const crow::request& req, int id) {
  try {
    auto json = crow::json::load(req.body);
    if (!json) {
      return crow::response(400, "Invalid JSON");
    }

    Room room = Room::fromJson(json);

    pqxx::connection conn(Database::getConnectionString());
    pqxx::work txn(conn);

    txn.exec_params(
      "UPDATE rooms SET "
      "number = $1, price = $2, floor = $3, isSuite = $4, "
      "airConditioner = $5, guestCapacity = $6, bunkbed = $7 "
      "WHERE id = $8",
      room.number,
      room.price,
      room.floor,
      room.isSuite,
      room.airConditioner,
      room.guestCapacity,
      room.bunkbed,
      id
    );
    txn.commit();

    return crow::response(200);
  } catch (const std::exception& e) {
    return crow::response(500, e.what());
  }
}

crow::response RoomRepository::deleteRoom(int id) {
  try {
    pqxx::connection conn(Database::getConnectionString());
    pqxx::work txn(conn);

    txn.exec_params(
      "UPDATE rooms SET deletedAt = NOW() WHERE id = $1",
      id
    );
    txn.commit();

    return crow::response(204);
  } catch (const std::exception& e) {
    return crow::response(500, e.what());
  }
}
