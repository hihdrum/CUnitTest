#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

extern "C" {

#include "use.h"
#include "dep.h"

int dep(int *ip)
{
  mock().actualCall("dep")
    .withParameter("ip", *ip);
  return mock().intReturnValue();
}

void MockSet_dep(int iReturnValue, int *ip)
{
  mock().expectOneCall("dep")
    .withParameter("ip", *ip)
    .andReturnValue(iReturnValue);
}

}

TEST_GROUP(tg01)
{
  void teardown() {
    mock().checkExpectations();
    mock().clear();
  }

};

TEST(tg01, sample)
{
  int i = 1;
  MockSet_dep(5, &i);

  int iReturnValue = use();

  LONGS_EQUAL(50, iReturnValue);
}
