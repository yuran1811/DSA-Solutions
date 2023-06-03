#include <iostream>
#include <queue>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll oo = 1e17 + 5;
const int N = 1e4 + 5;

vector<pii> a[N];
int n, m;

template <typename T> bool mnz(T &a, T b) { return a > b ? a = b, 1 : 0; }

void Dijkstra(int s, int t) {
  vector<ll> d(n + 5, oo);
  priority_queue<pii> q;

  d[s] = 0;
  q.push({0, s});

  while (q.size()) {
    int u = q.top().se;
    ll du = -q.top().fi;
    q.pop();

    if (d[u] != du)
      continue;

    if (u == t)
      break;

    for (pii x : a[u])
      if (mnz(d[x.fi], d[u] + x.se))
        q.push({-d[x.fi], x.fi});
  }

  cout << (d[t] < oo ? d[t] : -1);
}

int main() {
  cin >> n >> m;
  for (int i = 1, u, v, w; i <= m; i++)
    cin >> u >> v >> w, a[u].push_back({v, w}), a[v].push_back({u, w});

  Dijkstra(1, n);
  return 0;
}
