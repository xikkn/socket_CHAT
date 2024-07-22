#include <boost/json.hpp>
#include <iostream>

namespace json = boost::json;

int main() {
    // Sample JSON string
    std::string json_str = R"({
        "name": "John Doe",
        "age": 30,
        "address": {
            "street": "123 Main St",
            "city": "Anytown"
        },
        "phone_numbers": [
            "123-456-7890",
            "987-654-3210"
        ]
    })";

    // Parse the JSON string into a Boost JSON value
    json::value jv = json::parse(json_str);

    // Access and print individual elements
    std::string name = jv.at("name").as_string().c_str();
    int age = jv.at("age").as_int64();

    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";

    // Modify the JSON object
    jv.as_object()["age"] = 31; // Update age
    jv.as_object()["address"].as_object()["city"] = "New City"; // Update city

    // Add a new field
    jv.as_object()["email"] = "john.doe@example.com";

    // Serialize the modified JSON object back to a string
    std::string updated_json_str = json::serialize(jv);

    std::cout << "Updated JSON: " << updated_json_str << "\n";

    return 0;
}