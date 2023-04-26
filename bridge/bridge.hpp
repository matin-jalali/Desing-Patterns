#ifndef BRIDGE_HPP
#define BRIDGE_HPP
#include <iostream>

struct Renderer {
    virtual void render_circle(float x, float y, float radius) = 0;
};

struct VectorRenderer : Renderer {
    void render_circle(float x, float y, float radius) override {
        std::cout << "Rastering a circle of radius " << radius << '\n';
    }
};

struct RasterRenderer : Renderer {
    void render_circle(float x, float y, float radius) override {
        std::cout << "Drawing a circle of radius " << radius << '\n';
    }
};

struct Shape {
protected:
    Renderer& renderer;
    Shape(Renderer& renderer) : renderer(renderer) {}
public:
    virtual void draw() = 0;
    virtual void resize(float factor) = 0;
};

struct Circle : Shape {
private:
    float x,y,radius;
public:
    Circle(Renderer& renderer, float x, float y, float radius)
        : Shape(renderer)
        , x{x}
        , y{y}
        , radius{radius} {}
    void draw() override { renderer.render_circle(x,y,radius); }
    void resize(float factor) override { radius *= factor; }
};




namespace BRIDGE {
static void test(void) {

    RasterRenderer rr;
    Circle raster_circle{rr,5,5,5};
    raster_circle.resize(2);
    raster_circle.draw();

    set_exit_value(0);
}
}

#endif // BRIDGE_HPP
