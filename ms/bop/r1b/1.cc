#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct card
{
  string label;
  unsigned long long num;
  unsigned long long cache;
  vector<int> edges;
  card(string l):num(1), cache(0), label(l)
  {
  }
  bool sameAs(card &c)
  {
    if (label[0] == c.label[0])
      return true;
    return false;
  }
};

int main()
{
  int t, T;
  while (cin >> T)
  {
    for (t = 1; t <= T; t ++)
    {
      cout << "Case #" << t << ": ";
      int n;
      vector<card> cards;
      cin >> n;
      for (int i = 0; i < n; i ++)
      {
        string label;
        cin >> label;
        cards.push_back(card(label));
        int len = cards.size();
        for (int j = 0; j < len  - 1; j ++)
        {
          if (!cards[j].sameAs(cards[len - 1]))
          {
            cards[j].edges.push_back(len - 1);
            cards[len - 1].edges.push_back(j);
          }
        }
      }
      for (int k = 1; k < n; k ++)
      {
        cout << "iteration " << k << endl;
        for (int i = 0; i < n; i ++)
        {
          cout << "card " << i << endl;
          cards[i].cache = 0;
          int len = cards[i].edges.size();
          cout << "#edges " << len << endl;
          for (int j = 0; j < len; j ++)
          {
            int ptr = cards[i].edges[j];
            cards[i].cache += cards[ptr].num;
            cout << cards[ptr].label << ' ' << cards[ptr].num << endl;
          }
          cout << "cache " << cards[i].cache << endl;
        }
        for (int i = 0; i < n; i ++)
          cards[i].num = cards[i].cache;
      }
      unsigned long long sum = 0;
      for (int i = 0; i < n; i ++)
        sum += cards[i].num;
      cout << sum << endl;
    }
  }
  return 0;
}


