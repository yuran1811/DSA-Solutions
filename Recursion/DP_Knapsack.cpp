#include <iostream>

using std::cin;
using std::cout;

const int N = 1e4;

int n, m;
int f[N][N];
int w[N], v[N];

template <typename T>
int mxm(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= m; j++) {
      f[i][j] = f[i - 1][j];
      if (j >= w[i]) mxm(f[i][j], f[i - 1][j - w[i]] + v[i]);
    }

  cout << f[n][m] << '\n';
  while (n) {
    if (f[n][m] != f[n - 1][m]) cout << n << " ", m -= w[n];
    n--;
  }

  return 0;
}