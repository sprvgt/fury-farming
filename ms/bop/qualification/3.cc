#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution
{
public:
  long long getMinimalCost(vector<int> &ax, vector<int> &ay,
                            vector<int> &bx, vector<int> &by)
  {
    int x, y;
    x = getMinimalPtr(ax, bx);
    y = getMinimalPtr(ay, by);
    return min(
              min(getCost(x, y, ax, ay, bx, by), getCost(x, y + 1, ax, ay, bx, by)),
              min(getCost(x + 1, y, ax, ay, bx, by), getCost(x + 1, y + 1, ax, ay, bx, by))
        );
  }

private:
  int getMinimalPtr(vector<int> &a, vector<int> &b)
  {
    int an = a.size();
    int ptr = 0, mod = 0;
    for (int i = 0; i < an; i ++)
    {
      ptr += (mod + a[i]) / an;
      mod = (mod + a[i]) % an;
    }
    return ptr; 
  }

  long long getCost(int x, int y,
                    vector<int> &ax, vector<int> &ay,
                    vector<int> &bx, vector<int> &by)
  {
    long long ret = 0;
    int n;
    n = ax.size();
    for (int i = 0; i < n; i ++)
      ret += (long long)(ax[i] - x) * (long long)(ax[i] - x) +
             (long long)(ay[i] - y) * (long long)(ay[i] - y);
    n = bx.size();
    int minB = 0x7fffffff;
    for (int i = 0; i < n; i ++)
      if (minB > abs(bx[i] - x) + abs(by[i] - y))
        minB = abs(bx[i] - x) + abs(by[i] - y);
    ret += (long long) minB;
    return ret;
  }
};

int main()
{
  int t, T;
  Solution s;
  cin >> T;
  for (t = 1; t <= T; t ++)
  {
    cout << "Case #" << t << ": ";
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<int> ax, ay, bx, by;
    int x, y;
    for (int i = 0; i < a; i ++)
    {
      cin >> x >> y;
      ax.push_back(x);
      ay.push_back(y);
    }
    for (int i = 0; i < b; i ++)
    {
      cin >> x >> y;
      bx.push_back(x);
      by.push_back(y);
    }
    cout << s.getMinimalCost(ax, ay, bx, by) << endl;
  }
  return 0;
}
