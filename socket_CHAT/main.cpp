#include <iostream>
#include <boost/json.hpp>

namespace json = boost::json;

int main() {
    // Creating a JSON object
    json::object obj;
    obj["name"] = "John";
    obj["age"] = 30;
    obj["is_student"] = false;

    // Creating a JSON array
    json::array arr;
    arr.push_back("apple");
    arr.push_back("banana");
    arr.push_back("cherry");
    obj["fruits"] = arr;

    // Converting JSON object to string
    std::string json_str = json::serialize(obj);
    std::cout << "Serialized JSON: " << json_str << std::endl;

    // Parsing JSON string to object
    json::value parsed_value = json::parse(json_str);
    json::object parsed_obj = parsed_value.as_object();

    // Accessing values
    std::string name = parsed_obj["name"].as_string().c_str();
    int age = parsed_obj["age"].as_int64();
    bool is_student = parsed_obj["is_student"].as_bool();
    json::array fruits = parsed_obj["fruits"].as_array();

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Is student: " << (is_student ? "true" : "false") << std::endl;
    std::cout << "Fruits: ";
    for (const auto& fruit : fruits) {
        std::cout << fruit.as_string().c_str() << " ";
    }
    std::cout << std::endl;
    system("pause");

    return 0;
}