#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];

struct SegTree {
  int t[4 * N];

  void build(int l, int r, int i) {
    if (l == r)
      return void(t[i] = a[l]);

    int m = (l + r) >> 1;
    build(l, m, i << 1);
    build(m + 1, r, i << 1 | 1);

    t[i] = t[i << 1] + t[i << 1 | 1];
  }

  void up(int l, int r, int i, int pos, int val) {
    if (pos < l || r < pos)
      return;

    if (l == r)
      return void(t[i] = val);

    int m = (l + r) >> 1;
    up(l, m, i << 1, pos, val);
    up(m + 1, r, i << 1 | 1, pos, val);

    t[i] = t[i << 1] + t[i << 1 | 1];
  }

  int get(int l, int r, int i, int u, int v) {
    if (v < l || r < u)
      return 0;

    if (u <= l && r <= v)
      return t[i];

    int m = (l + r) >> 1;
    return get(l, m, i << 1, u, v) + get(m + 1, r, i << 1 | 1, u, v);
  }
} T;

void loadData() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  T.build(1, n, 1);
}

int main() {
  loadData();
  return 0;
}