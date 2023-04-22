#ifndef SINGLETONE_HPP
#define SINGLETONE_HPP
#include <map>
#include <string>
#include <fstream>
#include <boost/lexical_cast.hpp>

class SingletonDatabase {
    SingletonDatabase() {
        std::cout << "Initializing database\n";
        std::ifstream ifs("/capitals.txt");
        std::string s, s2;
        while(getline(ifs, s)) {
            getline(ifs, s2);
            int pop = boost::lexical_cast<int>(s2);
            capitals[s] = pop;
        }
    }
    std::map<std::string, int> capitals;
public:
     SingletonDatabase(SingletonDatabase const&) = delete;
     SingletonDatabase operator=(SingletonDatabase const&) = delete;

     static SingletonDatabase& get() {
         static SingletonDatabase db;
         return db;
     }
     int get_population(const std::string& name) {
         return capitals[name];
     }

};

namespace SINGLETON {
static void test(void) {
    std:: cout << SingletonDatabase::get().get_population("Tokyo") << '\n';
    set_exit_value(0);
}
}

#endif // SINGLETONE_HPP
