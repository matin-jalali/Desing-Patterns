#pragma once
#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include <string>

namespace builder {
class PersonBuilder;
class Person {
    // address
    std::string street_address, city, post_code, no;
    // employment
    std::string company_name, position;
    int annual_income = 0;
    explicit Person() { std::cout << "Created!\n"; };
public:
    ~Person() { std::cout << "Destroyed!\n"; }

    static PersonBuilder create();

    Person(Person&& other)
      : street_address{move(other.street_address)},
        post_code{move(other.post_code)},
        city{move(other.city)},
        company_name{move(other.company_name)},
        position{move(other.position)},
        annual_income{other.annual_income}
    {
    }

    Person& operator=(Person&& other)
    {
      if (this == &other)
        return *this;
      street_address = move(other.street_address);
      post_code = move(other.post_code);
      city = move(other.city);
      company_name = move(other.company_name);
      position = move(other.position);
      annual_income = other.annual_income;
      return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& obj)
    {
      return os
        << "street_address: " << obj.street_address
        << " post_code: " << obj.post_code
        << " city: " << obj.city
        << " company_name: " << obj.company_name
        << " position: " << obj.position
        << " annual_income: " << obj.annual_income;
    }

    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;
};
}

namespace BUILDER {
static void test(void) {
//    builder::Person p = builder::Person::create()
//      .lives().at("123 London Road").with_postcode("SW1 1GB").in("London")
//      .works().at("PragmaSoft").as_a("Consultant").earning(10e6);
}
}

#endif // PERSON_HPP
