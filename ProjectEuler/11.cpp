#include<fstream>
#include<iostream>
using namespace std;

int getNum(int grid[][20], int x, int y)
{
  if (x < 0)
    return 1;
  if (y < 0)
    return 1;
  return grid[x][y];
}

int
main(int argc, char* argv[])
{
  int grid[20][20];
  int max = 0;
  ifstream fin("11.in");

  for (int i = 0; i < 20; i ++)
  {
    int left = 1, up = 1, leftup = 1, rightup = 1;
    for (int j = 0; j < 20; j ++)
    {
      fin >> grid[i][j];
      left = getNum(grid, i, j) * getNum(grid, i, j - 1) * getNum(grid, i, j - 2) * getNum(grid, i, j - 3); 
      if (left > max) max = left;
      up = getNum(grid, i, j) * getNum(grid, i - 1, j) * 
            getNum(grid, i - 2, j) * getNum(grid, i - 3, j);
      if (up > max) max = up;
      leftup = getNum(grid, i, j) * getNum(grid, i - 1, j - 1) *
              getNum(grid, i - 2, j - 2) * getNum(grid, i - 3, j - 3);
      if (leftup > max) max = leftup;
      rightup = getNum(grid, i, j) * getNum(grid, i - 1, j + 1) * 
              getNum(grid, i - 2, j + 2) * getNum(grid, i - 3, j + 3);
      if (rightup > max) max = rightup;
    }
  }

  cout << max << endl;

  return 0;
}
