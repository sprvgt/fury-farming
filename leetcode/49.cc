#include<

class Solution {
public:
    string getsymbol(string str)
    {
        int cnt[26] = {0};
        int n = str.length();
        for (int i = 0; i < n; ++ i)
            ++ cnt[str[i] - 'a'];
        string ret = "";
        for (int i = 0; i < 26; ++ i)
            ret += to_string(cnt[i]) + string(1, 'a' + i);
        return ret;
    }
    vector<string> anagrams(vector<string>& strs) {
        vector<string>  ret;
        unordered_map<string, vector<string>> dict;
        vector<vector<string>*> groups;
        int n = strs.size();
        int maxgroupsize = 2;
        for (int i = 0; i < n; ++ i)
        {
            string sym = getsymbol(strs[i]);
            if (dict.count(sym) == 0)
            {
                dict[sym] = vector<string>();
                dict[sym].push_back(strs[i]);
            }
            else
            {
                dict[sym].push_back(strs[i]);
                if (dict[sym].size() == 2)
                    groups.push_back(&(dict[sym]));
                if (dict[sym].size() > maxgroupsize)    maxgroupsize = dict[sym].size();
            }
        }
        if (groups.empty()) return ret;
        int ngroup = groups.size();
        for (int i = 0; i < maxgroupsize; ++ i)
        for (int j = 0; j < ngroup; ++ j)
            if (groups[j]->size() > i)  ret.push_back((*(groups[j]))[i]);
        return ret;
    }
};
