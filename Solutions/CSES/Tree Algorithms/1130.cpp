// https://cses.fi/problemset/task/1130
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 5;

vector<int> a[N];
vector<bool> isVisited;
int n, res = 0;

void DFS(int u, int p) {
  for (int v : a[u])
    if (v != p) {
      DFS(v, u);
      if (!isVisited[u] && !isVisited[v])
        res++, isVisited[u] = isVisited[v] = 1;
    }
}

void loadData() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  isVisited.assign(n + 1, 0);
  for (int i = 2, u, v; i <= n; i++)
    cin >> u >> v, a[u].push_back(v), a[v].push_back(u);
}

int main() {
  loadData();
  DFS(1, -1);
  cout << res;
  return 0;
}
