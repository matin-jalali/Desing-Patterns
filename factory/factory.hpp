#ifndef FACTORY_HPP
#define FACTORY_HPP
#include <cmath>
#include <ostream>
//!
//! \brief The Point class to create point with types {cartesian, polar} you can just
//! use parameter in constructor's argument, and use if then else to initialize the x,y values.
//! or use these factory design pattern.
//!
class Point {
    //    friend class PointFactory;
public:
    Point(float x, float y) : x(x), y(y) {}
    float x, y;

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "X: " << point.x << " y: " << point.y;
        return os;
    }

    // a way to impl factory:
    //static Point NewCartesian(float x, float y) { return {x, y}; }
    //static Point NewPolar(float r, float theta) { return { r*std::cos(theta), r*std::sin(theta); } }


    //also we can use singletone
    //    class PointFactory;
    //    static PointFactory Factory;
    //private:
    //!
    //! \brief The PointFactory struct : its not good, since i've got private constructor.
    //! and also i've friend pointfactory struct that quash the OCP in solid design pattern
    //!
    class PointFactory {//its inner factory.
        PointFactory() {}
    public:
        static Point NewCartesian(float x, float y) { return {x,y}; }
        static Point NewPolar(float r, float theta) {
            return {r*std::cos(theta),r*std::sin(theta)};
        }
    };

};

namespace FACTORY {
static void test(void) {
    auto cartesian = Point::PointFactory::NewCartesian(3,4);
    auto polar = Point::PointFactory::NewPolar(5,6);
    //    auto cartesian = Point::Factory.NewCartesian(3,4);
    //    auto polar = Point::Factory.NewPolar(5,6);
    std::cout << "cartesian: " << cartesian << '\n' << "polar: " << polar << '\n';
    set_exit_value(0);
}
}


#endif // FACTORY_HPP
