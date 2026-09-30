#include <cstddef>
#include <iostream>

unsigned getRange(const unsigned *arr, size_t n) {
  unsigned minValue = arr[0];
  unsigned maxValue = arr[0];

  for (size_t i = 1; i < n; ++i) {
    if (arr[i] < minValue) {
      minValue = arr[i];
    }
    if (arr[i] > maxValue) {
      maxValue = arr[i];
    }
  }

  return maxValue - minValue;
}

unsigned GCDtwo_nums(unsigned a, unsigned b) {
  while (a != 0 && b != 0) {
    if (a > b) {
      a = a % b;
    } else {
      b = b % a;
    }
  }

  return a + b;
}

unsigned GCDfr(const unsigned *arr, size_t n) {
  unsigned result = arr[0];
  for (size_t i = 1; i < n; ++i) {
    result = GCDtwo_nums(result, arr[i]);
  }

  return result;
}

unsigned LCMtwo_nums(unsigned a, unsigned b) {
  unsigned gcd = GCDtwo_nums(a, b);

  return (a / gcd) * b;
}

unsigned LCMfr(const unsigned *arr, size_t n) {
  unsigned result = arr[0];
  for (size_t i = 1; i < n; ++i) {
    result = LCMtwo_nums(result, arr[i]);
  }

  return result;
}

void Bubble_Sorting(unsigned *arr, size_t n) {
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j + 1 < n - i; j++) {
      if (arr[j] > arr[j + 1]) {
        unsigned temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

double Median(const unsigned *arr, size_t n) {
  unsigned *sorted_arr = new unsigned[n];
  for (size_t i = 0; i < n; ++i) {
    sorted_arr[i] = arr[i];
  }
  Bubble_Sorting(sorted_arr, n);

  double result = 0;
  if (n % 2 == 1) {
    result = sorted_arr[n / 2];
  } else {
    result = (sorted_arr[n / 2] + sorted_arr[n / 2 - 1]) / 2.0;
  }

  delete[] sorted_arr;
  return result;
}

int main() {
  unsigned n = 0;
  std::cin >> n;
  if (std::cin.fail() || std::cin.bad()) {
    return 1;
  }

  unsigned *arr = new unsigned[n];

  for (size_t i = 0; i < n; ++i) {
    std::cin >> arr[i];

    if (std::cin.bad() || std::cin.fail()) {
      delete[] arr;
      return 1;
    }
  }

  std::cout << "Размах:  " << getRange(arr, n) << "\n";
  std::cout << "НОД:     " << GCDfr(arr, n) << "\n";
  std::cout << "НОК:     " << LCMfr(arr, n) << "\n";
  std::cout << "Медиана: " << Median(arr, n) << "\n";

  delete[] arr;
  return 0;
}
