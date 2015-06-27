#include<iostream>
#include<cstdio>
using namespace std;

bool isleap(int tt)
{
  if (tt % 400 == 0)
    return true;
  if (tt % 100 == 0)
    return false;
  if (tt % 4 == 0)
    return true;
  return false;
}

int
main(int argc, char* argv[])
{
  int dd[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int tt = 0;
  int day = 2;
  for (int i = 1901; i <= 2000; i ++)
  {
    for (int j = 1; j <= 12; j ++)
    {
      if (day == 0) tt ++;
      day = (day + dd[j]) % 7;
      if (j == 2 && isleap(i))
        day = (day + 1) % 7;
    }
  }
  cout << tt << endl;
  return 0;
}
