#include "dep.h"

int use(void)
{
  int iDepResult = dep(1, 2);
  if(0 == iDepResult)
  {
    return 0;
  }
  else
  {
    return 10 * iDepResult;
  }
}
