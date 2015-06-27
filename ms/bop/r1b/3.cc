#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;

struct person
{
  int gender;
  vector<int> fr;
  unordered_map<int, int> ship;
};

int main()
{
  int t, T;
  while (cin >> T)
  {
    for (t = 1; t <= T; t ++)
    {
      cout << "Case #" << t << ":" << endl;
      int n, m, q;
      cin >> n >> m >> q;
      vector<person> per(n + 1);
      for (int i = 1; i <= n; i ++)
        cin >> per[i].gender;
      long long int ret = 0;
      for (int i = 0; i < m; i ++)
      {
        int x, y, z;
        cin >> x >> y >> z;
        if (per[x].gender != per[y].gender) ret += z;
        per[x].fr.push_back(y);
        per[y].fr.push_back(x);
        per[x].ship[y] = z;
        per[y].ship[x] = z;
      }
      for (int i = 0; i < q; i ++)
      {
        int order;
        cin >> order;
        if (order == 3)
        {
          cout << ret << endl;
          continue;
        }
        if (order == 2)
        {
          int x, y, z;
          cin >> x >> y >> z;
          if (per[x].ship.find(y) == per[x].ship.end())
          {
            per[x].fr.push_back(y);
            per[y].fr.push_back(x);
          }
          if (per[x].gender != per[y].gender)
            ret += z - per[x].ship[y];
          per[x].ship[y] = z;
          per[y].ship[x] = z;
          continue;
        }
        if (order == 1)
        {
          int x;
          cin >> x;
          per[x].gender = 1 - per[x].gender;
          int len = per[x].fr.size();
          for (int j = 0; j < len; j ++)
          {
            int y = per[x].fr[j];
            if (per[x].gender == per[y].gender)
              ret -= per[x].ship[y];
            else
              ret += per[x].ship[y];
          }
        }
      }
    }
  }
  return 0;
}
