#include "dep.h"

int use(void)
{
  struct MyType tMyType = { 10, 'a' };
  int iDepResult = dep(&tMyType);
  if(0 == iDepResult)
  {
    return 0;
  }
  else
  {
    return 10 * iDepResult;
  }
}
