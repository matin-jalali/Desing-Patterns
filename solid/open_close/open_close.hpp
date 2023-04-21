#ifndef OPEN_CLOSE_HPP
#define OPEN_CLOSE_HPP
#include <string>
#include <vector>

enum class Color {red, blue, green};
enum class Size {small, medium, large};

struct Product {
    std::string _name;
    Color _color;
    Size _size;
};

//!
//! \brief The ProductFilter struct this struct just filter by color,
//! to extend these struct we should modify it.
//! OC from solid design pattern in c++ try to open to extention and close to modification.
//!
//struct ProductFilter {
//    std::vector<Product*> by_color(const std::vector<Product*>& items, const Color color) {
//        std::vector<Product*> result;
//        for(const auto& item : items)
//            if(color == item->_color)
//                result.push_back(item);
//        return result;
//    }
//};

template<typename T>
struct AndSpecification;

template<typename T>
struct Specification {
    virtual bool is_specified(T* item) = 0;
    AndSpecification<T> operator&&(Specification<T>&& other) {
        return AndSpecification<T>(*this, other);
    }
};

template<typename T>
struct Filter {
    virtual std::vector<T*> filter(const std::vector<T*>& items, Specification<T>& spec) = 0;
};

struct BetterFilter : public Filter<Product> {
    std::vector<Product*> filter(const std::vector<Product*>& items, Specification<Product>& spec) override {
        std::vector<Product*> result;
        for(auto& item : items)
            if(spec.is_specified(item))
                result.push_back(item);
        return result;
    }
};

struct ColorSpecification : public Specification<Product> {
    Color _color;
    explicit ColorSpecification(const Color color) : _color{color} {}
    bool is_specified(Product* item) override {
        return _color == item->_color;
    }
};

struct SizeSpecification : public Specification<Product> {
    Size _size;
    explicit SizeSpecification(const Size size) : _size{size} {}
    bool is_specified(Product* item) override {
        return _size == item->_size;
    }
};

template<typename T>
struct AndSpecification : Specification<T> {
    Specification<T>& firsts;
    Specification<T>& seconds;
    AndSpecification(Specification<T>& _first, Specification<T>& _second)
        : firsts (_first),
          seconds (_second) { }
    bool is_specified(T *item) override {
        return firsts.is_specified(item) && seconds.is_specified(item);
    }
};

namespace OPEN_CLOSE {
static void test(void) {
    Product apple {"Apple", Color::green, Size::small};
    Product tree {"Tree", Color::green, Size::large};
    Product house {"House", Color::blue, Size::large};
    std::vector<Product*> items {&apple, &tree, &house};
    //ProductFilter pf;
    //const auto green_things = pf.by_color(items, Color::green);
    //for(const auto& item : green_things)
    //    std::cout << item->_name << '\n';

    //
    ColorSpecification color_spec(Color::green);
    SizeSpecification size_spec(Size::large);
    AndSpecification<Product> green_and_large_spec(color_spec, size_spec);
    //should work in operator&&
    BetterFilter bf;
    for(auto& item : bf.filter(items, green_and_large_spec) )
        std::cout << item->_name << '\n';
    set_exit_value(0);
}
}

#endif // OPEN_CLOSE_HPP
