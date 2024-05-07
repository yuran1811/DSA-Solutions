#include <iostream>

using std::cin;
using std::cout;

const int N = 1e5 + 5;

int a[N];

struct Node {
  int lz, val;

  Node() : lz(0), val(0) {}
  Node(int lz, int val) : lz(lz), val(val) {}
};

struct Lazy {
  Node t[N * 4];

  void build(int l, int r, int i) {
    if (l == r) return void(t[i].val = a[l]);

    int m = (l + r) >> 1;
    build(l, m, i << 1);
    build(m + 1, r, i << 1 | 1);

    t[i].val = t[i << 1].val + t[i << 1 | 1].val;
  }

  void down(int i) {
    int &val = t[i].lz;
    t[i << 1].val += val;
    t[i << 1 | 1].val += val;
    val = 0;
  }

  void update(int l, int r, int i, int u, int v, const int &val) {
    if (v < l || r < u) return;
    if (l == r) {
      t[i].val += (r - l + 1) * val;
      t[i].lz += val;
      return;
    }

    down(i);

    int m = (l + r) >> 1;
    update(l, m, i << 1, u, v, val);
    update(m + 1, r, i << 1 | 1, u, v, val);

    t[i].val = t[i << 1].val + t[i << 1 | 1].val;
  }

  int get(int l, int r, int i, int u, int v) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return t[i].val;

    down(i);

    int m = (l + r) >> 1;
    return get(l, m, i << 1, u, v) + get(m + 1, r, i << 1 | 1, u, v);
  }
};

void loadData(int &n, Lazy &T) {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  T.build(1, n, 1);
}

int main() {
  Lazy T;
  int n, q;

  loadData(n, T);

  cin >> q;
  for (int c, u, v, val; q--;) {
    cin >> c >> u >> v;

    if (c)
      cout << T.get(1, n, 1, u, v) << '\n';
    else
      cin >> val, T.update(1, n, 1, u, v, val);
  }

  return 0;
}