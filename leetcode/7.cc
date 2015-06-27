#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return x;
        bool minus  = false;
        if (x < 0)  
            {
                minus = true; x = -x;
            }
        int y = 0;
        while (x)
        {
            if (y > 0x7fffffff / 10 ||
                y == 0x7fffffff / 10 && x % 10 > 0x7fffffff % 10)
            {
                y = 0;
                break;
            }
            y = y * 10 + x % 10;
            x /= 10;
            cout << y << endl;
        }
        if (minus)  y = -y;
        return y;
    }
};

int main()
{
  cout << Solution().reverse(-2147483648) << endl;
  return 0;
}
