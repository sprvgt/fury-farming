#include<iostream>
using namespace std;

int main()
{
  pair<int, int> a = make_pair(10, 30),
                 b = make_pair(20, 20);
  pair<int, int> c = min(a, b);
  cout << c.first << ' ' << c.second << endl;
  return 0;
}
