#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;

vector<int> a;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  // 必须在unique之前 sort O(nlogn) 或是其他
  sort(a.begin(), a.end());
  // unique会把重复的数据丢在末尾，并返回第一个重复数据的迭代器
  a.erase(unique(a.begin(), a.end()), a.end());

  for (int &i : a)
    cout << i << '\n';
}