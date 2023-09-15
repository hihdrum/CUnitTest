#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

extern "C" {

#include "use.h"
#include "dep.h"

int dep(char *cp)
{
  mock().actualCall("dep")
    .withParameter("cp", *cp);
  return mock().intReturnValue();
}

void MockSet_dep(int iReturnValue, char *cp)
{
  mock().expectOneCall("dep")
    .withParameter("cp", *cp)
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
  char c = 'A';
  char dmy = 'B';
  MockSet_dep(5, &c);

  int iReturnValue = use();

  LONGS_EQUAL(50, iReturnValue);
}
