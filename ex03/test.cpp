#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

extern "C" {

#include "use.h"
#include "dep.h"

int dep(void)
{
  mock().actualCall("dep");
  return mock().intReturnValue();
}

void MockSet_dep(int iReturnValue)
{
  mock().expectOneCall("dep")
    .andReturnValue(iReturnValue);
}

}

TEST_GROUP(tg01)
{
  void teardown() {
    mock().clear();
  }

};

TEST(tg01, depReturn0)
{
  MockSet_dep(0);

  int iReturnValue = use();

  LONGS_EQUAL(0, iReturnValue);
}

TEST(tg01, depReturn10)
{
  MockSet_dep(10);

  int iReturnValue = use();

  LONGS_EQUAL(10 * 10, iReturnValue);
}

