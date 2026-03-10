#include "Fixed.hpp"

int main() {
    Fixed a(5.5f);
    Fixed b(29);

    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "a / b = " << a / b << std::endl;

    Fixed c = a;
    std::cout << "c = " << c << std::endl;
    std::cout << "++c = " << ++c << std::endl;
    std::cout << "c++ = " << c++ << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "--c = " << --c << std::endl;
    std::cout << "c-- = " << c-- << std::endl;
    std::cout << "c = " << c << std::endl;

    std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

    return 0;
}