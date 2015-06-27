#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int
main(int argc, char* argv[])
{
  int ans = 0;
  int a[10000];
  for (int i = 1; i < 10000; i ++)
  {
    int up = (int)sqrt(i);
    int sum = 1;
    for (int j = 2; j <= up; j ++)
    {
      if (i % j == 0)
      {
        int k = i / j;
        sum += j + k;
        if (j == k)
          sum -= k;
      }
    }
    a[i] = sum;
    if (sum <= i && a[sum] == i)
    {
      cout << i << '\t' << sum << endl;
      ans += sum + i;
      if (sum == i)
      {
        printf("a[%d] == %d\n", i, i);
        ans -= i + i;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
