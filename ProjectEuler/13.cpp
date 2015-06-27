#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;

int
main(int argc, char* argv[])
{
  ifstream fin("13.in");
  int nums[100][60];
  for (int i = 0; i < 100; i ++)
    for (int j = 49; j >= 0; j --)
    {
      char ch;
      fin >> ch;
      nums[i][j] = (int)(ch - '0');
    }
  fin.close();

 int ans[60];
 memset(ans, 0, sizeof(ans));
 for (int i = 0; i < 50; i ++)
 { 
  for (int j = 0; j < 100; j ++)
    ans[i] += nums[j][i];
  ans[i + 1] += ans[i] / 10;
  ans[i] %= 10;
 }
 for (int i = 50; i >= 0; i --)
  cout << ans[i];
 cout << endl;
 return 0;
}

