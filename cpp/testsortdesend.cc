#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
  vector<int> a(3);
  a[0] = 1; a[1] = 2; a[2] = 3;
  sort(a.begin(), a.end(), greater<int>());
  cout << a[0] << a[1] << a[2] << endl;
  return 0;
}
