#include<iostream>
using namespace std;

int main()
{
  int num;

  cin >> num;

  int factor = 1, ret = 0;
  
  do
  {
    factor *= 5;
    ret += num / factor;
  }
  while (num / 5 >= factor);

  cout << ret << endl;

  return 0;
}
