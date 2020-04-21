/**
 * Driver for starting movie store tests
 */

#include <iostream>

// forward declaration, implementation in store_test.cpp
void testAll();

int main() {
  testAll();
  std::cout << "Done." << std::endl;
  std::cin.get();
  return 0;
}
