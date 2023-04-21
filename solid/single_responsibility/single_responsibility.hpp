#ifndef SINGLE_RESPONSIBILITY_HPP
#define SINGLE_RESPONSIBILITY_HPP
#include <iostream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <cstdio>
#include <fstream>

struct Journal {
    std::string _title;
    std::vector<std::string> _entries;
    Journal(const std::string title) : _title{title} {}

    void add_entry(const std::string entry) {
        static int count = 1;
        _entries.push_back(count + ": " + entry);
        _entries.push_back(boost::lexical_cast<std::string>(count++) + ": " + entry);
    }

    //not to be here... this api doen't relate to these structure.
    //void save(const std::string filename) {
    //    ofstream ofs(filename);
    //    for(const auto& e : entries)
    //        ofs << e << '\n';
    //}
};

struct PersistanceManager {
    static void save(const Journal& journal, const std::string filename) {
        std::ofstream ofs(filename);
        for(const auto& e : journal._entries)
            ofs << e << '\n';
    }
};

namespace SINGLE_RESPONSIBILITY {
static void test(void) {
    Journal journal("Dear Diary");
    journal.add_entry("I ate a bug.");
    journal.add_entry("I cried today");

    PersistanceManager pm;
    pm.save(journal, "Diary_Single_responsibility.txt");
    std::cout << "Diary_Single_responsibility.txt SAVED\n";
    set_exit_value(0);
}
}


#endif // SINGLE_RESPONSIBILITY_HPP
