#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

extern "C" {

#include "use.h"
#include "dep.h"

int dep(int x, int y)
{
  mock().actualCall("dep")
    .withParameter("x", x)
    .withParameter("y", y);
  return mock().intReturnValue();
}

void MockSet_dep(int iReturnValue, int x, int y)
{
  mock().expectOneCall("dep")
    .withParameter("x", x)
    .withParameter("y", y)
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
  MockSet_dep(5, 1, 2);

  int iReturnValue = use();

  LONGS_EQUAL(50, iReturnValue);
}
