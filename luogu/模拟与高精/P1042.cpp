// 评测通过
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;

char c;
int hua_11 = 0;
int hua_opp_11 = 0;
                
int hua_21 = 0;
int hua_opp_21 = 0;

stringstream res11;
stringstream res21;

int main() {
  while (1) {
    cin >> c;
    if (c == 'W') {
      hua_11++;
      hua_21++;
    }
    else if (c == 'L') {
      hua_opp_11++;
      hua_opp_21++;
    } else if (c == 'E') {
      cout << res11.str();
      cout << hua_11 << ':' << hua_opp_11 << endl;

      cout << endl;

      cout << res21.str();
      cout << hua_21 << ':' << hua_opp_21 << endl;
      break;
    }

    if (max(hua_11, hua_opp_11) >= 11 && abs(hua_11-hua_opp_11) >= 2) {
      res11 << hua_11 << ':' << hua_opp_11 << endl;
      hua_11 = 0;
      hua_opp_11 = 0;
    }
    if (max(hua_21, hua_opp_21)>=21 && abs(hua_21-hua_opp_21) >= 2) {
      res21 << hua_21 << ':' << hua_opp_21 << endl;
      hua_21 = 0;
      hua_opp_21 = 0;
    }
  }
}