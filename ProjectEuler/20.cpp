#include<iostream>
#include<cstring>
using namespace std;

int
main(int argc, char* argv[])
{
  int a[200];
  memset(a, 0, sizeof(a));
  a[0] = 1;
  int len = 1;
  for (int i = 2; i <= 100; i ++)
  {
    int up = 0;
    for (int j = 0; j < len; j ++)
    {
      a[j] *= i;
      a[j] += up;
      up = a[j] / 10;
      a[j] %= 10;
    }
    while (up > 0)
    {
      a[len ++] = up % 10;
      up /= 10;
    }
  }
  int sum = 0;
  for (int i = 0; i < len; i ++)
    sum += a[i];
  cout << sum << endl;
  return 0;
}
