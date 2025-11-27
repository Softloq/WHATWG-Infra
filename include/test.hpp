#ifndef SOFTLOQ_WHATWG_INFRA_TEST_HPP
#define SOFTLOQ_WHATWG_INFRA_TEST_HPP

#include <Softloq/API.Softloq.WHATWG.Infra.hpp>
#include <string>

namespace Softloq::WHATWG::Infra {

/**
 * @brief A simple test class to demonstrate the library structure
 */
class Test {
public:
  /**
   * @brief Construct a new Test object
   * @param name The name for this test instance
   */
  SOFTLOQ_WHATWG_INFRA_API explicit Test(const std::string &name);

  /**
   * @brief Get the name of this test instance
   * @return const std::string& The name
   */
  SOFTLOQ_WHATWG_INFRA_API const std::string &getName() const;

  /**
   * @brief Run the test
   * @return true if the test passes, false otherwise
   */
  SOFTLOQ_WHATWG_INFRA_API bool run() const;

private:
  std::string m_name;
};

} // namespace Softloq::WHATWG::Infra

#endif // SOFTLOQ_WHATWG_INFRA_TEST_HPP
