#include <algorithm>
#include <iostream>
#define sz(s) (int(s.size()))
using namespace std;

typedef long long ll;

const int N = 1e6 + 5;

ll suf[N], pos[N], tmp[N], lcp[N], gap;
string s;
int n;

bool Cmp(ll x, ll y) {
  if (pos[x] != pos[y])
    return pos[x] < pos[y];
  x += gap, y += gap;
  return (x < n && y < n) ? pos[x] < pos[y] : x > y;
}

void Build() {
  for (int i = 0; i < n; i++)
    suf[i] = i, pos[i] = s[i];
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

void LCP() {
  for (int i = 0, k = 0; i < n; i++) {
    if (pos[i] == n - 1) {
      k = 0;
      continue;
    }
    ll j = suf[pos[i] + 1];
    while (i + k < n && j + k < n && s[i + k] == s[j + k])
      k++;
    lcp[pos[i]] = k;
    if (k)
      k--;
  }
}

void Load_Data() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  n = sz(s);
  Build();
  LCP();
  cout << n << " ";
  for (int i = 0; i < n; i++)
    cout << suf[i] << " \n"[i == n - 1];
  cout << "0 ";
  for (int i = 0; i < n - 1; i++)
    cout << lcp[i] << " ";
}

int Scorpio() {
  Load_Data();
  return 0;
}

int main() { Scorpio(); }
