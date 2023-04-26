#ifndef GEOMETRIC_SHAPE_HPP
#define GEOMETRIC_SHAPE_HPP
#include <iostream>
#include <string>
#include <vector>

struct GraphicObject {
    virtual void draw() = 0;
};

struct Circles : GraphicObject {
    void draw() override
    {
        std::cout << "Circle\n"; }
};

struct Group : GraphicObject {
    std::string name;
    std::vector<GraphicObject*> objects;
    Group(const std::string& name) : name(name) {}

    void draw() override {
        std::cout << "Grp: " << name.c_str() << "\tcontains: \n";
        for(auto&& o : objects)
            o->draw();
    }
};



namespace GEOMETRIC_SHAPE {
static void test(void) {

    Group root("root");
    Circles c1, c2;
    root.objects.push_back(&c1);

    Group submodule("submodule");
    Circles c3;
    submodule.objects.push_back(&c3);
    root.objects.push_back(&submodule);
    root.draw();

    set_exit_value(0);
}
};

#endif // GEOMETRIC_SHAPE_HPP
