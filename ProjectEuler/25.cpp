#include<iostream>
#include<cstring>
using namespace std;

#define MAXLENGTH 1001

int
main(int argc, char* argv[])
{
  int a[MAXLENGTH], b[MAXLENGTH], c[MAXLENGTH];
  int alen, blen, clen;

  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  memset(c, 0, sizeof(c));
  a[0] = 1; b[0] = 1;
  alen = 1; blen = 1; clen = 0;
  int cnt = 2;
  while (clen < 1000)
  {
    c[0] = 0;
    for (int i = 0; i < blen; i ++)
    {
      c[i] += a[i] + b[i];
      c[i + 1] = c[i] / 10;
      c[i] = c[i] % 10;
    }
    if (c[blen] > 0)
    {
      clen = blen + 1;
    }
    else
    {
      clen = blen;
    }
    cnt ++;
/*
    cout << cnt << '\t';
    for (int i = clen - 1; i >=0; i --)
      cout << c[i];
    cout << endl;
*/
    for (int i = 0; i < clen; i ++)
    {
      a[i] = b[i];
      b[i] = c[i];
    }
    alen = blen; blen = clen;
  }
  cout << cnt << endl;
  return 0;
}
