#include <vector>

using std::vector;

struct BIT {
  vector<int> v1, v2;
  int n;

  BIT() {}
  BIT(int n) : n(n) {
    v1.resize(n + 5, 0);
    v2.resize(n + 5, 0);
  }

  void pointUpdate(vector<int> &bit, int i, const int &val) {
    for (; i <= n; i += -i & i) bit[i] += val;
  }

  void rangeUpdate(int l, int r, const int &val) {
    pointUpdate(v1, l, val);
    pointUpdate(v1, r + 1, -val);
    pointUpdate(v2, l, val * (l - 1));
    pointUpdate(v2, r + 1, -val * r);
  }

  int pointGet(vector<int> &bit, int i, int sum = 0) {
    for (; i > 0; i -= -i & i) sum += bit[i];
    return sum;
  }

  int rangeGet(int l, int r) {
    int rightSum = pointGet(v1, r) * r - pointGet(v2, r);
    int leftSum = pointGet(v1, l - 1) * (l - 1) - pointGet(v2, l - 1);
    return rightSum - leftSum;
  }
};