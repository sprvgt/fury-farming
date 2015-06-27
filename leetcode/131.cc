#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool judgePalindrome(string s)
    {
        if (equal(s.begin(), s.begin() + s.size() / 2, s.rbegin()))
            return true;
        return false;
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<int>> edges(n, vector<int>());
        for (int i = n - 1; i >= 0; i --)
        {
            edges[i].push_back(i + 1);
            for (int j = i + 2; j <= n; j ++)
                if (judgePalindrome(s.substr(i, j - i)))
                    edges[i].push_back(j);
        }
       
        cout << "edge built" << endl;

        vector<vector<string>> ret;
        vector<string> trace;
        for (int i = 0; i < edges[0].size(); i ++)
        {
            trace.push_back(s.substr(0, edges[0][i]));
            dfs(s, edges[0][i], edges, trace, ret);
            trace.pop_back();
        }
        return ret;
    }
    
    void dfs(string s, int label, vector<vector<int>> &edges,
            vector<string>& trace, vector<vector<string>> &ret)
    {
        int n = s.length();
        if (label == n)
        {
            cout << "try to push" << endl;
            ret.push_back(trace);
            cout << "push successful" << endl;
            return;
        }
        for (int i = 0; i < edges[label].size(); i ++)
        {
            trace.push_back(s.substr(label, edges[label][i]));
            dfs(s, edges[label][i], edges, trace, ret);
            trace.pop_back();
        }
    }
};

int main()
{
  cout << Solution().partition("a").size() << endl;
  return 0;
}
