#include "test.hpp"
#include <cassert>
#include <iostream>

int main() {
  std::cout << "Running basic tests for WHATWG Infra library..." << std::endl;

  // Test 1: Constructor and getName
  Softloq::WHATWG::Infra::Test test1("BasicTest");
  assert(test1.getName() == "BasicTest");
  std::cout << "✓ Test 1 passed: Constructor and getName()" << std::endl;

  // Test 2: run() returns true for non-empty name
  assert(test1.run() == true);
  std::cout << "✓ Test 2 passed: run() returns true for valid test"
            << std::endl;

  // Test 3: run() returns false for empty name
  Softloq::WHATWG::Infra::Test test2("");
  assert(test2.run() == false);
  std::cout << "✓ Test 3 passed: run() returns false for empty name"
            << std::endl;

  std::cout << "\nAll basic tests passed!" << std::endl;
  return 0;
}
