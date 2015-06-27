#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
  int t, T;
  while (cin >> T)
  {
    for (t = 1; t <= T; ++ t)
    {
      cout << "Case #" << t << ":" << endl;
      int n;
      cin >> n;
      unordered_map<int, int> color;
      unordered_map<int, vector<int>> edges;
      for (int i = 0; i < n - 1; i ++)
      {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
      }
      int q;
      cin >> q;

      int num = 1;
      for (int k = 0; k < q; k ++)
      {
        int order;
        cin >> order;
        if (order == 1)
        {
          cout << num << endl;
          continue;
        }
        int ptr, col;
        cin >> ptr >> col;
        int precnt = 0, aftcnt = 0;
        for (vector<int>::iterator it = edges[ptr].begin();
            it != edges[ptr].end(); ++ it)
        {
          if (color[*it] == color[ptr]) 
            precnt ++;
          if (color[*it] == col)  aftcnt ++;
        }
        color[ptr] = col;
        num += precnt - 1;
        num -= aftcnt - 1;
      }

    }
  }
  return 0;
}
