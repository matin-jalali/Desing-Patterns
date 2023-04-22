#ifndef DEPENDENCY_HPP
#define DEPENDENCY_HPP
#include <string>
#include <vector>
#include <tuple>

struct Person {
    std::string name;
};

enum class Relations {
    parent, child, sibling
};

struct RelationShipBrowser {
    virtual std::vector<Person> find_all_childer_of(std::string name) = 0;
};

struct RelationShip : public RelationShipBrowser { // low level module
    std::vector<std::tuple<Person, Relations, Person>> relations;
    void add_parent_and_child(const Person& parent, const Person& child) {
        relations.push_back({parent, Relations::parent, child});
        relations.push_back({child, Relations::child, parent});
    }

public:
    std::vector<Person> find_all_childer_of(std::string name) override {
        std::vector<Person>result;
        for(auto&& [first, rel, second] : relations)
            if(first.name == name && rel == Relations::parent)
                result.push_back(second);
        return result;
    }
};

struct Research { // high level module
    // in this situation i pass low level module to hight level module and create dependency...(NOT SOLID)
    //Research(RelationShip& relationships) {
    //    auto relations = relationships.relations;
    //    for(auto&& [first, rel, second] : relations)
    //        if(first.name == "John" && rel == Relations::parent)
    //            std::cout << "John is parent: " << second.name << '\n';
    //}

    Research(RelationShipBrowser& browser) {
        for(auto& child : browser.find_all_childer_of("John"))
           std::cout << "John's child: " << child.name << '\n';
    }

};



namespace DEPENDENCY {
static void test(void) {
    Person parent{"John"};
    Person child1{"cris"}, child2{"matt"};
    RelationShip rs;
    rs.add_parent_and_child(parent, child1);
    rs.add_parent_and_child(parent, child2);

    Research _(rs);


    set_exit_value(0);
}
}


#endif // DEPENDENCY_HPP
