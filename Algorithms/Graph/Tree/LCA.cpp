#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 5, LOG = 20;

vector<pair<int, int>> a[N];
int high[N], d[N], par[N], f[N][LOG + 5];
int n;

void DFS(int u, int p) {
  for (pair<int, int> x : a[u]) {
    int v = x.first;
    int w = x.second;

    if (v == p)
      continue;

    high[v] = high[u] + 1;
    d[v] = d[u] + w;
    par[v] = u;

    DFS(v, u);
  }
}

void Sparse_Table() {
  DFS(1, 0);

  high[0] = -1;

  for (int j = 1; j <= LOG; j++)
    for (int i = 1; i <= n; i++)
      f[i][j] = f[f[i][j - 1]][j - 1];
}

int LCA(int u, int v) {
  if (high[u] < high[v])
    swap(u, v);

  for (int i = LOG; i >= 0; i--)
    if (high[f[u][i]] >= high[v])
      u = f[u][i];

  if (u == v)
    return u;

  for (int i = LOG; i >= 0; i--)
    if (f[u][i] != f[v][i])
      u = f[u][i], v = f[v][i];

  return f[u][0];
}