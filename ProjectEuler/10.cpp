#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

#define UPLIMIT 2000000

int
main(int argc, char* argv[])
{
  bool a[UPLIMIT];
  long long int sum = 0;
  memset(a, 0, sizeof(a));
  for (int i = 2; i < UPLIMIT; i ++)
  {
    if (!a[i])
    {
      sum += (long long int)i;
      for (int j = i; j < UPLIMIT; j += i)
        a[j] = true;
    }
  }
  cout << sum << endl;
  return 0;
}
