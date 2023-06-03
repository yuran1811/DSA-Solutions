#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 5;
const int oo = 1e9 + 7;

vector<int> Node[N], a[N], s;
int Num[N], Low[N], cnt = 0;
int n, m, numCpn;

template <typename T> bool mnz(T &a, T b) { return a > b ? a = b, 1 : 0; }

void Tarjan(int u) {
  Num[u] = Low[u] = ++cnt;
  s.push_back(u);

  for (int v : a[u])
    if (!Num[v]) {
      Tarjan(v);
      mnz(Low[u], Low[v]);
    } else
      mnz(Low[u], Num[v]);

  if (Low[u] == Num[u]) {
    numCpn++;
    int v;

    do {
      v = s.back();
      s.pop_back();
      Node[numCpn].push_back(v);
      Num[v] = Low[v] = oo;
    } while (v != u);

    sort(Node[numCpn].begin(), Node[numCpn].end());
  }
}

void loadData() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++)
    cin >> u >> v, a[u].push_back(v);

  for (int u = 1; u <= n; u++)
    if (!Num[u])
      Tarjan(u);
}

int main() {
  loadData();

  cout << numCpn << '\n';
  for (int i = 1; i <= numCpn; i++, cout << '\n')
    for (int v : Node[i])
      cout << v << " ";

  return 0;
}