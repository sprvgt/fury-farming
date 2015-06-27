#include<iostream>
using namespace std;

int 
countDivisor(int num)
{
  int cnt = 1;
  int i = 2;
  while (num > 1)
  {
    int t = 0;
    while (num % i == 0)
    {
      num /= i;
      t ++;
    }
    if (t > 0)
      cnt *= (t + 1);
    i ++;
  }
  return cnt;
}

int
main(int argc, char* argv[])
{
  int sum = 0;
  bool flag = true;
  for (int i = 1; flag; i ++)
  {
    int cnt;
    sum += i;
    if ((cnt = countDivisor(sum)) > 500)
      flag = false;
    cout << sum << "\t" << cnt << endl;
  }
  cout << sum << endl;
  return 0;
}
