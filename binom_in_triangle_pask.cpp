#include <iostream>
#include <limits>
#include <stdexcept>

unsigned long long safe_multiply(unsigned long long a, unsigned long long b) {
  if (a != 0 && b != 0 &&
      a > std::numeric_limits<unsigned long long>::max() / b) {
    throw std::overflow_error("Переполнение при вычислении факториала!/Введено "
                              "некорректное значение!");
  }

  return a * b;
}

unsigned long long factorial(unsigned long long n) {
  if (n <= 1) {
    return 1;
  }

  return safe_multiply(factorial(n - 1), n);
}

unsigned long long binom_k(unsigned long long n, unsigned long long k) {
  if (k > n) {
    throw std::invalid_argument("Некорректный порядковый номер!");
  }

  return factorial(n) / (safe_multiply(factorial(n - k), factorial(k)));
}

int main() {
  try {
    long long n = 0, k = 0;
    std::cin >> n >> k;

    if (std::cin.fail() || std::cin.bad()) {
      throw std::runtime_error("Некорректный ввод");
    }

    unsigned long long result = binom_k(n, k);
    std::cout << result << " ";
  } catch (std::invalid_argument &e) {
    std::cerr << "Ошибка: " << e.what() << "\n";
    return 1;
  } catch (std::overflow_error &e) {
    std::cerr << "Ошибка: " << e.what() << "\n";
    return 2;
  } catch (std::runtime_error &e) {
    std::cerr << "Ошибка: " << e.what() << "\n";
    return 3;
  }

  return 0;
}
