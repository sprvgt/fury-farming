#include<iostream>
#include<cstring>
using namespace std;

#define MAXNUMBER 1000000 

int a[MAXNUMBER];

int length(long long int num)
{
  cout << num << "->";
 if (num < MAXNUMBER && a[(int)num] > 0)
 {
  cout << endl;
  return a[(int)num];
 }
 int ret = 1;
 
 while (num >= MAXNUMBER)
 {
  if (num & 1)
    num = num * 3 + 1;
  else
    num >>= 1;
  ret ++;
  cout << num << "->";
 }

 if (num & 1)
  ret += length(num * 3 + 1);
 else
  ret += length(num >> 1);
 if (num < MAXNUMBER) a[(int)num] = ret;
 return ret;
}

int
main(int argc, char* argv[])
{
  int ans = 1;
  int maxlength = 1;
  memset(a, 0, sizeof(a));
  a[1] = 1;
  for (int i = 113383; i < MAXNUMBER; i ++)
  {
    int tmp;
    if ((tmp = length(i)) > maxlength)
    {
      ans = i;
      maxlength = tmp;
    }
  }
  cout << ans << '\t' << maxlength << endl;
  return 0;
}
