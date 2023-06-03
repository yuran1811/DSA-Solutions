#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 1e6 + 7;
const int oo = 1e9 + 7;

vector<int> a[N];
int d[N], used[N], matched[N];
int n, m, u, v, order;
bool vs[N];

bool findPath() {
  queue<int> q;

  for (int u = 1; u <= n; u++) {
    if (used[u] == order)
      d[u] = -1;
    else
      d[u] = 0, q.push(u);

    vs[u] = 0;
  }

  while (q.size()) {
    int u = q.front();
    q.pop();

    for (int v : a[u])
      if (!matched[v])
        return true;
      else if (d[matched[v]] < 0)
        d[matched[v]] = d[u] + 1, q.push(matched[v]);
  }

  return false;
}

bool enlarge(int u) {
  if (!m)
    return true;

  vs[u] = true;

  for (int v : a[u]) {
    int _u = matched[v];
    if (!matched[v] || (!vs[_u] && d[_u] == d[u] + 1 && enlarge(_u))) {
      if (!matched[v])
        m--;

      used[u] = order;
      matched[v] = u;

      return true;
    }
  }

  return false;
}

void match() {
  int job = m;

  while (m) {
    order++;

    while (findPath()) {
      for (int u = 1; u <= n; u++)
        if (used[u] != order)
          enlarge(u);

      if (!m)
        break;
    }
  }

  cout << order << '\n';
  for (int i = 1; i <= job; i++)
    cout << matched[i] << " ";
}

int main() {
  cin >> n >> m;
  while (cin >> u >> v)
    a[u].push_back(v);

  match();

  return 0;
}