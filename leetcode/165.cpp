#include<iostream>
#include<cstring>
#include<vector>
#include<sstream>
using namespace std;

class Solution {

public:

    vector<string> &split(const string &s, char delim)

    {

        stringstream ss(s);

        string item;

        vector<string> elem;

        while (getline(ss, item, delim))    {

            elem.push_back(item);

        }

        return elem;

    }



    int compareVersion(string version1, string version2) {

        vector<string> v1 = split(version1 + '.', '.');

        vector<string> v2 = split(version2 + '.', '.');

        int l1 = v1.size(), l2 = v2.size();

        int len = min(l1, l2);

        for (int i = 0; i < len; i ++)

            if (v1[i] != v2[i])

                return v1[i] < v2[i];

        return l1 < l2;

    }

};

int main()
{
  Solution s;

  cout << s.compareVersion("0", "1");

  return 0;
}
