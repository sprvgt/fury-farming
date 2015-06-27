#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main()
{
  ifstream fin("A-large-practice.in");
  ofstream fout("data_Packing.out");

  int t, T;

  fin >> T;
  for (t = 1; t <= T; ++ t)
  {
    int n, s;
    fin >> n >> s;
    int stuff[n];
    for (int i = 0; i < n; i ++)
      fin >> stuff[i];
    sort(stuff, stuff + n);
    int l = 0, r = n - 1;
    int ans = 0;
    while (l < r)
    {
      ans ++;
      if (stuff[l] + stuff[r] <= s)
        l ++;
      r --;
    }
    if (l == r) ans ++;
    fout << "Case #" << t << ": " << ans << endl;
  }

  return 0;
}
