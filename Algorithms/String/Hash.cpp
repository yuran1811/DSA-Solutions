#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll BASE = 311;

ll Pow[N], Hash[N], hashT;
vector<int> res;
string s, t;
int n, m;

void Build() {
  n = s.size();
  m = t.size();
  s = " " + s;
  t = " " + t;

  Pow[0] = 1;
  for (int i = 1; i <= n; i++)
    Pow[i] = Pow[i - 1] * BASE % MOD,
    Hash[i] = (Hash[i - 1] * BASE + s[i]) % MOD;

  for (int i = 1; i <= m; i++)
    hashT = (hashT * BASE + t[i]) % MOD;
}

ll Get(int i, int j) {
  return (Hash[j] - Hash[i - 1] * Pow[j - i + 1] + MOD * MOD) % MOD;
}

void stringMatching() {
  for (int i = 1; i <= n - m + 1; i++)
    if (hashT == Get(i, i + m - 1))
      res.push_back(i);

  cout << res.size() << '\n';
  for (int x : res)
    cout << x << " ";
}

void loadData() { cin >> t >> s; }

int main() {
  loadData();
  Build();
  stringMatching();
  return 0;
}
