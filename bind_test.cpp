#include <iostream>
#include <type_traits>
#include <functional>

int main() {
    int i = 2;
    auto l = [=](int& j) -> int {return i + ++j;};
    auto b = std::bind(l, std::ref(i));
    b();
    std::cout << "i:" << i << std::endl;
    return 0;
}
