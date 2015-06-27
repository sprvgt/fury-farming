#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int
main(int argc, char* argv[])
{
  ifstream fin("22.in");
  string input;
  fin >> input;
  cout << input.length();
  return 0;
}
