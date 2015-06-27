#include<iostream>
#include<fstream>
using namespace std;

int main()
{
  ifstream fin("pD.in");
  ofstream fout("pD.out");

  int T, t;

  fin >> T;

  for (t = 1; t <= T; t ++)
  {
    int x, r, c;
    string ans[2] = {"GABRIEL", "RICHARD"};
    fin >> x >> r >> c;

    int flag = 0;

    if (x >= 7)
     flag = 1;
    
    if (r * c % x != 0)
      flag = 1;

    if (r * c / x == 2 && x >= 4)
      flag = 1;

    if ((x / 2) + (x & 1) > min(r, c))
      flag = 1;

    if (x > max(r, c))
      flag = 1;

    if (x == 5 && min(r, c) == 3 && max(r, c) == 5)
      flag = 1;
    if (x == 6 && min(r, c) == 3)
      flag = 1;

    fout << "Case #" << t << ": " << ans[flag] << endl;
  }

  return 0;
}
