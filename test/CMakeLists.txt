# Create executable
add_executable(customer_unit_tests CustomerTest.cpp)

target_link_libraries(customer_unit_tests 
    customer_lib
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(customer_unit_tests)
