#include <algorithm>
#include <iostream>
#include <string>

#define sz(x) (int)x.size()

using std::max;
using std::string;

string Multi(string a, int b) {
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

string Plus(string a, string b, string res = "") {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int id = 0, debt = 0;

  while (debt || id < max(sz(a), sz(b))) {
    int x = (id < sz(a)) ? a[id] - '0' : 0;
    int y = (id < sz(b)) ? b[id] - '0' : 0;
    int val = x + y + debt;
    debt = val / 10;
    res += char(val % 10 + '0');
    id++;
  }

  reverse(res.begin(), res.end());

  return res;
}

string Minus(string a, string b, string res = "") {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  int id = 0, debt = 0;

  while (debt || id < max(sz(a), sz(b))) {
    int x = (id < sz(a)) ? a[id] - '0' : 0;
    int y = (id < sz(b)) ? b[id] - '0' : 0;
    int val = x - y - debt;
    if (x < y + debt)
      val += 10, debt = 1;
    else
      debt = 0;
    res += char(val % 10 + '0');
    id++;
  }

  while (res.back() == '0') res.pop_back();

  reverse(res.begin(), res.end());

  return res;
}