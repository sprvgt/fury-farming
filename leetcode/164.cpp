#include<iostream>
#include<vector>
using namespace std;

class Solution {

public:

    void bucketSort(vector<int> &num)

    {

        int len = num.size();

        vector<int> buffer[2];
        buffer[0].swap(num);

        for (int i = 0; i < buffer[0].size(); i ++)
          cout << buffer[0][i] << '\t';
        cout << endl;

        int ptr = 0;
        int bit = 1;

        while (bit)
        {
            int dir = (ptr + 1) % 2;
            buffer[dir].clear();
            for (int i = 0; i < len; i ++)
                if (!(buffer[ptr][i] & bit))
                    buffer[dir].push_back(buffer[ptr][i]);
            for (int i = 0; i < len; i ++)
                if (buffer[ptr][i] & bit)
                    buffer[dir].push_back(buffer[ptr][i]);
            ptr = dir;
            bit <<= 1;

            for (int i = 0; i < buffer[ptr].size(); i ++)
              cout << buffer[ptr][i] << '\t';
            cout << endl;
        }

        buffer[ptr].swap(num);

    }



    int maximumGap(vector<int> &num) {

        if (num.size() < 2)

            return 0;

        

        bucketSort(num);

        

        int n = num.size();

        int ret = 0x80000000;

        

        for (int i = 1; i < n; i ++)

            if (num[i] - num[i - 1] > ret)

                ret = num[i] - num[i - 1];

                

        return ret;

    }

};

int main()
{
  int n;
  vector<int> num;

  cin >> n;
  for (int i = 0; i < n; i ++)
  {
    int tmp;
    cin >> tmp;
    num.push_back(tmp);
  }

  cout << Solution().maximumGap(num) << endl;

  return 0;
}
