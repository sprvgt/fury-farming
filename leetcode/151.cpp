#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    void reversewords(string &s, int l, int r)
    {
        if (0 <= l && l < r && r <= s.length())
        {
            int mid = l + (r - l) / 2;
            for (int i = l; i < mid; i ++)
            {
                char ch;
                ch = s[i]; s[i] = s[r + l - i - 1]; s[r + l - i - 1]= ch;
            }
        }
    }

    void reverseWords(string &s) {
        int cnt = 0;
        int len = s.length();
        int ptr = 0, dir = 0;
        while (ptr < len)
        {
            while (ptr < len && s[ptr] == ' ')   ptr ++;
            if (ptr == len)  break;
            if (cnt)
                s[dir ++] = ' ';
            int l = 0;
            while (ptr < len && s[ptr] != ' ')  
            {
                s[dir] = s[ptr];
                cout << s[dir] << endl;
                dir ++;
                ptr ++;
                l ++;
            }
            cout << "---" << endl;
            reversewords(s, dir - l, dir);
            cnt ++;
        }
        cout << s << endl;
        s.resize(dir);
        cout << s << endl;
        cout << dir << endl;
        reversewords(s, 0, dir);
        cout << s << endl;
    }
};

int main()
{
  string str = "    a   b   ";
  Solution().reverseWords(str);
  cout << str << endl;
  return 0;
}
