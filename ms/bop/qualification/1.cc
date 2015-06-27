#include<iostream>
#include<unordered_map>
#include<cstdlib>
using namespace std;

class Solution
{
  public:
    int getDayNum(string m1, string d1, string y1,
                  string m2, string d2, string y2)
    {
      int sm, sd, sy, em, ed, ey;
      sm = monthDict[m1]; sd = atoi(d1.substr(0, d1.length() - 1).c_str()); sy = atoi(y1.c_str());
      em = monthDict[m2]; ed = atoi(d2.substr(0, d2.length() - 1).c_str()); ey = atoi(y2.c_str());
      if (sm == em && sd == ed && sy == ey)
        if (isYear(sy) && sm == 2 && sd == 29)
          return 1;
        else
          return 0;

      if (sy == ey)
        if (isYear(sy) && before229(sm, sd) && after229(em, ed))
          return 1;
        else
          return 0;
      
      int ret = 0;
      if (isYear(sy) && before229(sm, sd))  ++ ret;
      if (isYear(ey) && after229(em, ed)) ++ ret;
      -- ey;
      if (sy >= ey)  return ret;
      ret += (ey / 4) - (sy / 4);
      ret -= (ey / 100) - (sy / 100);
      ret += (ey / 400) - (sy / 400);
      return ret;
    }

    Solution()
    {
      string monthName[] = {"January", "February", "March", "April", 
                            "May", "June", "July", "August", "September", 
                            "October", "November" , "December"};
      for (int i = 0; i < 12; i ++)
        monthDict[monthName[i]] = i + 1;
    }

  private:
    unordered_map<string, int>  monthDict;

    bool before229(int month, int day)
    {
      if (month < 2 || month == 2 && day <= 29)
        return true;
      return false;
    }

    bool after229(int month, int day)
    {
      if (month > 2 || month == 2 && day == 29)
        return true;
      return false;
    }

    bool isYear(int year)
    {
      if (year % 4 == 0 && year % 100 != 0)
        return true;
      if (year % 400 == 0)
        return true;
      return false;
    }
};

int main()
{
  Solution s;
  int t, T;
  while (cin >> T)
  {
    for (t = 1; t <= T; t ++)
    {
      cout << "Case #" << t << ": ";
      string m1, d1, y1;
      string m2, d2, y2;
      cin >> m1 >> d1 >> y1;
      cin >> m2 >> d2 >> y2;
      cout << s.getDayNum(m1, d1, y1, m2, d2, y2) << endl;
    }
  }
  return 0;
}
