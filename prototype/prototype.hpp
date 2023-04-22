#ifndef PROTOTYPE_HPP
#define PROTOTYPE_HPP
#include <string>
#include <ostream>

struct Address {
    std::string street, city;
    int suit;

    Address(const Address& address)
        : street { address.street }
        , city { address.city }
        , suit { address.suit }
    {}
    friend std::ostream &operator<<(std::ostream &os, const Address& address) {
        os << "Street: "
           << address.street
           << " City: "
           << address.city
           << " suit: "
           << suit;
        return os;
    }
};

struct Contact {
    std::string name;
    Address* address;

    Contact(const std::string& name, const Address& address)
        : name{name}, address { new Address {address} } {}//i know there is mem leak.

};

namespace PROTOTYPE {
static void test(void) {

    set_exit_value(0);
}
}



#endif // PROTOTYPE_HPP
