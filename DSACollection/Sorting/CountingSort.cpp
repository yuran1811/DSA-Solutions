#include <iostream>
#include <vector>

using namespace std;

const int MAX_NUM = 1e6 + 7;

vector<int> countingSort(const vector<int> &a) {
  const int n = a.size();
  vector<int> b(n), d(MAX_NUM, 0);

  int maxNum = a[0];
  for (const int &_ : a) d[_]++, maxNum = max(maxNum, _);
  for (int i = 1; i <= maxNum; i++) d[i] += d[i - 1];
  
  for (int i = n - 1; i >= 0; i--) b[--d[a[i]]] = a[i];

  return b;
}

vector<int> radixSort(const vector<int> &a) {
  const int n = a.size();
  vector<int> b = a;

  int maxNum = a[0];
  for (const int &_ : a) maxNum = max(maxNum, _);

  for (int exp = 1; maxNum / exp > 0; exp *= 10) {
    vector<int> d(10, 0), c(n);

    for (const int &_ : b) d[_ / exp % 10]++;
    for (int i = 1; i <= 9; i++) d[i] += d[i - 1];

    for (int i = n - 1; i >= 0; i--) c[--d[b[i] / exp % 10]] = b[i];
    b = c;
  }

  return b;
}
