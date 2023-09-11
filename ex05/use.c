#include "dep.h"

int use(void)
{
  int t1 = dep();
  int t2 = dep();

  return t1 + t2;
}
