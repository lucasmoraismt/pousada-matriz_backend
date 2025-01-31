cmake_minimum_required(VERSION 3.15)
project(guesthouse_backend)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Download and build Crow automatically
include(FetchContent)
FetchContent_Declare(
  crow
  GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
  GIT_TAG        v1.0+3
)
FetchContent_MakeAvailable(crow)

# Find required packages
find_package(PostgreSQL REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

# Include directories
include_directories(
  ${PostgreSQL_INCLUDE_DIRS}
  ${OPENSSL_INCLUDE_DIR}
  ${PQXX_INCLUDE_DIRS}
)

# Link directories
link_directories(${PQXX_LIBRARY_DIRS})

# Add executable
add_executable(${PROJECT_NAME}
  main.cpp
  models/Room/Room.cpp
  models/Rental/Rental.cpp
  repositories/Room/RoomRepository.cpp
  repositories/Rental/RentalRepository.cpp
  utils/Database.cpp
)

# Link libraries
target_link_libraries(${PROJECT_NAME}
  PRIVATE Crow::Crow
  PRIVATE ${PostgreSQL_LIBRARIES}
  PRIVATE ${PQXX_LIBRARIES}
  PRIVATE OpenSSL::SSL
)
