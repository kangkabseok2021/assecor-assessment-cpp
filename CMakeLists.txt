cmake_minimum_required(VERSION 3.10)
project(LibraryCustomer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Source files
set(SOURCES
    src/customer.cpp
    main.cpp
)

# Create executable
add_executable(CustomerData ${SOURCES})
