#include "gtest/gtest.h"
#include "customer.h"
#include <functional>
#include <sstream>

// Helper function to capture stdout for testing displayInfo()
std::string CaptureStdout(std::function<void()> func) {
    std::stringstream ss;
    
    std::streambuf* old_cout = std::cout.rdbuf();
    
    std::cout.rdbuf(ss.rdbuf());

    func();

    std::cout.rdbuf(old_cout);
    return ss.str();
}

namespace {
    
class CustomerTest : public ::testing::Test {
protected:
    // Setup initial data used in tests
    const int kId = 101;
    const std::string kFirstName = "Alice";
    const std::string kLastName = "Smith";
    const std::string kZipCode = "12345";
    const std::string kCity = "Testville";
    const int kColor = COLOR_BLUE;

    Customer customer_full_{kId, kFirstName, kLastName, kZipCode, kCity, kColor};
};

// Test 1: Full Constructor and Getters
TEST_F(CustomerTest, FullConstructorAndGetters) {
    EXPECT_EQ(customer_full_.getId(), kId);
    EXPECT_EQ(customer_full_.getFirstName(), kFirstName);
    EXPECT_EQ(customer_full_.getLastName(), kLastName);
    EXPECT_EQ(customer_full_.getZipCode(), kZipCode);
    EXPECT_EQ(customer_full_.getCity(), kCity);
    EXPECT_EQ(customer_full_.getFavoriteColor(), kColor);
}

// Test 2: Default Constructor and Getters
TEST_F(CustomerTest, DefaultConstructorAndGetters) {
    Customer customer_default;
    EXPECT_EQ(customer_default.getId(), 0);
    EXPECT_TRUE(customer_default.getFirstName().empty());
    EXPECT_TRUE(customer_default.getLastName().empty());
    EXPECT_TRUE(customer_default.getZipCode().empty());
    EXPECT_TRUE(customer_default.getCity().empty());
    EXPECT_EQ(customer_default.getFavoriteColor(), COLOR_WHITE);
}

// Test 3: displayInfo() Output
TEST_F(CustomerTest, DisplayInfoOutput) {
    std::string expected_output = "Smith, Alice, 12345 Testville, Blue\n"; 

    std::string captured_output = CaptureStdout([this]() {
        customer_full_.displayInfo();
    });

    EXPECT_EQ(captured_output, expected_output);
}

} // namespace

namespace {

// Test Fixture for CustomerArchive
class CustomerArchiveTest : public ::testing::Test {
protected:
    CustomerArchive archive_;
    
    // Sample customers
    const Customer cust1_{1, "Bob", "Client", "54321", "CityA", COLOR_RED};
    const Customer cust2_{2, "Charlie", "User", "98765", "CityB", COLOR_GREEN};

    void SetUp() override {
        archive_.addCustomer(cust1_);
        archive_.addCustomer(cust2_);
    }
};

// Test 4: addCustomer - Insertion and Count Check
TEST_F(CustomerArchiveTest, AddCustomerSuccess) {
    // Try adding a new customer
    Customer cust3{3, "Eve", "New", "11111", "CityC", COLOR_YELLOW};
    archive_.addCustomer(cust3);
    
   std::string captured_output = CaptureStdout([this]() {
        archive_.displayCustomerById(3);
    });
    EXPECT_NE(captured_output.find("New, Eve"), std::string::npos);
}

// Test 5: addCustomer - Duplicate ID Check (Ensure the new one *replaces* the old one or is ignored)
TEST_F(CustomerArchiveTest, AddCustomerDuplicateId) {
    
    // New customer with the same ID
    Customer cust_duplicate{1, "NewName", "NewLastName", "00000", "NewCity", COLOR_VIOLET};
    archive_.addCustomer(cust_duplicate); // Should replace cust1_
    
    std::string captured_output = CaptureStdout([this]() {
        archive_.displayCustomerById(1);
    });
    
    // Check for the new name and color in the output
    EXPECT_NE(captured_output.find("NewLastName, NewName"), std::string::npos);
    EXPECT_NE(captured_output.find("Violet"), std::string::npos);
}

// Test 6: displayCustomerById - Found Customer
TEST_F(CustomerArchiveTest, DisplayCustomerByIdFound) {
    // cust2_ is ID 2
    std::string captured_output = CaptureStdout([this]() {
        archive_.displayCustomerById(2);
    });
    
    // Check for unique identifier of cust2
    EXPECT_NE(captured_output.find("User, Charlie"), std::string::npos);
    EXPECT_NE(captured_output.find("98765 CityB"), std::string::npos);
}

// Test 7: displayCustomerById - Not Found Customer
TEST_F(CustomerArchiveTest, DisplayCustomerByIdNotFound) {
    int non_existent_id = 999;
    std::string captured_output = CaptureStdout([this, non_existent_id]() {
        archive_.displayCustomerById(non_existent_id);
    });
    
    // Check that the output indicates the customer was not found (assuming the implementation handles this)
    // Adjust the EXPECT based on what your displayCustomerById prints when ID is not found.
    // Assuming it prints an error message or "Customer not found."
    EXPECT_NE(captured_output.find("not found"), std::string::npos); 
}

// Test 8: displayAllCustomers - Multiple Customers
TEST_F(CustomerArchiveTest, DisplayAllCustomersMultiple) {
    std::string captured_output = CaptureStdout([this]() {
        archive_.displayAllCustomers();
    });
    
    // Check that both customers' unique names are present in the output
    EXPECT_NE(captured_output.find("Client, Bob"), std::string::npos);
    EXPECT_NE(captured_output.find("User, Charlie"), std::string::npos);
}

// Test 9: displayAllCustomers - Empty Archive
TEST_F(CustomerArchiveTest, DisplayAllCustomersEmpty) {
    CustomerArchive empty_archive; // New, empty archive

    std::string captured_output = CaptureStdout([&empty_archive]() {
        empty_archive.displayAllCustomers();
    });
    
    EXPECT_TRUE(captured_output.find("Keine Kunden") != std::string::npos);
}

} // namespace