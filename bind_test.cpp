#include <iostream>
#include <type_traits>
#include <functional>

int foo(int a, int c, std::string& s) {
    std::cout << a << c << s << std::endl;
    return 1;
}

int main() {
    int i = 2;
    auto l = [=](int& j) -> int {return i + ++j;};
    auto b = std::bind(l, std::ref(i));
    b();
    std::cout << "i:" << i << std::endl;
    return 0;
    std::string a;
}
