#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e6 + 5;
const int BASE = 311;
const int MOD = 1e9 + 1993;

int n, m;
ll Pow[N];

struct HASH {
  ll table[N];

  void init(string s, int &n) {
    n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++)
      table[i] = (1LL * table[i - 1] * BASE + s[i] - 'a' + 1) % MOD;
  }

  ll get(int i, int j) {
    return (table[j] - 1LL * table[i - 1] * Pow[j - i + 1] + 1LL * MOD * MOD) %
           MOD;
  }
} hashOrigin, hashPattern;

void factorialBuild() {
  Pow[0] = 1;
  for (int i = 1; i < N; i++)
    Pow[i] = 1LL * Pow[i - 1] * BASE % MOD;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  factorialBuild();

  string s, t;
  cin >> s >> t;

  hashOrigin.init(s, n);
  hashPattern.init(t, m);

  int cnt = 0;
  for (int i = 1; i <= n - m + 1; i++)
    if (hashPattern.table[m] == hashOrigin.get(i, i + m - 1))
      cnt++;

  cout << cnt;

  return 0;
}
