#include "dep.h"

int use(void)
{
  char c = 'A';
  char dmy = 'A';
  int iDepResult = dep(&c);
  if(0 == iDepResult)
  {
    return 0;
  }
  else
  {
    return 10 * iDepResult;
  }
}
