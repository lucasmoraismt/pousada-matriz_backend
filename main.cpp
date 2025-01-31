#include <crow.h>
#include "models/Room/Room.hpp"
#include "models/Rental/Rental.hpp"
#include "repositories/Room/RoomRepository.hpp"
#include "repositories/Rental/RentalRepository.hpp"
#include "utils/Database.hpp"
#include "utils/Env.hpp"

int main() {
  Env::load(".env");
  Database::initialize();

  crow::SimpleApp app;

  // Room routes
  CROW_ROUTE(app, "/rooms").methods("GET"_method)([]{
    return RoomRepository::getAllRooms();
  });

  CROW_ROUTE(app, "/rooms/<int>").methods("GET"_method)([](int id){
    return RoomRepository::getRoomById(id);
  });

  CROW_ROUTE(app, "/rooms").methods("POST"_method)([](const crow::request& req){
    return RoomRepository::createRoom(req);
  });

  CROW_ROUTE(app, "/rooms/<int>").methods("PUT"_method)([](const crow::request& req, int id){
    return RoomRepository::updateRoom(req, id);
  });

  CROW_ROUTE(app, "/rooms/<int>").methods("DELETE"_method)([](int id){
    return RoomRepository::deleteRoom(id);
  });

  // Rental routes
  CROW_ROUTE(app, "/rentals").methods("GET"_method)([]{
    return RentalRepository::getAllRentals();
  });

  CROW_ROUTE(app, "/rentals/<int>").methods("GET"_method)([](int id){
    return RentalRepository::getRentalById(id);
  });

  CROW_ROUTE(app, "/rentals").methods("POST"_method)([](const crow::request& req){
    return RentalRepository::createRental(req);
  });

  CROW_ROUTE(app, "/rentals/<int>").methods("PUT"_method)([](const crow::request& req, int id){
    return RentalRepository::updateRental(req, id);
  });

  CROW_ROUTE(app, "/rentals/<int>").methods("DELETE"_method)([](int id){
    return RentalRepository::deleteRental(id);
  });

  app.port(8080).multithreaded().run();
}
