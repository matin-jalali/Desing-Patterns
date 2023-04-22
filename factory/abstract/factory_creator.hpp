#ifndef FACTORY_CREATOR_HPP
#define FACTORY_CREATOR_HPP
#include <memory>
#include <string>
#include <map>
#include "HotDrinkFactory.hpp"

std::unique_ptr<HotDrink> make_drink(std::string type) {
    std::unique_ptr<HotDrink> drink;
    if("tea" == type) {
        drink = std::make_unique<Tea>();
        drink->prepare(200);
    } else if ("coffee" == type) {
        drink = std::make_unique<Coffee>();
        drink->prepare(50);
    } else { /*...*/ }

    return drink;
}

class DrinkFactory {
    std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_factories;
public:
    DrinkFactory() {
        hot_factories["coffee"] = std::make_unique<CoffeeFactory>();
        hot_factories["tea"] = std::make_unique<TeaFactory>();
    }

    std::unique_ptr<HotDrink> make_drink(std::string type) {
        auto drink = hot_factories[type]->make();
        return drink;
    }
};


namespace ABSTRACT_FACTORY {
static void test(void) {
    auto d = make_drink("tea");
    DrinkFactory df;
    auto c = df.make_drink("coffee");
}
}


#endif // FACTORY_CREATOR_HPP
