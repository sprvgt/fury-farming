#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Solution {
public:
    bool oneDiff(string a, string b)
    {
        int n = a.length();
        if (n != b.length())    return false;
        int cnt = 0;
        for (int i = 0; i < n; i ++)
        {
            if (a[i] != b[i])
                cnt ++;
            if (cnt > 1)    return false;
        }
        if (cnt == 1)   return true;
        return false;
    }
    
    void updateEdges(string word, string endword, unordered_set<string>& wordDict, unordered_map<string, vector<string>>& edges)
    {
        int n = word.length();
        if (n != endword.length())
            return;
        
        vector<string> elist;
        
        string tmpword;
        for (int i = 0; i < n; i ++)
        {
            tmpword = word;
            for (char ch = 'a'; ch <= 'z'; ch ++)
            {
                if (ch == word[i])  continue;
                tmpword[i] = ch;
                if (wordDict.count(tmpword))
                    elist.push_back(tmpword);
            }
        }
        if (wordDict.count(endword) == 0 && oneDiff(word, endword))
            elist.push_back(endword);
        if (!elist.empty())
            edges[word] = elist;
    }

    void backtrace(vector<pair<string, int>>& que, int label, vector<vector<string>>& ret, string endword)
    {
        stack<string> st;
        st.push(endword);
        while (label)
        {
            st.push(que[label].first);
            label = que[label].second;
        }
        st.push(que[0].first);
        vector<string> trace;
        while (!st.empty())
        {
            trace.push_back(st.top());
            st.pop();
        }
        ret.push_back(trace);
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string>& wordDict) {
        vector<vector<string>>  ret;
        
        int n = beginWord.length();
        if (n != endWord.length())
            return ret;
        
        unordered_map<string, vector<string>> edges;
        
        if (wordDict.count(beginWord) == 0)
            updateEdges(beginWord, endWord, wordDict, edges);
        for (unordered_set<string>::iterator it = wordDict.begin();
            it != wordDict.end(); ++ it)
        {
            updateEdges(*it, endWord, wordDict, edges);
        }

        cout << "Edges built" << endl;

        vector<pair<string, int>> que;
        int front = 0;
        int minL = 0x7fffffff;
        unordered_map<string, int> visited;
        que.push_back(make_pair(beginWord, 0));
        visited[beginWord] = 1;
        while(!que.empty())
        {
            string str = que[front].first;
            int dep = visited[str];
            cout << "(" << str << "," << dep << ")" << endl;
            if (dep >= minL)    break;
            if (edges.count(str))
            {
                int l = edges[str].size();
cout << l << endl;
                for (int i = 0; i < l; i ++)
                    if (!visited.count(edges[str][i]))
                    {
                        if (edges[str][i] == endWord && dep + 1 <= minL)
                        {
                            minL = dep + 1;
                            backtrace(que, front, ret, endWord);
                        }
                        que.push_back(make_pair(edges[str][i], front));
                        visited[edges[str][i]] = dep + 1;
                    }
            }
            ++ front;
        }
        return ret;
    }
};

int main()
{
string strList[] = {"hot","cog","dog","tot","hog","hop","pot","dot"};
unordered_set<string> input;
for (int i = 0; i < 8; i ++)
	input.insert(strList[i]);
cout << Solution().findLadders("hot", "dog", input).size() << endl;
return 0;
}

