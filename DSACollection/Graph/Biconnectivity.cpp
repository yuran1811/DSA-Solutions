#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

const int N = 3e4 + 50;

vector<int> a[N], s;

int Low[N], Num[N], cnt = 0, res = 1;
int NumCpn = 0, lastvs[N];
int n, m;

template <typename T>
bool mnz(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
bool mxm(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}

void dfs(int u) {
  Low[u] = Num[u] = ++cnt;

  for (int v : a[u])
    if (Num[v])
      mnz(Low[u], Num[v]);
    else {
      s.push_back(u);

      dfs(v);
      mnz(Low[v], Low[u]);

      if (Low[v] >= Num[u]) {
        int tmp = 0;
        NumCpn++;
        do {
          v = s.back();
          tmp += mxm(lastvs[v], NumCpn);
          s.pop_back();
        } while (u != v);
        mxm(res, tmp);
      }
    }

  s.push_back(u);
}

int main() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++)
    cin >> u >> v, a[u].push_back(v), a[v].push_back(u);

  for (int u = 1; u <= n; u++)
    if (!Num[u]) dfs(u);
  cout << res;

  return 0;
}