#ifndef LISKOV_HPP
#define LISKOV_HPP
#include <string>

class Rectangle {
protected:
    int _width = 0, _height = 0;
public:
    Rectangle(int width, int height)
        : _width(width), _height(height) {}
    virtual void set_width(int width) {
        Rectangle::_width = width;
    }
    virtual void set_height(int height) {
        Rectangle::_height = height;
    }
    int get_width() const {
        return Rectangle::_width;
    }
    int get_height() const {
        return Rectangle::_height;
    }
    int area(void) {
        return _width * _height;
    }
};

class Square : public Rectangle {
public:
    Square(int size) : Rectangle(size, size) {}
    void set_width(int width) override {
        this->_width = this->_height = width;
    }
    void set_height(int height) override {
        this->_width = this->_height = height;
    }
};

void process(Rectangle& r) {
    int w = r.get_width();
    r.set_height(10);
    std::cout << "we except for area: " << (w*10)
              << " real area: " << r.area() << '\n';
}

struct RectangleFactory {
    static Rectangle create_rectangle(int w, int h) { return Rectangle(w,h); }
    static Rectangle create_square(int size) { return Rectangle(size, size); }
};

namespace LISKOV {
static void test(void) {
    //Rectangle rect(3,4);
    //process(rect);
    //Square sqr(5);
    //process(sqr);

    auto rect = RectangleFactory::create_rectangle(3,4);
    auto sqr = RectangleFactory::create_square(5);
    process(rect);
    process(sqr);

    set_exit_value(0);
}
}


#endif // LISKOV_HPP
