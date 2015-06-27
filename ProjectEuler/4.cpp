#include<iostream>
using namespace std;

bool palindrome(int num)
{
  int cnt = 0;
  int n[7];
  while (num > 0)
  {
    n[cnt] = num % 10;
    num /= 10;
    cnt ++;
  }
  int mid = cnt / 2;
  for (int i = 0; i < mid; i ++)
    if (n[i] != n[cnt - i - 1])
      return false;
  return true;
}

int
main(int argc, char* argv[])
{
  int ans = 0;
  for (int a = 100; a < 1000; a ++)
    for (int b = a; b < 1000; b ++)
    {
      int c = a * b;
      if (palindrome(c) && c > ans)
        ans = c;
    }
  cout << ans << endl;
  return 0;
}
