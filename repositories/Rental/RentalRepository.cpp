#include <crow.h>
#include "RentalRepository.hpp"
#include "../../models/Rental/Rental.hpp"

crow::response RentalRepository::getAllRentals() {
  try {
    pqxx::connection conn(Database::getConnectionString());
    pqxx::work txn(conn);
    pqxx::result result = txn.exec(
      "SELECT id, startDate, endDate, roomId, createdAt, updatedAt "
      "FROM rentals WHERE deletedAt IS NULL"
    );

    crow::json::wvalue json;
    int index = 0;
    for (auto row : result) {
      Rental rental;
      rental.setId(row["id"].as<int>());
      rental.setStartDate(row["startDate"].as<std::string>());
      rental.setEndDate(row["endDate"].as<std::string>());
      rental.setRoomId(row["roomId"].as<int>());
      rental.setCreatedAt(row["createdAt"].as<std::string>());
      rental.setUpdatedAt(row["updatedAt"].as<std::string>());

      json[index] = rental.toJson();
      index++;
    }
    return crow::response{json};
  } catch (const std::exception& e) {
    return crow::response(500, e.what());
  }
}

crow::response RentalRepository::getRentalById(int id) {
  try {
    pqxx::connection conn(Database::getConnectionString());
    pqxx::work txn(conn);
    pqxx::result result = txn.exec_params(
      "SELECT id, startDate, endDate, roomId, createdAt, updatedAt "
      "FROM rentals WHERE id = $1 AND deletedAt IS NULL",
      id
    );

    if (result.empty()) {
        return crow::response(404, "Rental not found");
    }

    auto row = result[0];
    Rental rental;
    rental.setId(row["id"].as<int>());
    rental.setStartDate(row["startDate"].as<std::string>());
    rental.setEndDate(row["endDate"].as<std::string>());
    rental.setRoomId(row["roomId"].as<int>());
    rental.setCreatedAt(row["createdAt"].as<std::string>());
    rental.setUpdatedAt(row["updatedAt"].as<std::string>());

    return crow::response{rental.toJson()};
  } catch (const std::exception& e) {
    return crow::response(500, e.what());
  }
}

crow::response RentalRepository::createRental(const crow::request& req) {
  try {
    auto json = crow::json::load(req.body);
    if (!json) {
      return crow::response(400, "Invalid JSON");
    }

    Rental rental = Rental::fromJson(json);

    pqxx::connection conn(Database::getConnectionString());
    pqxx::work txn(conn);

    // Check room availability
    pqxx::result conflict = txn.exec_params(
      "SELECT id FROM rentals WHERE "
      "roomId = $1 AND "
      "(startDate, endDate) OVERLAPS (TO_DATE($2, 'DD/MM/YYYY'), TO_DATE($3, 'DD/MM/YYYY')) "
      "AND deletedAt IS NULL",
      rental.getRoomId(),
      rental.getStartDate(),
      rental.getEndDate()
    );

    if (!conflict.empty()) {
      return crow::response(409, "Room already booked for this period");
    }

    txn.exec_params(
      "INSERT INTO rentals (startDate, endDate, roomId) "
      "VALUES (TO_DATE($1, 'DD/MM/YYYY'), TO_DATE($2, 'DD/MM/YYYY'), $3)",
      rental.getStartDate(),
      rental.getEndDate(),
      rental.getRoomId()
    );
    txn.commit();

    return crow::response(201);
  } catch (const std::exception& e) {
    return crow::response(500, e.what());
  }
}

crow::response RentalRepository::updateRental(const crow::request& req, int id) {
  try {
    auto json = crow::json::load(req.body);
    if (!json) {
      return crow::response(400, "Invalid JSON");
    }

    Rental rental = Rental::fromJson(json);

    pqxx::connection conn(Database::getConnectionString());
    pqxx::work txn(conn);

    txn.exec_params(
      "UPDATE rentals SET "
      "startDate = TO_DATE($1, 'DD/MM/YYYY'), endDate = TO_DATE($2, 'DD/MM/YYYY'), roomId = $3 "
      "WHERE id = $4",
      rental.getStartDate(),
      rental.getEndDate(),
      rental.getRoomId(),
      id
    );
    txn.commit();

    return crow::response(200);
  } catch (const std::exception& e) {
    return crow::response(500, e.what());
  }
}

crow::response RentalRepository::deleteRental(int id) {
  try {
    pqxx::connection conn(Database::getConnectionString());
    pqxx::work txn(conn);
    
    txn.exec_params(
      "UPDATE rentals SET deletedAt = NOW() WHERE id = $1",
      id
    );
    txn.commit();

    return crow::response(204);
  } catch (const std::exception& e) {
    return crow::response(500, e.what());
  }
}
