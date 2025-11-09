#include "customer.h"

Customer::Customer(
    int id, const std::string& first_name, const std::string& last_name,
    const std::string& zip_code, const std::string& city, Color favorite_color)
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

void CustomerArchive::newCustomer() {
};
