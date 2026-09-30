#include <exception>
#include <iostream>
#include <stdexcept>

int divide(const int a, const int b) {
  if (b == 0) {
    throw std::invalid_argument("can`t divide by zero");
  }
  return a / b;
}

int main() {
  int a = 0;
  int *b = &a;
  try {
    std::cout << divide(4, 0) << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "error : " << e.what() << std::endl;
    return 1;
  }
}
