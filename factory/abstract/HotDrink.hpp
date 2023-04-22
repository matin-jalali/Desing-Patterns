#pragma once
#ifndef HOTDRINK_HPP
#define HOTDRINK_HPP
#include <iostream>

struct HotDrink {
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink {
    void prepare(int volume) override {
        std::cout << "Take tea bag, boil water, pour " << volume
                  << "ml, add some lemon\n";
    }
};

struct Coffee : HotDrink {
    void prepare(int volume) override {
        std::cout << "Frind some beans, boil water, pour " << volume
                  << "ml, add some cream, enjoy\n";
    }
};


#endif // HOTDRINK_HPP
