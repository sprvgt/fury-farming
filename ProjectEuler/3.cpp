#include<iostream>
#include<cmath>
using namespace std;

int
dive(int n)
{
  for (int i = (int)(sqrt((double)n)); i > 1; i --)
    if (n % i == 0)
    {
      dive(n / i);
      cout << '*';
      dive(i);
      return 0;
    }
  cout << n;
  return 0;
}

int
main(int argc, char* argv[])
{
  long long int N = 600851475143;
  for (int i = 2500000; i > 1; i --)
    if (N % (long long int) i == 0)
    {
      dive((int)(N / (long long int)i));
      cout << '*';
      dive(i);
      cout << endl;
      break;
    }
  return 0;
}
