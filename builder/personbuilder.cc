#include "personbuilder.hpp"
#include "personjobbuilder.hpp"
#include "personaddressbuilder.hpp"

PersonAddressBuilder PersonBuilderBase::lives() const
{
    return PersonAddressBuilder { person };
}

PersonJobBuilder PersonBuilderBase::works() const
{
    return PersonJobBuilder { person };
}
