# Pousada Matriz - Hotel Management System

Welcome to **Pousada Matriz**, a hotel room management system developed in C++ for the Object-Oriented Data Structures course at the Center of Informatics (CIn), Federal University of Pernambuco (UFPE). This project demonstrates the application of modern C++ programming paradigms, object-oriented design principles, and RESTful API development for managing rooms and rentals in a hotel.

---

## Table of Contents
1. [Project Overview](#project-overview)
2. [Architecture and Design](#architecture-and-design)
   - [Folder Structure](#folder-structure)
   - [Database Schema](#database-schema)
   - [Repository Pattern](#repository-pattern)
   - [Database Configuration](#database-configuration)
3. [Object-Oriented Features](#object-oriented-features)
   - [Encapsulation](#encapsulation)
   - [Abstraction](#abstraction)
   - [Inheritance and Polymorphism](#inheritance-and-polymorphism)
4. [RESTful API Endpoints](#restful-api-endpoints)
   - [Room Endpoints](#room-endpoints)
   - [Rental Endpoints](#rental-endpoints)
5. [Requirements and Tools](#requirements-and-tools)
6. [Setup and Configuration](#setup-and-configuration)
7. [Build and Execution](#build-and-execution)
8. [Contributing](#contributing)
9. [License](#license)

---

## Project Overview

Pousada Matriz is a backend system designed to manage hotel rooms and their rentals. It provides a RESTful API for performing CRUD (Create, Read, Update, Delete) operations on two main entities:
- **Room**: Represents a hotel room with attributes like ID, type, and availability.
- **Rental**: Represents a booking or rental of a room, including start date, end date, and associated room ID.

The system is built using modern C++ and leverages the **libpqxx** library for PostgreSQL database interactions. It follows object-oriented programming (OOP) principles and uses the **Repository Pattern** to separate data access logic from business logic.

---

## Architecture and Design

### Folder Structure
The project is organized into a clean and modular folder structure to ensure maintainability and readability.

![Folder Structure](assets/architecture.png)

- **`models/`**: Defines the data models (e.g., `Room`, `Rental`).
- **`repositories/`**: Implements the repository pattern for database interactions.
- **`utils/`**: Utility functions and helpers.
- **`sql/`**: SQL scripts for database setup.
- **`main.cpp`**: Contains the main application source code as well as routes.

### Database Schema
The PostgreSQL database schema consists of two main tables: `room` and `rental`.

![Database Schema](assets/schema.png)

- **`room`**:
  - `id`: Unique identifier for the room.
  - `number`: Number of the room.
  - `price`: Rental price for the room.
  - `floor`: Floor of the room.
  - `isSuite`: Boolean.
  - `airConditioner`: Boolean.
  - `guestCapacity`: Number of max guests accepted.
  - `bunkbed`: Boolean.
  - `createdAt`: Timestamp when the room was created.
  - `updatedAt`: Timestamp when the room was last updated.
  - `deletedAt`: Timestamp when the room was soft-deleted.

- **`rental`**:
  - `id`: Unique identifier for the rental.
  - `startDate`: Start date of the rental.
  - `endDate`: End date of the rental.
  - `roomId`: Foreign key referencing the `room` table.
  - `createdAt`: Timestamp when the rental was created.
  - `updatedAt`: Timestamp when the rental was last updated.
  - `deletedAt`: Timestamp when the rental was soft-deleted.

### Repository Pattern
The Repository Pattern is used to abstract database operations. Each entity (`Room` and `Rental`) has a corresponding repository class that handles CRUD operations.

![Repository Pattern](assets/repository.png)

- **`RoomRepository`**: Manages database operations for the `room` table.
- **`RentalRepository`**: Manages database operations for the `rental` table.

### Database Configuration
The database connection is configured using environment variables. The `DATABASE_URL` environment variable specifies the connection string for PostgreSQL.

![Database Configuration](assets/database.png)

---

## Object-Oriented Features

### Encapsulation
Encapsulation is achieved by defining private data members in the `Room` and `Rental` classes and providing public getters and setters to access and modify them.

```cpp
class Room {
private:
    int id;
    std::string type;
    std::string createdAt;
    std::string updatedAt;
    std::string deletedAt;

public:
    // Getters and setters
    int getId() const { return id; }
    void setId(int id) { this->id = id; }
    // ...
};
```

## Abstraction
Abstraction is demonstrated by hiding the implementation details of database operations in the repository classes. The controllers interact with the repositories without needing to know how the data is stored or retrieved.

## Inheritance and Polymorphism
While not heavily used yet, this project will be updated in the future for real world use and fill have more features.

---

## RESTful API Endpoints

### Room Endpoints
- **GET `/rooms`**: Retrieve all rooms.
- **GET `/rooms/{id}`**: Retrieve a room by ID.
- **POST `/rooms`**: Create a new room.
- **PUT `/rooms/{id}`**: Update a room by ID.
- **DELETE `/rooms/{id}`**: Soft-delete a room by ID.

### Rental Endpoints
- **GET `/rentals`**: Retrieve all rentals.
- **GET `/rentals/{id}`**: Retrieve a rental by ID.
- **POST `/rentals`**: Create a new rental.
- **PUT `/rentals/{id}`**: Update a rental by ID.
- **DELETE `/rentals/{id}`**: Soft-delete a rental by ID.

---

## Requirements and Tools

- **CMake** (>= 3.15): For building the project.
- **C++ Compiler** (GCC/Clang/MSVC): For compiling the code.
- **PostgreSQL**: As the database system.
- **libpqxx**: C++ library for PostgreSQL.
- **OpenSSL**: For secure connections.

---

## Demonstration Video

Watch the video below to see a demonstration of the Pousada Matriz system in action:

[![Pousada Matriz Demo](https://img.youtube.com/vi/0bcUxExTQoE/0.jpg)](https://youtu.be/0bcUxExTQoE)

*Click the thumbnail above to watch the video on YouTube.*

---

## Setup and Configuration

1. Set up the PostgreSQL database connection:
   ```bash
   export DATABASE_URL="postgresql://user:password@host:port/dbname"
   ```
2. Create the database tables:
   ```bash
   psql "postgresql://user:password@host:port/dbname" -f sql/create_tables.sql
   ```

## Build and Execution
1. Clone the repository:
   ```bash
   git clone https://github.com/lucasmoraismt/pousada_matriz.git
   cd pousada_matriz
   ```
2. Configure and build the project:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```
3. Run the application:
   ```bash
   ./guesthouse_backend
   ```
