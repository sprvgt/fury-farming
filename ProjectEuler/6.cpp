#include<iostream>
using namespace std;

int
main(int argc, char* argv[])
{
  int sum = 0;
  for (int i = 1; i <= 100; i ++)
    for (int j = i + 1; j <= 100; j ++)
      sum += 2 * i * j;
  cout << sum << endl;
  return 0;
}
