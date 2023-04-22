#pragma once
#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include <string>

class PersonBuilder;
class Person {
    // address
    std::string street_address, city, alley_address, no;
    // employment
    std::string company_name, position;
    int annual_incomming = 0;
    explicit Person() { std::cout << "Created!\n"; };
public:
    ~Person() { std::cout << "Destroyed!\n"; }

    static PersonBuilder create();

    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;
};

//namespace BUILDER {
//static void test(void) {


//    set_exit_value(0);
//}
//}

#endif // PERSON_HPP
