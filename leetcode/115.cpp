#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int lens = S.length(),
            lent = T.length();
        vector<int> cnt(lens, 0);
        for (int i = 0; i < lent; i ++)
        {
            int sum = 0;
            for (int j = 0; j < lens; j ++)
            {
                int tmp = cnt[j];
                if (T[i] == S[j])
                    if (i == 0)
                        cnt[j] = 1;
                    else
                        cnt[j] += sum;
                sum += tmp;
            }
        }

        cout << cnt[lens - 1] << endl;
        cout << "HELLO THERE" << endl;
        return cnt[lens - 1];
    }
};

int main()
{
  cout << Solution().numDistinct("aacaacca", "ca") << endl;
  return 0;
}
