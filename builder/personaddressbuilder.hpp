#pragma once
#ifndef PERSONADDRESSBUILDER_HPP
#define PERSONADDRESSBUILDER_HPP
#include "personbuilder.hpp"

namespace builder {
class PersonAddressBuilder : public PersonBuilderBase {
    typedef PersonAddressBuilder Self;
public:
    explicit PersonAddressBuilder(Person& person)
        : PersonBuilderBase{person} {};

    Self& at(std::string street_address)
    {
      person.street_address = street_address;
      return *this;
    }

    Self& with_postcode(std::string post_code)
    {
      person.post_code = post_code;
      return *this;
    }

    Self& in(std::string city)
    {
      person.city = city;
      return *this;
    }
};
}

#endif // PERSONADDRESSBUILDER_HPP
