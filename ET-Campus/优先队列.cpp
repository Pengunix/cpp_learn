#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;

class cmp {
public:
  bool operator()(const ll &u, const ll &v) const { return u < v; }
};

int main() {
  int q;
  cin >> q;
  priority_queue<ll, vector<ll>, cmp> pq;

  ll sum = 0;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      ll x;
      cin >> x;
      pq.push(x);
      sum += x;
    } else if (pq.size()) {
      sum -= pq.top();
      pq.pop();
    }
    cout << sum << '\n';
  }
}