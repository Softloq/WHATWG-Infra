#include "test.hpp"
#include <iostream>

int main() {
  std::cout << "=== WHATWG Infra Library Example ===" << std::endl;
  std::cout << std::endl;

  // Create a test instance
  Softloq::WHATWG::Infra::Test myTest("ExampleTest");

  // Get the test name
  std::cout << "Test name: " << myTest.getName() << std::endl;

  // Run the test
  bool result = myTest.run();

  if (result) {
    std::cout << "Test result: PASSED ✓" << std::endl;
  } else {
    std::cout << "Test result: FAILED ✗" << std::endl;
  }

  std::cout << std::endl;
  std::cout << "Example completed successfully!" << std::endl;

  return 0;
}
