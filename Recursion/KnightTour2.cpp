#include <iostream>

using namespace std;

const pair<int, int> dir[8] = {{2, 1},  {1, 2},  {-1, 2},  {1, -2},
                               {-2, 1}, {2, -1}, {-2, -1}, {-1, -2}};

int x, y, d, a[21][21];

bool checkInside(int x, int y, int d) {
  return x <= d && y <= d && x > 0 && y > 0;
}

void backtracking(int h, int c) {
  for (int i = 0; i < 8; i++) {
    int u = h + dir[i].first;
    int v = c + dir[i].second;

    if (a[u][v] == 0 && checkInside(u, v, d)) {
      a[u][v] = a[h][c] + 1;

      if (a[u][v] == d * d) {
        for (int k = 1; k <= d; k++, cout << '\n')
          for (int l = 1; l <= d; l++) cout << a[k][l] << "  ";
        exit(0);
      } else
        backtracking(u, v);

      a[u][v] = 0;
    }
  }
}

int main() {
  cin >> d >> x >> y;
  a[x][y] = 1;

  backtracking(x, y);

  return 0;
}