#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

class Solution
{
  public:
    int getPalindromeNum(string str)
    {
      int n = str.length();
      int pair[n][n];
      memset(pair, 0, sizeof(pair));
      for (int i = 0; i < n; i ++)
      {
        pair[i][i] = 1;
        for (int j = i - 1; j >= 0; j --)
        {
          if (str[j] == str[i])
          {
            pair[j][i] = 1;
            if (j < i - 1)
              for (int p = j + 1; p <= i - 1; p ++)
                for (int q = p; q <= i - 1; q ++)
                  pair[j][i] = (pair[j][i] + pair[p][q]) % 100007;
          }
        }
      }
      int sum = 0;
      for (int i = 0; i < n; i ++)
        for (int j = i; j < n; j ++)
          sum = (sum + pair[i][j]) % 100007;

      return sum;
    }
};

int main()
{
  int T, t;
  while (cin >> T)
  {
    for (t = 1; t <= T; t ++)
    {
      cout << "Case #" << t << ": ";
      string str;
      cin >> str;
      cout << Solution().getPalindromeNum(str) << endl;
    }
  }
  return 0;
}
