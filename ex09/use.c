#include "dep.h"

int use(void)
{
  int i = 1;
  int iDepResult = dep(&i);
  if(0 == iDepResult)
  {
    return 0;
  }
  else
  {
    return 10 * iDepResult;
  }
}
