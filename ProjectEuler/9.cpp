#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
  for (int a = 1; a < 1000; a ++)
    for (int b = a + 1; b < 1000; b ++)
    {
      int c = 1000 - a - b;
      if (c > b)
      {
        if (a * a + b * b == c * c)
        {
          cout << a * b * c << endl;
          exit(0);
        }
      }
    }
  return 0;
}
