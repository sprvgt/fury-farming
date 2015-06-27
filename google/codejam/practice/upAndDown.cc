#include<iostream>
#include<fstream>
#include<map>
using namespace std;

int main()
{
  ifstream fin("B-small-practice.in");
  ofstream fout("upAndDown.out");

  int t, T;
  map<int, int> dict;
  fin >> T;
  for (t = 1; t <= T; t ++)
  {
    fout << "Case #" << t << ": ";
    dict.clear();

    int n;
    fin >> n;
    for (int i = 1; i <= n; i ++)
    {
      int num;
      fin >> num;
      dict[num] = i;
    }

    int l = 1, r = n;
    int ans = 0;

    while (!dict.empty())
    {
      int key = dict.begin()->first, pos = dict.begin()->second;
      cout << key << ',' << pos << endl;
      if (pos - l < r - pos)
      {
        for (map<int, int>::iterator it = dict.begin();
            it != dict.end(); ++ it)
        {
          if (it->second < pos)
            it->second ++;
        }
        ans += pos - l;
        l ++;
      }
      else
      {
        for (map<int, int>::iterator it = dict.begin();
            it != dict.end(); ++ it)
          if (it->second > pos)
            it->second --;
        ans += r - pos;
        r --;
      }
      dict.erase(key);
    }

    fout << ans << endl;
  }

  return 0;
}
