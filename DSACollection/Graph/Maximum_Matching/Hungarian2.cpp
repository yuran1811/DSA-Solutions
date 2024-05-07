#include <bits/stdc++.h>

using namespace std;

const int N = 205, oo = 1e6 + 7;

int d[N], fx[N], fy[N], my[N], mx[N];
int n, c[N][N], trace[N], aug[N];
queue<int> q;

void Init() {
  memset(c, oo, sizeof c);

  cin >> n;

  int u, v, w;
  while (cin >> u >> v >> w) c[u][v] = min(c[u][v], w);
}

int GetC(int u, int v) { return c[u][v] - fx[u] - fy[v]; }

void BFS(int u) {
  q = queue<int>();
  q.push(u);

  for (int i = 1; i <= n; i++) trace[i] = 0, d[i] = GetC(u, i), aug[i] = u;
}

int FIND_AUGMENTING_PATH() {
  while (q.size()) {
    int u = q.front();
    q.pop();

    for (int v = 1; v <= n; v++)
      if (!trace[v]) {
        int w = GetC(u, v);

        if (!w) {
          trace[v] = u;
          if (my[v] == 0) return v;
          q.push(my[v]);
        }

        if (d[v] > w) d[v] = w, aug[v] = u;
      }
  }

  return 0;
}

void UPDATE(int &finish, int u) {
  int delta = oo;

  for (int i = 1; i <= n; i++)
    if (!trace[i]) delta = min(delta, d[i]);

  fx[u] += delta;

  for (int i = 1; i <= n; i++) {
    if (trace[i])
      fx[my[i]] += delta, fy[i] -= delta;
    else {
      d[i] -= delta;
      if (!d[i]) {
        trace[i] = aug[i];

        if (!my[i])
          finish = i;
        else
          q.push(my[i]);
      }
    }
  }
}

void Enlarge(int finish) {
  for (int y = finish, next, x; y; y = next)
    x = trace[y], next = mx[x], mx[x] = y, my[y] = x;
}

void Matching() {
  for (int i = 1; i <= n; i++) {
    BFS(i);
    int finish = 0;

    do {
      finish = FIND_AUGMENTING_PATH();
      if (!finish) UPDATE(finish, i);
    } while (!finish);

    Enlarge(finish);
  }

  int res = 0;
  for (int i = 1; i <= n; i++)
    if (mx[i]) res += c[i][mx[i]];

  cout << res << '\n';
  for (int i = 1; i <= n; i++) cout << i << " " << mx[i] << '\n';
}

int main() {
  Init();
  Matching();

  return 0;
}