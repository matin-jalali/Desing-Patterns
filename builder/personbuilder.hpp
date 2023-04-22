#pragma once
#ifndef PERSONBUILDER_HPP
#define PERSONBUILDER_HPP
#include "person.hpp"

class PersonAddressBuilder;
class PersonJobBuilder;
class PersonBuilderBase {
protected:
    Person& person;
    explicit PersonBuilderBase(Person& person)
        : person{person} {}

public:
    operator Person() const {
        return std::move(person);
    }

    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;

};

class PersonBuilder : public PersonBuilderBase {
    Person p;
public:
    explicit PersonBuilder()
        : PersonBuilderBase {p} {}
};

#endif // PERSONBUILDER_HPP
