#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

extern "C" {

#include "use.h"
#include "dep.h"

int dep(struct MyType *tpMyType)
{
  mock().actualCall("dep")
    .withParameter("tpMyType", tpMyType);
  return mock().intReturnValue();
}

void MockSet_dep(int iReturnValue, struct MyType *tpMyType)
{
  mock().expectOneCall("dep")
    .withParameter("tpMyType", tpMyType)
    .andReturnValue(iReturnValue);
}

}

TEST_GROUP(tg01)
{
  void teardown() {
    mock().clear();
  }

};

TEST(tg01, sample)
{
  struct MyType tMyType = { 10 };
  MockSet_dep(100, &tMyType);

  int iReturnValue = use();

  LONGS_EQUAL(50, iReturnValue);
}
