#include "customer.h"
#include <iostream>

int main() {
    std::cout << "=== Testing Customer Archive ===" << std::endl;

    CustomerArchive archive;

    // Create some test customers
    Customer customer1(1, "John", "Doe", "12345", "New York", Color::BLUE);
    Customer customer2(2, "Jane", "Smith", "67890", "Los Angeles", Color::GREEN);

    // Add customers to the archive
    archive.addCustomer(customer1);
    archive.addCustomer(customer2);

    // Display all customers
    archive.displayAllCustomers();

    // Display a specific customer by ID
    archive.displayCustomerById(1);
    archive.displayCustomerById(3);  // Non-existent ID

    return 0;
}       
