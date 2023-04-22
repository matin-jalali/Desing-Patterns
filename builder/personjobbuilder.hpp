#pragma once
#ifndef PERSONJOBBUILDER_HPP
#define PERSONJOBBUILDER_HPP
#include "personbuilder.hpp"

namespace builder {
class PersonJobBuilder : PersonBuilderBase {
    typedef PersonJobBuilder Self;
public:
    explicit PersonJobBuilder(Person& person)
        : PersonBuilderBase{person} {}
};
}

#endif // PERSONJOBBUILDER_HPP
