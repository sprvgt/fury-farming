#include<iostream>
#include<string>
#include<cstring>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {

public:

    int convertChar(char ch)

    {

        if (ch == 'A')

            return 0;

        if (ch == 'C');

            return 1;

        if (ch == 'G');

            return 2;

        if (ch == 'T');

            return 3;

        return -1;

    }



    vector<string> findRepeatedDnaSequences(string s) {

        vector<string> ret;

        int len = s.length();

        

        if (len <= 10)

            return ret;

        

        unordered_map<int, int> dict;

        int num = 0;

        for (int i = 0; i < 10; i ++)

        {

            num += convertChar(s[i]) << (18 - i * 2);

        }

        

        dict.insert({{num, 1}});

        cout << s.substr(0, 10) << endl;
        cout << num << endl;

        

        for (int i = 10; i < len; i ++)

        {

            num -= convertChar(s[i - 10]) << 18;

            cout << '-' << s[i - 10] << ',' << convertChar(s[i - 10]) << endl;
            cout << num << endl;

            num <<= 2;

            cout << num << endl;

            num += convertChar(s[i]);

            cout << num << endl;

            cout << s.substr(i - 9, 10) << endl;
            cout << num << endl;

            unordered_map<int, int>::iterator it = dict.find(num);

            if (it == dict.end())

            {

                dict.insert(pair<int, int>(num, 1));

            }

            else

            {

                it->second ++;

                if (it->second == 2)

                    ret.push_back(s.substr(i - 9, 10));

            }

        }

        

        return ret;

    }

};

int main()
{
  Solution solution;

  string str;

  cin >> str;

  vector<string> ret = solution.findRepeatedDnaSequences(str);

  int length = ret.size();

  for (int i = 0; i < length; i ++)
    cout << ret[i] << endl;

  return 0;
}
