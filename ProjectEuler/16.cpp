#include<iostream>
#include<cstring>
using namespace std;

int
main(int argc, char* argv[])
{
  int prod[1000];
  memset(prod, 0, sizeof(prod));
  prod[0] = 1;
  int len = 1;
  for (int i = 1; i <= 1000; i ++)
  {
    int up = 0;
    for (int j = 0; j < len; j ++)
    {
      prod[j] <<= 1;
      prod[j] += up;
      up = prod[j] / 10;
      prod[j] %= 10;
    }
    if (up)
      prod[len ++] = up;
  }
  int sum = 0;
  for (int i = 0; i < len; i ++)
    sum += prod[i];
  cout << sum << endl;
  return 0;
}
