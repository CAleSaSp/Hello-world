#include <iostream>
#include <limits>
#include <stdexcept>

unsigned long long fibonachchi(long long n) {
  if (n < 0) {
    throw std::invalid_argument(
        "Номер числа Фибоначчии может быть только положительным!");
  }
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }

  unsigned long long number_1 = 0, number_2 = 0;

  number_1 = fibonachchi(n - 1);
  number_2 = fibonachchi(n - 2);

  if (number_1 > std::numeric_limits<unsigned long long>::max() - number_2) {
    throw std::overflow_error("Переполнение при вычислении числа Фибоначчи");
  }

  return number_1 + number_2;
}

int main() {
  try {

    long long n;
    std::cin >> n;

    if (std::cin.fail() || std::cin.bad()) {

      throw std::runtime_error("Некорректный ввод");
    }

    unsigned long long result = fibonachchi(n);
    std::cout << result << "\n";

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
