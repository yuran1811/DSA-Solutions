#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 5e4 + 50;
const int oo = 2e9 + 7;

vector<int> mx(N, 0), my(N, 0);
vector<int> a[N], d(N);

int matchedCount = 0;
int n, m, p;

bool findPath() {
  queue<int> q;

  for (int u = 1; u <= n; u++)
    if (mx[u])
      d[u] = oo;
    else
      d[u] = 0, q.push(u);

  while (q.size()) {
    int u = q.front();
    q.pop();

    for (int v : a[u])
      if (!my[v])
        return true;
      else if (d[my[v]] == oo)
        d[my[v]] = d[u] + 1, q.push(my[v]);
  }

  return false;
}

bool enlarge(int u) {
  if (d[u] == oo)
    return false;

  for (int v : a[u])
    if (!my[v] || (d[my[v]] == d[u] + 1 && enlarge(my[v])))
      return mx[u] = v, my[v] = u, true;

  return false;
}

void match() {
  while (findPath())
    for (int u = 1; u <= n; u++)
      if (!mx[u])
        matchedCount += enlarge(u);
}

int main() {
  cin >> n >> m >> p;
  for (int i = 1, u, v; i <= p; i++)
    cin >> u >> v, a[u].push_back(v);

  match();
  cout << matchedCount;

  return 0;
}