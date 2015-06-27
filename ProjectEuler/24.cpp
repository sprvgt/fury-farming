#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
  int a[10] = {0, 1, 2, 3, 4, 5,
              6, 7, 8, 9};
  int tt = 1000000 - 1;
  int prod = 1;
  for (int i = 1; i <= 9; i ++) prod *= i;
  for (int i = 9; i >= 1; i --)
  {
    //printf("[%d]\n", prod);
    int j = tt / prod;
    int k = 0;
    while (j > 0)
    {
      if (a[k] >= 0)
        j --;
      k ++;
    }
    while (a[k] < 0)
      k ++;
    cout << a[k];
    a[k] = -1;
    tt = tt % prod;
    prod /= i;
  }
  for (int i = 0; i < 10; i ++)
    if (a[i] >= 0)
      cout << a[i] << endl;
  return 0;
}

