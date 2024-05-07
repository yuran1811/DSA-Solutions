#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int n, c, b;
int a[21][21];
int row[101], secCheck[101], priCheck[101];

void solve(int i) {
  for (int j = 1; j <= 8; j++)
    if (!a[j][i] && !row[j] && !secCheck[i - j + 8] && !priCheck[i + j]) {
      a[j][i] = row[j] = secCheck[i - j + 8] = priCheck[i + j] = 1;

      if (i >= 8) {
        if (a[c][b] == 1) {
          for (int l = 1; l <= 8; l++, cout << endl)
            for (int k = 1; k <= 8; k++) cout << (a[l][k] == 1 ? "w" : ".");

          exit(0);
        }
      } else
        solve(i + 1);

      a[j][i] = row[j] = secCheck[i - j + 8] = priCheck[i + j] = 0;
    }
}

int main() {
  cin >> c >> b;

  solve(1);

  return 0;
}