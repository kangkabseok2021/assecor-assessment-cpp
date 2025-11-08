include "customer.h"
Customer::Customer(int id, const std::string& first_name, const std::string& last_name,
                   const std::string& zip_code, const std::string& city, Color favorite_color)
    : id_(id), first_name_(first_name), last_name_(last_name),
      zip_code_(zip_code), city_(city), favorite_color_(favorite_color) {}  
      