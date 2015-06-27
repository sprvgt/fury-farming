#include<iostream>
using namespace std;

class Solution {

public:

    string intToRoman(int num) {

        string TH, H, TE, O;

        int th, h, te, o;

        

        th = num / 1000;

        if (th > 0)

        {

            TH = string(th, 'M');

            num -= th * 1000;

        }

        else TH = "";

        cout << TH << endl;

        

        h = num / 100;

        if (h == 9)

            H = "CM";

        else

        if (h >= 5)

            H = "D" + string(h - 5, 'C');

        else

        if (h == 4)

            H = "CD";

        else

        if (h > 0)

            H = string(h, 'C');

        else

            H = "";

        num -= h * 100;

        cout << H << endl;

            

        te = num / 10;

        if (te == 9)

            TE = "XC";

        else

        if (te >= 5)

            TE = "L" + string(te - 5, 'X');

        else

        if (te == 4)

            TE = "XL";

        else

        if (te > 0)

            TE = string(te, 'X');

        else

            TE = "";

        cout << TE << endl;

        num -= te * 10;

        

        o = num;

        cout << num << endl;

        if (o == 9)

            O = "IX";

        else

        if (o >= 5)

            O = "V" + string(te - 5, 'I');

        else

        if (o == 4)

            O = "IV";

        else

        if (o > 0)

            O = string(te, 'I');

        else

            O = "";

        cout << O << endl;    

        

        return TH + H + TE + O;  

    }

};

int main()
{
  cout << Solution().intToRoman(5) << endl;
  return 0;
}
