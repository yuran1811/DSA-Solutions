#include <iostream>
#include <vector>

using namespace std;

const int MAX_NUM = 1e6 + 7;

vector<int> countingSort(const vector<int> &a) {
  int n = a.size();
  vector<int> b(n), c(MAX_NUM, 0);

  for (const int &_ : a) c[_]++;

  for (int i = 1; i < MAX_NUM; i++) {
    c[i] += c[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    b[--c[a[i]]] = a[i];
  }

  return b;
}

vector<int> radixSort(const vector<int> &a) {
  vector<int> b = a;

  for (int exp = 1; MAX_NUM / exp > 0; exp *= 10) {
    vector<int> c(MAX_NUM, 0);

    for (const int &_ : b) c[_]++;

    for (int i = 1; i < MAX_NUM; i++) {
      c[i] += c[i - 1];
    }

    vector<int> d(b.size());

    for (int i = b.size() - 1; i >= 0; i--) {
      d[--c[b[i] / exp % 10]] = b[i];
    }

    b = d;
  }

  return b;
}