#include "customer.h"
#include <iostream>

int main() {
    std::cout << "=== Testing Customer Archive ===" << std::endl;

    CustomerArchive archive;

    // Create some test customers
    Customer customer1(1, "John", "Doe", "12345", "New York", COLOR_BLUE);
    Customer customer2(2, "Jane", "Smith", "67890", "Los Angeles", COLOR_GREEN);

    // Add customers to the archive
    archive.addCustomer(customer1);
    archive.addCustomer(customer2);

    // Display all customers
    // archive.displayAllCustomers();

    // Display a specific customer by ID
    //  archive.displayCustomerById(1);
    // archive.displayCustomerById(3);  // Non-existent ID
    
    //  archive.addNewCustomer();
    //  archive.displayAllCustomers();

    int choice;

    do {
        std::cout << "\n\n=== Customer Archive Menu ===" << std::endl;
        std::cout << "1. Add a new customer" << std::endl;
        std::cout << "2. Print customer data for a given ID" << std::endl;
        std::cout << "3. Print the list of all customers" << std::endl;
        std::cout << "0. Exit application" << std::endl;
        std::cout << "Enter your choice ";

        while(!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number (0-3). " << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice) {
            case 1:
                archive.addNewCustomer();
                break;
            case 2:
                archive.displayCustomerById();
                break;
            case 3:
                archive.displayAllCustomers();
                break;
            case 0:
                std::cout << "\nApplication exting. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please select a number from the menu." << std::endl;
                break;
        }
    } while(choice != 0);

    return 0;
}       
