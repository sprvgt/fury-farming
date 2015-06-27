#include<iostream>
#include<map>
using namespace std;

int main()
{
  map<char, int> dict;

  dict['c'] = 0;

  cout << (dict.find('c') == dict.end()) << endl;

  return 0;
}
