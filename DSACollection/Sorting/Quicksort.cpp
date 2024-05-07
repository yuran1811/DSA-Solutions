#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int n, a[N];

void quickSort(int l, int r) {
  int i = l, j = r;
  int x = a[(l + r) / 2];

  while (i <= j) {
    while (a[i] < x) i++;
    while (a[j] > x) j--;
    if (i <= j) {
      swap(a[i], a[j]);
      i++;
      j--;
    }
  }

  if (l < j) quickSort(l, j);
  if (i < r) quickSort(i, r);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  quickSort(1, n);

  for (int i = 1; i <= n; i++) cout << a[i] << " ";

  return 0;
}