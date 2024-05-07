#include <iostream>

using std::cin;
using std::cout;

const int N = 1e5 + 5;

struct SegTree {
  int t[4 * N];

  SegTree() {}
  SegTree(int n, int a[]) { build(1, n, 1, a); }

  void build(int l, int r, int i, int a[]) {
    if (l == r) return void(t[i] = a[l]);

    int m = (l + r) >> 1;
    build(l, m, i << 1, a);
    build(m + 1, r, i << 1 | 1, a);

    t[i] = t[i << 1] + t[i << 1 | 1];
  }

  void up(int l, int r, int i, int pos, int val) {
    if (pos < l || r < pos) return;
    if (l == r) return void(t[i] = val);

    int m = (l + r) >> 1;
    up(l, m, i << 1, pos, val);
    up(m + 1, r, i << 1 | 1, pos, val);

    t[i] = t[i << 1] + t[i << 1 | 1];
  }

  int get(int l, int r, int i, int u, int v) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return t[i];

    int m = (l + r) >> 1;
    return get(l, m, i << 1, u, v) + get(m + 1, r, i << 1 | 1, u, v);
  }
};

int main() {
  int n;
  cin >> n;

  int a[n + 5];
  for (int i = 1; i <= n; i++) cin >> a[i];

  SegTree T(n, a);

  return 0;
}