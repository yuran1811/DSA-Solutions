#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int N = 1e6 + 5;

ll suf[N], pos[N], tmp[N], lcp[N], gap;
string s, t, Combine, res = "";
int n, m;

bool Cmp(ll x, ll y) {
  if (pos[x] != pos[y])
    return pos[x] < pos[y];
  x += gap;
  y += gap;
  return (x < n && y < n) ? pos[x] < pos[y] : x > y;
}

void Build() {
  for (int i = 0; i < n; i++)
    suf[i] = i, pos[i] = Combine[i] == '$' ? 0 : Combine[i];
  for (gap = 1;; gap <<= 1) {
    sort(suf, suf + n, Cmp);
    for (int i = 0; i < n - 1; i++)
      tmp[i + 1] = tmp[i] + Cmp(suf[i], suf[i + 1]);
    for (int i = 0; i < n; i++)
      pos[suf[i]] = tmp[i];
    if (tmp[n - 1] == n - 1)
      break;
  }
}

void LCP_Build() {
  for (int i = 0, k = 0; i < n; i++) {
    if (k)
      k--;
    int j = suf[pos[i] - 1];
    while (i + k < n && j + k < n && Combine[i + k] == Combine[j + k])
      k++;
    lcp[pos[i]] = k;
  }
}

void Load_Data() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s >> t;
  m = s.size();
  Combine = s + "$" + t + "#";
  n = Combine.size();
  Build();
  LCP_Build();
}

int Scorpio() {
  Load_Data();
  ll LCS_lth = 0, id;
  vector<ll> f(n);
  for (int i = 0; i < n; i++)
    f[i] = suf[i] >= m ? 2 : 1;
  for (int i = 1; i < n; i++)
    if (f[i] != f[i - 1] && LCS_lth < lcp[i])
      LCS_lth = lcp[i], id = suf[i];
  for (int i = id; i < id + LCS_lth; i++)
    cout << Combine[i];
  return 0;
}

int main() { Scorpio(); }
