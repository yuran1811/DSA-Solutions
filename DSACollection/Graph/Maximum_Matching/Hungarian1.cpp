#include <bits/stdc++.h>

using namespace std;

const int N = 205, oo = 1e6 + 7;

int finish, res = 0, c[N][N];
int x[N], y[N], trace[N];
int mx[N], my[N];
int fx[N], fy[N];
int n, u, v, w;

int BFS(int s) {
  memset(trace, 0, sizeof trace);
  memset(x, 0, sizeof x);
  memset(y, 0, sizeof y);
  queue<int> q;
  q.push(s);

  while (q.size()) {
    int u = q.front();
    q.pop();
    x[u] = 1;

    for (int v = 1; v <= n; v++)
      if (!y[v] && c[u][v] == fx[u] + fy[v]) {
        y[v] = 1;
        trace[v] = u;

        if (!my[v]) return finish = v, true;

        q.push(my[v]);
      }
  }

  return false;
}

void Turn() {
  int delta = oo;
  for (int u = 1; u <= n; u++)
    if (x[u])
      for (int v = 1; v <= n; v++)
        if (!y[v]) delta = min(delta, c[u][v] - fx[u] - fy[v]);

  for (int i = 1; i <= n; i++) {
    if (x[i]) fx[i] += delta;
    if (y[i]) fy[i] -= delta;
  }
}

void Enlarge(int s) {
  int u, v = finish, t;
  while (!mx[s]) u = trace[v], t = mx[u], my[v] = u, mx[u] = v, v = t;
}

int main() {
  memset(c, oo, sizeof c);

  cin >> n;
  while (cin >> u >> v >> w) c[u][v] = min(c[u][v], w);

  for (int i = 1; i <= n; i++) {
    while (!BFS(i)) Turn();
    Enlarge(i);
  }

  for (int i = 1; i <= n; i++) res += fx[i] + fy[i];

  cout << res << '\n';
  for (int i = 1; i <= n; i++) cout << i << " " << mx[i] << '\n';

  return 0;
}