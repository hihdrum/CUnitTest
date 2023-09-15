#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

extern "C" {

#include "use.h"
#include "dep.h"

int dep(struct MyType *tpMyType)
{
  mock().actualCall("dep")
    .withParameterOfType("MyType", "tpMyType", tpMyType);
  return mock().intReturnValue();
}

void MockSet_dep(int iReturnValue, struct MyType *tpMyType)
{
  mock().expectOneCall("dep")
    .withParameterOfType("MyType", "tpMyType", tpMyType)
    .andReturnValue(iReturnValue);
}

}

class MyTypeComparator : public MockNamedValueComparator
{
public:
  virtual bool isEqual(const void* object1, const void* object2)
  {
    return 0 == memcmp(object1, object2, sizeof(struct MyType));
  }
  virtual SimpleString valueToString(const void* object)
  {
    struct MyType *tpMyType = (struct MyType *)object;
    return StringFromFormat("f:%d, f2:%d", tpMyType->f, tpMyType->f2);
  }
};


TEST_GROUP(tg01)
{
  void teardown() {
    mock().clear();
    mock().removeAllComparatorsAndCopiers();
  }

};

TEST(tg01, sample)
{
  MyTypeComparator comparator;
  mock().installComparator("MyType", comparator);

  struct MyType tMyType = { 100 };
  MockSet_dep(5, &tMyType);

  int iReturnValue = use();

  LONGS_EQUAL(50, iReturnValue);
}
