
#include "oatpp-test/UnitTest.hpp"

#include "oatpp-curl/RequestExecutor.hpp"

#include "oatpp/Environment.hpp"

#include <iostream>

namespace {

class Test : public oatpp::test::UnitTest {
public:
  Test() : oatpp::test::UnitTest("MyTag")
  {}

  void onRun() override {
    // TODO write correct tests
    auto requestExecutor = oatpp::curl::RequestExecutor::createShared("url");
  }
};

void runTests() {
  OATPP_RUN_TEST(Test);
}

}

int main() {

  oatpp::Environment::init();

  runTests();

  /* Print how much objects were created during app running, and what have left-probably leaked */
  /* Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
  std::cout << "\nEnvironment:\n";
  std::cout << "objectsCount = " << oatpp::Environment::getObjectsCount() << "\n";
  std::cout << "objectsCreated = " << oatpp::Environment::getObjectsCreated() << "\n\n";

  OATPP_ASSERT(oatpp::Environment::getObjectsCount() == 0);

  oatpp::Environment::destroy();

  return 0;
}
