#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::max;
using std::string;
using std::vector;

const int N = 3e3 + 3;

int n, m, cnt = 1, f[N][N];

vector<string> ans;
string s, t, res;

int main() {
  cin >> s >> t;
  n = s.size();
  m = t.size();
  s = "#" + s;
  t = "#" + t;

  for (int i = 1; i <= n; i++) f[i][0] = 0;
  for (int i = 1; i <= m; i++) f[0][i] = 0;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i] == t[j])
        f[i][j] = f[i - 1][j - 1] + 1;
      else
        f[i][j] = max(f[i - 1][j], f[i][j - 1]);

  while (f[n][m] > 0) {
    while (f[n][m] == f[n - 1][m]) n--;
    while (f[n][m] == f[n][m - 1]) m--;
    res += s[n];
    n--;
    m--;
  }

  for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
  return 0;
}