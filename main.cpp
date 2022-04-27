#include "extra.h"

int main()
{
  SLAR mySystem1, mySystem2;

  mySystem1.print();
  mySystem1.YakobiMethod();
  mySystem2.SeidelMethod();
  return 0;
}
