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
};
}

#endif // PERSONADDRESSBUILDER_HPP
