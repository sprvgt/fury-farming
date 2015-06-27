#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

struct tri
{
  int x;
  int y;
  int w;
  tri(int _x, int _y, int _w): x(_x), y(_y), w(_w)  {}
};

bool cmp(tri a, tri b)
{
  return (a.x + a.y) < (b.x + b.y);
}

bool cover(tri a, tri b)
{
  if (b.x - b.y <= a.x - a.y)
    return true;
  return false;
}

double jointSize(tri a, tri b)
{
  if (a.x + a.y <= b.x - b.y)
    return 0.0;
  double l = (a.x + a.y) - (b.x - b.y);
  return (l / 2.0) * (l / 2.0);
}

int main()
{
  int t, T;
  while (cin >> T)
  {
    for (t = 1; t <= T; t ++)
    {
      cout << "Case #" << t << ": ";
      int n;
      cin >> n;
      vector<tri> triList;
      for (int i = 0 ;i < n; i ++)
      {
        int x, y, w;
        cin >> x >> y >> w;
        tri tmp(x, y, w);
        triList.push_back(tmp);
      }
      sort(triList.begin(), triList.end(), cmp);
      vector<double> opt(n, 0.0);
      double ret = 0.0;
      for (int i = 0; i < n; i ++)
      {
        opt[i] = triList[i].w - triList[i].y * triList[i].y;
        double bonus = triList[i].w - triList[i].y * triList[i].y;
        for (int j = i - 1; j >= 0; j --)
        {
          if (cover(triList[j], triList[i]))
          {
            bonus += triList[j].w;
            continue;
          }
          if (bonus + opt[j] + jointSize(triList[j], triList[i]) > opt[i])
            opt[i] = bonus + opt[j] + jointSize(triList[j], triList[i]);
        }
        if (bonus > opt[i])
          opt[i] = bonus;
        if (opt[i] > ret) ret = opt[i];
      }
      printf("%.2f\n", ret);
    }
  }
  return 0;
}

