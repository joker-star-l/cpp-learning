#include <iostream>
#include <gtest/gtest.h>
 #include <folly/Poly.h>

class PolyTest : public testing::Test {
};

struct IDrawable {
    template <class Base>
    struct Interface : Base {
        void draw(std::ostream& out) const { folly::poly_call<0>(*this, out); };
    };
    
    template<class T> 
    using Members = folly::PolyMembers<&T::draw>;
};

using Drawable = folly::Poly<IDrawable>;

struct Square {
    void draw(std::ostream& out) const { out << "Square\n"; }
};

struct Circle {
    void draw(std::ostream& out) const { out << "Circle\n"; }
};

void f(const Drawable& d) {
    d.draw(std::cout);
}

TEST_F(PolyTest, basic) {
    f(Square());
    f(Circle());
}
