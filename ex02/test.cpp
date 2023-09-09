#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

extern "C" {

int use_init_x(void);

void init_x(int *x)
{
  mock().actualCall("init_x")
    .withOutputParameter("x", x);
}

void MockSet_init_x(int *x)
{
  mock().expectOneCall("init_x")
    .withOutputParameterReturning("x", x, sizeof(int));
}

}

TEST_GROUP(tg01)
{
  void teardown() {
    mock().clear();
  }

};

TEST(tg01, t01)
{
  int x = 0;
  MockSet_init_x(&x);

  int iReturnValue = use_init_x();

  LONGS_EQUAL(0, iReturnValue);
}
