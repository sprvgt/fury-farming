#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;

#define H 100 

int
main(int argc, char* argv[])
{
  int a[H][H];
  int opt[2][H];
  ifstream fin("67.in");
  int s = 0;
  memset(opt, 0, sizeof(opt));
  for (int i = 0; i < H; i ++)
  {
    for (int j = 0; j <= i; j ++)
    {
      fin >> a[i][j];
      if (0 < j && j < i)
      {
        opt[s][j] = max(opt[1 - s][j], opt[1 - s][j - 1])
                    + a[i][j];
      }
      else
      if (j == 0)
        opt[s][j] = opt[1 - s][j] + a[i][j];
      else
      if (j == i && i > 0)
        opt[s][j] = opt[1 - s][j - 1] + a[i][j];
    }
    s = 1 - s;
  }
  s = 1 - s;
  int optimal = 0;
  for (int i = 0; i < H; i ++)
    if (opt[s][i] > optimal)
      optimal = opt[s][i];
  cout << optimal << endl;
  return 0;
}

