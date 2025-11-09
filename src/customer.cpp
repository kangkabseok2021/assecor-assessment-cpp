#include "customer.h"

Customer::Customer(
    int id, const std::string& first_name, const std::string& last_name,
    const std::string& zip_code, const std::string& city, int favorite_color)
: id_(id), first_name_(first_name), last_name_(last_name),
    zip_code_(zip_code), city_(city), favorite_color_(favorite_color) {};  

// Method to display customer information
void Customer::displayInfo() const {
    std::cout << last_name_ << ", " << first_name_ << ", " << zip_code_ <<" "<< city_ << ", "
              << ColorNames.at(favorite_color_) << "\n";
};

// Method to add a customer to the archive
void CustomerArchive::addCustomer(const Customer& customer) {
    customers_[customer.getId()] = customer;
};

// Method to display all customers in the archive
void CustomerArchive::displayAllCustomers() const {
    if(customers_.empty()) {
        std::cout << "(Keine Kunden)\n";
    }
    else { 
        for (const auto& customer : customers_) {
            customer.second.displayInfo();
        }
    }
};

void CustomerArchive::displayCustomerById(int id) const {
    auto it = customers_.find(id);
    if (it != customers_.end()) {
        it->second.displayInfo();
    } else {
        std::cout << "Customer with ID " << id << " not found.\n";
    }
};

void CustomerArchive::displayCustomerById() const {
    int id;
    std::cout<< "Enter Customer ID (integer):";
    while(!(std::cin >> id)) {
        std::cout << "Invalid input. Please enter an integer ID: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    displayCustomerById(id);
};

void CustomerArchive::addNewCustomer() {
    int id, color;
    std::string firstname, lastname, zip, city;
    std::cout << "\n=== Add Bew Customer ===" << std::endl;
    std::cout<< "Enter Customer ID (integer):";
    //std::cin >> id;
    while(!(std::cin >> id)) {
        std::cout << "Invalid input. Please enter an integer ID: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //Check if ID already exists
    if(customers_.count(id)) {
        std::cout << "Error: Customer with ID : "<< id << " already exists. Aborting. \n";
        return;
    }
    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstname);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastname);
    std::cout << "Enter Zip Code: ";
    std::getline(std::cin, zip);
    std::cout << "Enter City: ";
    std::getline(std::cin, city);

    std::cout << "Enter Favorite Color Code (1: Blue, 2: GREEN, 3: VIOLET, 4: RED, ";
    std::cout << "5: YELLOW, 6: TURQUOISE, 7: WHITE) :";
    //std::cin >> color;
    while(!(std::cin >> color)) {
        std::cout << "Invalid input. Please enter an integer 1 -- 7: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Customer customer(id, firstname, lastname, zip, city, color);
    
    addCustomer(customer);
};
