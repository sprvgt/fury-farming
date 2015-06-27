#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

struct point
{
  int x, y;
  point(int _x, int _y):x(_x), y(_y)  {}
};

bool cmp(point p1, point p2)
{
  if (p1.x == p2.x)
    return p1.y < p2.y;
  return p1.x < p2.x;
}

int xchen(point p1, point p2, point p)
{
  return (p1.x - p.x) * (p2.y - p.y) - (p1.y - p.y) * (p2.x - p.x);
}

vector<point> getBao(vector<point> &ptrList)
{
  vector<point>  bao;
  if (ptrList.size() < 3)  
  {
    for (int i = 0; i < ptrList.size(); i ++)
      bao.push_back(ptrList[i]);
    return bao;
  }
  vector<point> localList(ptrList);
  sort(localList.begin(), localList.end(), cmp);
//  cout << "Sorted:";
//for (int i = 0; i < localList.size(); i ++)
//    cout << '(' << localList[i].x << ',' << localList[i].y << ")\t";
//ut << endl;
  bao.push_back(localList[0]);
  bao.push_back(localList[1]);
  int n = ptrList.size();
  for (int i = 2; i < n; i ++)
  {
    while (bao.size() > 1 && xchen(localList[i], bao[bao.size() - 1], bao[bao.size() - 2]) > 0)
      bao.pop_back();
    bao.push_back(localList[i]);
  }
  int t = bao.size();
  bao.push_back(localList[n - 2]);
  for (int i = n - 3; i >= 0; i --)
  {
    while (bao.size() > t && xchen(localList[i], bao[bao.size() - 1], bao[bao.size() - 2]) > 0)
      bao.pop_back();
    bao.push_back(localList[i]);
  }
  return bao;
}


void findAns(vector<point>& ptrList, vector<int> &ret,
        vector<point> &pickPtr, int depth)
{
  if (depth == ptrList.size())
  {
//  cout << "Pick:";
//  for (int i = 0; i < pickPtr.size(); i ++)
//    cout << '(' << pickPtr[i].x << ',' << pickPtr[i].y << ")\t";
//  cout << endl;
    vector<point> bao = getBao(pickPtr);
//  cout << "Bao:";
//  for (int i = 0; i < bao.size(); i ++)
//    cout << '(' << bao[i].x << ',' << bao[i].y << ")\t";
//  cout << endl;
    for (int k = 0; k < bao.size(); k ++)
    {
      point ptr = bao[k];
      int n = ptrList.size();
      for (int i = 0; i < n; i ++)
      {
        if (ptr.x == ptrList[i].x && ptr.y == ptrList[i].y)
          if (n - pickPtr.size() < ret[i])
          {
            ret[i] = n - pickPtr.size();
//          cout << "ret[" << i << "]=" << ret[i] << endl;
          }
      }
    }
    return;
  }
  findAns(ptrList, ret, pickPtr, depth + 1);
  pickPtr.push_back(ptrList[depth]);
  findAns(ptrList, ret, pickPtr, depth + 1);
  pickPtr.pop_back();
}

int main()
{
  ifstream cin("3.in");
  ofstream cout("3.out");

  int t, T;
  cin >> T;
  for (t = 1; t <= T; ++ t)
  {
    cout << "Case #" << t << ":" << endl;
    int n;
    vector<point> ptrList;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
      int x, y;
      cin >> x >> y;
      ptrList.push_back(point(x, y));
    }
    vector<int> ret(n, 0x7fffffff);
    vector<point> pickPtr;
    findAns(ptrList, ret, pickPtr, 0);
    for (int i = 0; i < n; i ++)
      cout << ret[i] << endl;
  }
  return 0;
}
