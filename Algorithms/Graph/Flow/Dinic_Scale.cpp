#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Dinic {
  vector<int> to, nxt, capa, f;
  vector<int> head, d, use;
  int lim;

  Dinic() {}
  Dinic(int n) {
    head.assign(n + 5, -1);
    d.assign(n + 5, 0);
    use.assign(n + 5, 0);
    // to.clear(); nxt.clear(); capa.clear(); f.clear();
  }

  void addPoint(int toValue, int nxtValue, int capaValue, int fValue) {
    to.push_back(toValue);
    nxt.push_back(nxtValue);
    capa.push_back(capaValue);
    f.push_back(fValue);
  }

  int addEdge(int u, int v, int c, bool r = false) {
    addPoint(v, head[u], c, 0);
    head[u] = to.size() - 1;

    addPoint(u, head[v], c * r, 0);
    head[v] = to.size() - 1;

    return head[u];
  }

  bool findPath(int s, int t) {
    fill(d.begin(), d.end(), -1);
    queue<int> q;

    d[s] = 0;
    q.push(s);

    while (q.size()) {
      s = q.front();
      q.pop();

      for (int i = head[s]; i >= 0; i = nxt[i])
        if (d[to[i]] < 0 && capa[i] - f[i] >= lim)
          d[to[i]] = d[s] + 1, q.push(to[i]);
    }

    return d[t] >= 0;
  }

  int flowing(int s, int t, int flow) {
    if (s == t)
      return flow;

    for (int &i = use[s]; i >= 0; i = nxt[i])
      if (d[to[i]] == d[s] + 1 && capa[i] - f[i] >= lim) {
        int d = flowing(to[i], t, min(flow, capa[i] - f[i]));

        if (d > 0) {
          f[i] += d;
          f[i ^ 1] -= d;
          return d;
        }
      }

    return 0;
  }

  long long dinic(int s, int t) {
    long long maxflow = 0;
    int aug;

    for (lim = 1 << 30; lim > 0; lim >>= 1)
      while (findPath(s, t)) {
        copy(head.begin(), head.end(), use.begin());

        while ((aug = flowing(s, t, INT_MAX)) > 0)
          maxflow += aug;
      }

    return maxflow;
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  Dinic D{n};

  for (int i = 1, u, v, c; i <= m; i++)
    cin >> u >> v >> c, D.addEdge(u, v, c, 1);

  cout << D.dinic(1, n);

  return 0;
}