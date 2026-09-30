#include <iostream>

int main() {
  double sum = 0, num = 0;
  int count = 0;

  while (true) {
    std::cin >> num;
    if (std::cin.eof()) {
      break;
    }
    if (std::cin.fail()) {
      std::cerr << "Wrong type!";
      return 1;
    }
    sum += num;
    count++;
  }

  if (count == 0) {
    std::cout << "Empty siquence!";
  } else {
    std::cout << "Average of siquence: " << sum / count << ".";
  }
}
