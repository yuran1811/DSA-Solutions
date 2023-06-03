#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 5;

int n, m;

struct Edge {
  int u, v, w;
  bool operator<(const Edge &a) const { return w < a.w; }
} e[N];

struct DSU {
  vector<int> f;
  int n;

  DSU() {}
  DSU(int n) : n(n) { f.resize(n + 5, -1); }

  int getRoot(int u) { return f[u] < 0 ? u : f[u] = getRoot(f[u]); }
  bool merge(int u, int v) {
    u = getRoot(u), v = getRoot(v);
    if (u == v)
      return false;
    if (f[u] > f[v])
      swap(u, v);
    return f[u] += f[v], f[v] = u, 1;
  }
};

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
    cin >> e[i].u >> e[i].v >> e[i].w;
  sort(e + 1, e + 1 + m);

  DSU dsu(n);
  long long res = 0;
  for (int i = 1; i <= m; i++)
    if (dsu.merge(e[i].u, e[i].v))
      res += e[i].w;
  cout << res;

  return 0;
}