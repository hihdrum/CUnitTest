#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

extern "C" {

#include "use.h"
#include "dep.h"

#include "Mock_dep.h"
#include "Mock_dep02.h"

}

TEST_GROUP(tg01)
{
  void teardown() {
    mock().clear();
  }

};

TEST(tg01, depReturn0)
{
  /* 依存関数の動作指定 */
  MockSet_dep(0);
  MockSet_dep02("zero");

  /* 試験対象関数の呼び出し */
  int iReturnValue = use();

  /* 結果確認 */
  LONGS_EQUAL(0, iReturnValue);
}

TEST(tg01, depReturn10)
{
  /* 依存関数の動作指定 */
  MockSet_dep(10);
  MockSet_dep02("ten");

  /* 試験対象関数の呼び出し */
  int iReturnValue = use();

  /* 結果確認 */
  LONGS_EQUAL(10 * 10, iReturnValue);
}

