#include "person.hpp"
#include "personbuilder.hpp"

namespace builder {
PersonBuilder Person::create()
{
    return PersonBuilder {};
}
}
