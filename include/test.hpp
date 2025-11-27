#ifndef WHATWG_INFRA_TEST_HPP
#define WHATWG_INFRA_TEST_HPP

#include <string>

namespace whatwg {
namespace infra {

/**
 * @brief A simple test class to demonstrate the library structure
 */
class Test {
public:
    /**
     * @brief Construct a new Test object
     * @param name The name for this test instance
     */
    explicit Test(const std::string& name);
    
    /**
     * @brief Get the name of this test instance
     * @return const std::string& The name
     */
    const std::string& getName() const;
    
    /**
     * @brief Run the test
     * @return true if the test passes, false otherwise
     */
    bool run() const;

private:
    std::string m_name;
};

} // namespace infra
} // namespace whatwg

#endif // WHATWG_INFRA_TEST_HPP
