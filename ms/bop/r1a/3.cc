#include<iostream>
using namespace std;

int main()
{
  int t, T;
  cin >> T;
  for (t = 1; t <= T; t ++)
  {
    cout << "Case #" << t << ": ";
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i ++)
    {
      int tmp;
      cin >> tmp;
      nums.push_back(tmp);
    }
  }
  return 0;
}
