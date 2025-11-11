cmake_minimum_required(VERSION 3.10)
project(LibraryCustomer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# find_package(GTest REQUIRED) # For GoogleTest

add_library(customer_lib
    src/customer.cpp
)

target_include_directories(
    customer_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
# Source files
set(SOURCES main.cpp)

# Create executable
add_executable(CustomerData ${SOURCES})

target_link_libraries(CustomerData customer_lib)

# enable_testing()  # For GoogleTest

# add_subdirectory(test) # For GoogleTest
