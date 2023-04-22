#include <iostream>
#define SEPERATOR std::cout << "******************\n"
int ext = 0;
void set_exit_value(int value) {
    SEPERATOR;
    ext = value;
}
#include "single_responsibility.hpp"
#include "solid/open_close/open_close.hpp"
#include "solid/liskov/liskov.hpp"
#include "solid/interface/interface.hpp"
#include "solid/dependency/dependency.hpp"
/*builder*/
//#include "builder/person.hpp"
//#include "builder/personbuilder.hpp"
//#include "builder/personjobbuilder.hpp"
//#include "builder/personaddressbuilder.hpp"

int main() {
    SINGLE_RESPONSIBILITY::test();
    OPEN_CLOSE::test();
    LISKOV::test();
    INTERFACE::test();
    DEPENDENCY::test();
//    BUILDER::test();
    return ext;
}
