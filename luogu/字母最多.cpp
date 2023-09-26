#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
  map<char, int> m;
  string s;
  cin >> s;

  for (const char &c : s) {
    map<char, int>::iterator it = m.find(c);
    if (it == m.end() && it->first != c)
      m.insert(pair<char, int>(c, 1));
    else
      m.find(c)->second ++;
  }
  int max = 0;
  char maxm;
  for (const pair<char, int> &p : m) {
    if (p.second > max) {
      max = p.second;
      maxm = p.first;
    } 
  }
  cout << maxm << '\n';
  cout << max << '\n';
}