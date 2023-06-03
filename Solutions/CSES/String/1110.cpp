#include <bits/stdc++.h>
using namespace std;

int Solve(string &s) {
  int a = 0, n = s.size();
  s += s;
  for (int b = 0; b < n; b++)
    for (int i = 0; i < n; i++) {
      if (a + i == b || s[a + i] < s[b + i]) {
        b += max(0, i - 1);
        break;
      }
      if (s[a + i] > s[b + i]) {
        a = b;
        break;
      }
    }
  return a;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  rotate(begin(s), begin(s) + Solve(s), end(s));
  return cout << s, 0;
}
