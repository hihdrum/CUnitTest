#include <CppUTest/TestHarness.h>

TEST_GROUP(SmallTestGroup)
{
};

TEST(SmallTestGroup, FailTest)
{
  FAIL("Fail me!");
}
