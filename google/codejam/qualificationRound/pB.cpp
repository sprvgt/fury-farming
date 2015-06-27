#include<iostream>
#include<fstream>
using namespace std;

int main()
{
  ifstream fin("pB.in");
  ofstream fout("pB.out");

  int T;

  fin >> T;
  for (int i = 0; i < T; i ++)
  {
    int n;
    fin >> n;

    int stuff[n];
    for (int j = 0; j < n; j ++)
      fin >> stuff[j];

    int ans = 1000;
    for (int j = 1; j < 1000; j ++)
    {
      int cur = j;
      for (int k = 0; k < n; k ++)
        cur += (stuff[k] - 1) / j;
      ans = min(ans, cur);
    }

    fout << "Case #" << i + 1 << ": " << ans << endl;
  }

  return 0;
}
