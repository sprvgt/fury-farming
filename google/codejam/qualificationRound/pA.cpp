#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
  ifstream fin("pA.in");
  ofstream fout("pA.out");
  
  int T;

  fin >> T;
  for (int t = 1; t <= T; t ++)
  {
    int s;
    string str;

    fin >> s >> str;

    int cnt = 0, ans = 0;
    for (int i = 0; i <= s; i ++)
    {
      if (cnt < i)
      {
        ans += i - cnt;
        cnt = i;
      }
      cnt += str[i] - '0';
    }

    fout << "Case #" << t << ": " << ans << endl;
  }

  return 0;
}
