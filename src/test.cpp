#include <test.hpp>
#include <iostream>

namespace Softloq::WHATWG::Infra {

Test::Test(const std::string &name) : m_name(name) {
  std::cout << "Test instance created: " << m_name << std::endl;
}

const std::string &Test::getName() const { return m_name; }

bool Test::run() const {
  std::cout << "Running test: " << m_name << std::endl;
  // Simple test logic
  return !m_name.empty();
}

} // namespace Softloq::WHATWG::Infra
