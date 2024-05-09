#include <iostream>

using namespace std;

const int N = 10;

int a[N][N];

void prt() {
  for (int i = 0; i < 9; i++, cout << '\n')
    for (int j = 0; j < 9; j++) cout << a[i][j] << " ";
}

bool check(int x, int y, int val) {
  for (int i = 0; i < 9; i++)
    if (a[x][i] == val || a[i][y] == val) return false;

  for (int i = x / 3 * 3; i <= x / 3 * 3 + 2; i++)
    for (int j = y / 3 * 3; j <= y / 3 * 3 + 2; j++)
      if (a[i][j] == val) return false;

  return true;
}

void solveSudoku(int x, int y) {
  if (y == 9) {
    if (x == 8)
      prt(), exit(0);
    else
      solveSudoku(x + 1, 0);

    return;
  }

  if (!a[x][y]) {
    for (int val = 1; val <= 9; val++)
      if (check(x, y, val)) {
        a[x][y] = val;

        solveSudoku(x, y + 1);

        a[x][y] = 0;
      }

    return;
  }

  solveSudoku(x, y + 1);
}

int main() {
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++) cin >> a[i][j];

  solveSudoku(0, 0);

  return cout << -1, 0;
}