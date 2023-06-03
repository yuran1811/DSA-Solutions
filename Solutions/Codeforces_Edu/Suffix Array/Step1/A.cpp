#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

ll suf[N], pos[N], tmp[N];
ll gap, lcp[N], n;
string s;

bool Cmp(ll x, ll y) {
  if (pos[x] != pos[y])
    return pos[x] < pos[y];
  x += gap;
  y += gap;
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

void Load_Data() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  n = s.size();
  Build();
}

int Scorpio() {
  Load_Data();
  cout << n << " ";
  for (int i = 0; i < n; i++)
    cout << suf[i] << " ";
  return 0;
}

int main() { Scorpio(); }
