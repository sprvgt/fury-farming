#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

struct status
{
  int pos;
  char ch;
};

int pos[4][4] = {{1, 1, 1, 1},
                 {1, -1, 1, -1},
                 {1, -1, -1, 1},
                 {1, 1, -1, -1}};
char chch[4][4] = {{'1', 'i', 'j', 'k'},
                   {'i', '1', 'k', 'j'},
                   {'j', 'k', '1', 'i'},
                   {'k', 'j', 'i', '1'}};

int convert(char ch)
{
  if (ch == '1')  return 0;
  if (ch == 'i')  return 1;
  if (ch == 'j')  return 2;
  if (ch == 'k')  return 3;
}

void multiple(status& sta, char ch)
{
  int ida = convert(sta.ch);
  int idb = convert(ch);
  sta.pos *= pos[ida][idb];
  sta.ch = chch[ida][idb];
}

void multiple(char ch, status& sta)
{
  int ida = convert(ch);
  int idb = convert(sta.ch);
  sta.pos *= pos[ida][idb];
  sta.ch = chch[ida][idb];
}

int main()
{
  ifstream fin("pC.in");
  ofstream fout("pC.out");

  int t, T;
  vector<int> posI, posK;
  vector<status> staList;

  fin >> T;

  for (t = 1; t <= T; t ++)
  {
    int l, x;
    string baseStr;

    posI.clear();
    posK.clear();
    staList.clear();

    fin >> l >> x;
    fin >> baseStr;

    ostringstream os;
    for (int i = 0; i < x; i ++)
      os << baseStr;

    string str = os.str();

    bool flag = false;

    int len = x * l;
    cout << len << endl;

    status s;
    s.pos = 1; s.ch = '1';
    for (int i = 0; i < len; i ++)
    {
      multiple(s, str[i]);
      staList.push_back(s);
      if (s.pos == 1 && s.ch == 'i')
        posI.push_back(i);
    }
    s.pos = 1; s.ch = '1';
    for (int i = len - 1; i >= 0; i --)
    {
      multiple(str[i], s);
      if (s.pos == 1 && s.ch == 'k')
        posK.push_back(i);
    }

    int ilen = posI.size(), klen = posK.size();
    for (int i = 0; i < ilen; i ++)
      for (int k = klen - 1; k >= 0 && posK[k] > posI[i]; k --)
      {
        /*
        s.pos = staList[posI[i]].pos; s.ch = staList[posI[i]].ch;
        multiple(s, 'j');
        if (s.pos == staList[posK[k] - 1].pos && s.ch == staList[posK[k] - 1].ch)
        {
          flag = true;
          break;
        }
        */

        s.pos = 1; s.ch = '1';
        for (int p = posI[i] + 1; p <= posK[k] - 1; p ++)
          multiple(s, str[p]);
        if (s.pos == 1 && s.ch == 'j')
        {
          flag = true;
          break;
        }
      }

    fout << "Case #" << t << ": " << (flag ? "YES" : "NO") << endl;
  }

  return 0;
}
