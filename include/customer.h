#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include <map>


#define	COLOR_BLUE      1
#define COLOR_GREEN     2
#define COLOR_VIOLET    3
#define COLOR_RED       4
#define COLOR_YELLOW    5
#define COLOR_TURQUOISE 6
#define COLOR_WHITE     7

struct _CUSTOMER {
    int id;
    char first_name[24];
    char last_name[32];
    char zip_code[8];
    char city[32];
    int favorite_color;
};

typedef struct _CUSTOMER CUSTOMER;

enum class Color {
    BLUE = 1,
    GREEN = 2,
    VIOLET = 3,
    RED = 4,
    YELLOW = 5,
    TURQUOISE = 6,
    WHITE = 7
};

const std::map<Color, std::string> ColorNames = {
    {Color::BLUE, "Blue"},
    {Color::GREEN, "Green"},
    {Color::VIOLET, "Violet"},
    {Color::RED, "Red"},
    {Color::YELLOW, "Yellow"},
    {Color::TURQUOISE, "Turquoise"},
    {Color::WHITE, "White"}
};

class Customer {
private:
    // Member variable (data fields) 
    int id_;
    std::string first_name_;
    std::string last_name_; 
    std::string zip_code_;
    std::string city_;
    Color favorite_color_;

public:
    // Constructor
    Customer(int id, const std::string& first_name, const std::string& last_name,
             const std::string& zip_code, const std::string& city, Color favorite_color);

    // Default Constructor
    Customer() : id_(0), first_name_(""), last_name_(""),
                 zip_code_(""), city_(""), favorite_color_(Color::WHITE) {}
    
    // Getter methods
    int getId() const { return id_; }
    std::string getFirstName() const { return first_name_; }
    std::string getLastName() const { return last_name_; }
    std::string getZipCode() const { return zip_code_; }
    std::string getCity() const { return city_; }
    Color getFavoriteColor() const { return favorite_color_; }

    // Method to display customer information
    void displayInfo() const;
};

class CustomerArchive { 
private:
    std::map<int, Customer> customers_;
public:
    // Method to add a customer to the archive
    void addCustomer(const Customer& customer);
    // Method to input a new customer to the archive
    void newCustomer();
    // Method to display all customers in the archive
    void displayAllCustomers() const;
    // Method to display a customer by ID
    void displayCustomerById(int id) const;
};

#endif // ifndef CUSTOMER_H
