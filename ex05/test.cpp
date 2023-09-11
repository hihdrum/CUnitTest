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

TEST(tg01, call2)
{
  MockSet_dep(3);
  MockSet_dep(4);

  int iReturnValue = use();

  LONGS_EQUAL(7, iReturnValue);
}

