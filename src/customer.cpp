#include "customer.h"

// Customer Constructor
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
void CustomerArchive::addCustomer_(const Customer& customer) {
    if(checkExistID_(customer.getId())) {
        customers_.erase(customer.getId());
    }
    customers_.emplace(customer.getId(), customer);
};

// Method to add a customer to the archive
void CustomerArchive::addCustomer(const Customer& customer) {
    addCustomer_(customer);
};

// Checking existence of a given id
bool CustomerArchive::checkExistID_(int id) const {
    return customers_.count(id) > 0;
};

// Method to display all customers in the archive
void CustomerArchive::displayAllCustomers() {
    std::vector<Customer> customers = getCustomerAll_();
    if(customers.empty()) {
        std::cout << "(Keine Kunden)\n";
    }
    else { 
        for (const auto& customer : customers) {
            customer.displayInfo();
        }
    }
};

// Method to display a customer by ID
void CustomerArchive::displayCustomerById(int id) {
    if (checkExistID_(id)) {
        Customer customer = getCustomerById_(id);
        customer.displayInfo();
    } else {
        std::cout << "Customer with ID " << id << " not found.\n";
    }
};

// Method to input a new customer to the archive from user input
void CustomerArchive::displayCustomerById() {
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

// Method to input a new customer to the archive from user input
void CustomerArchive::addNewCustomer() {
    int id, color;
    std::string firstname, lastname, zip, city;
    std::cout << "\n=== Add Bew Customer ===" << std::endl;
    std::cout<< "Enter Customer ID (integer):";
    while(!(std::cin >> id)) {
        std::cout << "Invalid input. Please enter an integer ID: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //Check if ID already exists
    if(checkExistID_(id)) {
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
    while(!(std::cin >> color) || color < 1 || color > 7) {
        std::cout << "Invalid input. Please enter an integer 1 -- 7: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Customer customer(id, firstname, lastname, zip, city, color);
    
    addCustomer(customer);
};

// get Customer of a given id
Customer CustomerArchive::getCustomerById_(int id) const {
    return customers_.at(id);
};

// get all Customers
std::vector<Customer> CustomerArchive::getCustomerAll_() const{
    std::vector<Customer> customers;
    for(auto it:customers_) customers.push_back(it.second);
    return customers;
};

