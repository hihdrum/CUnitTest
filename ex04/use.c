#include "dep.h"

int use(void)
{
  int iDepResult = dep();
  if(0 == iDepResult)
  {
    dep02("zero");
    return 0;
  }
  else
  {
    dep02("ten");
    return 10 * iDepResult;
  }
}
