#include <iostream>
#include <string>

class Person {
public:
    Person() : name(""), age(0) {}

    // Overload the extraction operator
    friend std::istream& operator>>(std::istream& is, Person& person);

    // Overload the insertion operator for output
    friend std::ostream& operator<<(std::ostream& os, const Person& person);

private:
    std::string name;
    int age;
};

// Define the overloaded extraction operator
std::istream& operator>>(std::istream& is, Person& person) {
    std::cout << "Enter name: ";
    is >> person.name;
    std::cout << "Enter age: ";
    is >> person.age;
    return is;
}

// Define the overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "Name: " << person.name << ", Age: " << person.age;
    return os;
}

int main() {
    Person person;
    std::cin >> person;  // Input: Enter name: Bob, Enter age: 25
    std::cout << person << std::endl;  // Output: Name: Bob, Age: 25
    return 0;
}

//In this example, the >> operator is overloaded to input a Person object. 
//The friend keyword is used to allow the operator>> function to access the private members of the Person class.
