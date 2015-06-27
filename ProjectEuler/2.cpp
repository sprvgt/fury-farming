#include<iostream>
using namespace std;

int
main(int argc, char* argv[])
{
  int a = 0, b = 1;
  int c = 0;
  int sum = 0;
  while (c <= 4000000)
  {
    c = a + b;
    if (!(c & 1))
      sum += c;
    a = b;
    b = c;
  }
  cout << sum << endl;
  return 0;
}
