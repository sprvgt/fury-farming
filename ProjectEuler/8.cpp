#include<fstream>
#include<iostream>
using namespace std;

int
main(int argc, char* argv[])
{
  ifstream fin("8.in");
  char ch;
  int cnt = 13;
  int num[13];
  int rec[13];
  long long int ans = 0;
  int tt = 0;
  while (fin >> ch)
  {
    tt ++;
    if ('0' <= ch && ch <= '9')
    {
      if (cnt > 0)
      {
        cnt --;
        num[cnt] = (int)(ch - '0');
      }
      else
      {
        for (int i = 12; i > 0; i --)
          num[i] = num[i - 1];
        num[0] = (int)(ch - '0');
      }
      if (cnt == 0)
      {
        long long int prod = 1;
        for (int i = 0; i < 13; i ++)
          prod *= (long long int)num[i];
        if (prod > ans)
        {
          ans = prod;
          for (int i = 0; i < 13; i ++)
            rec[i] = num[i];
        }
      }
    }
  }
  cout << ans << endl;
  for (int i = 12; i >= 0; i --)
    cout << rec[i];
  cout << endl;
  cout << tt << endl;
  fin.close();
  return 0;
}


