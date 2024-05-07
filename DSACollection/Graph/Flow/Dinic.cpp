#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 1080;
const int oo = 1e9 + 7;

int c[N][N], f[N][N];
int dfs[N], cnt = 0;
int n, m, s, t;

vector<int> d;
vector<int> a[N];

bool findPath(int s, int t) {
  d.assign(n + 5, 0);
  queue<int> q;

  d[s] = 1;
  q.push(s);

  while (q.size()) {
    int u = q.front();
    q.pop();

    if (u == t) return true;

    for (int v : a[u])
      if (!d[v] && f[u][v] < c[u][v]) d[v] = d[u] + 1, q.push(v);
  }

  return false;
}

int flowing(int u, int t, int minFlowValue) {
  if (u == t) return minFlowValue;

  if (dfs[u] == cnt) return 0;

  dfs[u] = cnt;

  for (int v : a[u])
    if (f[u][v] < c[u][v])
      if (dfs[v] != cnt && d[v] == d[u] + 1)
        if (int x = flowing(v, t, min(minFlowValue, c[u][v] - f[u][v])))
          return f[u][v] += x, f[v][u] -= x, x;

  return 0;
}

int main() {
  cin >> n >> m >> s >> t;
  for (int i = 1, u, v, w; i <= m; i++)
    cin >> u >> v >> w, a[u].push_back(v), a[v].push_back(u), c[u][v] += w;

  int maxflow = 0;
  while (findPath(s, t))
    while (int x = (cnt++, flowing(s, t, oo))) maxflow += x;
  cout << maxflow;

  return 0;
}