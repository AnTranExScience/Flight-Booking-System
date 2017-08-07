#include <iostream>
#include "StartUp.h"

/* ------------------------------------------------------------- */

int main()
{
  try
  {
    StartUp st1;
    st1.Run();
  }

  catch(const char* _e)
  {
    std::cout << _e << std::endl;
  }

  return 0;
}

/* ------------------------------------------------------------- */
