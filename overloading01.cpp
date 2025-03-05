#include <iostream>
#include <string>

class Person {
public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Overload the insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Person& person);

private:
    std::string name;
    int age;
};

// Define the overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "Name: " << person.name << ", Age: " << person.age;
    return os;
}

int main() {
    Person person("Alice", 30);
    std::cout << person << std::endl;  // Output: Name: Alice, Age: 30
    return 0;
}

//In this example, the << operator is overloaded to output a Person object in a specific format. 
//The friend keyword is used to allow the operator<< function to access the private members of the Person class.
