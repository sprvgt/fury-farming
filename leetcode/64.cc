#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid.size();
        if (n == 0) return 0;
        vector<int> sum(n, 0);
        sum[0] = grid[0][0];
	cout << sum[0];
        for (int i = 0; i < m; ++ i)
        for (int j = 0; j < n; ++ j)
        {
            if (i == 0 && j == 0)   continue;
            if (i == 0)
                sum[j] = sum[j - 1] + grid[i][j];
            else
            if (j == 0)
                sum[j] += grid[i][j];
            else
                sum[j] = min(sum[j - 1], sum[j]) + grid[i][j];
	     cout << sum[j];
        }
        return sum[n - 1];
    }
};

int main()
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>>	grid(m, vector<int>(n));
	for (int i = 0; i < m; ++ i)
	for (int j = 0; j < n; ++ j)
		cin >> grid[i][j];
	return Solution().minPathSum(grid);
}
