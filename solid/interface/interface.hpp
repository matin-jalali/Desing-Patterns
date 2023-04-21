#ifndef INTERFACE_HPP
#define INTERFACE_HPP

struct Document;
/*not efficient*/
//struct IMachine {
//    virtual void print(Document& doc) = 0;
//    virtual void scan(Document& doc) = 0;
//    virtual void fax(Document& doc) = 0;
//};

//struct Printer : IMachine {
//    void print(Document &doc) override {/*ok*/}
//    void scan(Document &doc) override {/*...*/}
//    void fax(Document &doc) override {/*...*/}
//};
//struct scanner : IMachine {
//    void print(Document &doc) override {/*...*/}
//    void scan(Document &doc) override {/*ok*/}
//    void fax(Document &doc) override {/*...*/}
//};

struct IScan {
    virtual void scan(Document &doc) = 0;
};

struct IPrinter {
    virtual void print(Document &doc) = 0;
};

struct IMachine : public IPrinter, IScan {};
struct Machine : public IMachine {
    // IScan interface
public:
    void scan(Document &doc) override {/*ok*/}
    // IPrinter interface
public:
    void print(Document &doc) override {/*ok*/}
};



namespace INTERFACE {
static void test(void) {
    std::cout << "Interface Segregation Principle.\n";
    set_exit_value(0);
}
}

#endif // INTERFACE_HPP
