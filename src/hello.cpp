#include <iostream>

namespace cl {   

void hello() {
    std::cout << "hello cpp-learning" << "\n";
}

} // namespace cl

int main() {
    cl::hello();
    return 0;
}
