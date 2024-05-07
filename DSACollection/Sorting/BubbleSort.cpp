#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int n, a[N];

void bubbleSort() {
  bool isSwap;

  for (int i = 1; i < n; i++) {
    isSwap = 0;

    for (int j = 1; j <= n - i; j++)
      if (a[j] > a[j + 1]) swap(a[j], a[j + 1]), isSwap = 1;

    if (!isSwap) break;
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  bubbleSort();

  for (int i = 1; i <= n; i++) cout << a[i] << " ";

  return 0;
}