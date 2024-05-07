#include <algorithm>
#include <string>

#define sz(x) (int)x.size()

using std::string;

string multiply(string a, int b) {
  string res = "";
  reverse(a.begin(), a.end());

  int debt = 0, i = 0;
  while (i < sz(a) || debt) {
    int x = (i < sz(a)) ? (a[i] - '0') : 0;
    int val = (x * b + debt) % 10;
    res += char(val + '0');
    debt = (debt + x * b) / 10;
    ++i;
  }

  reverse(res.begin(), res.end());

  return res;
}