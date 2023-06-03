#include <array>
#include <iostream>

using namespace std;

typedef unsigned long long ll;
typedef array<ll, 4> Int128;

const ll BASE = 1e9; // 1LL << 32;

int n;

Int128 Plus(Int128 a, Int128 b) {
  Int128 c = {0};
  int dept = 0;
  ll t = 0;

  for (int i = 0; i < 4; i++) {
    t = a[i] + b[i] + dept;
    dept = t / BASE;
    c[i] = t % BASE;
  }

  return c;
}

Int128 Minus(Int128 a, Int128 b) {
  Int128 c = {0};
  int dept = 0;

  for (int i = 0; i < 4; i++)
    if (a[i] < b[i] + dept)
      c[i] = BASE + a[i] - b[i] - dept, dept = 1;
    else
      c[i] = a[i] - b[i] - dept, dept = 0;

  return c;
}

Int128 Multi(Int128 a, Int128 b) {
  Int128 c = {0};
  ll d[4] = {0};

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      d[i + j] += 1LL * a[i] * b[j];

  for (int i = 0; i < 3; i++)
    c[i] = d[i] % BASE, d[i + 1] += d[i] / BASE;

  return c;
}

ll Modulo(Int128 a, ll MOD) {
  ll t = 0;

  for (int i = 3; i >= 0; i--)
    t = (t * BASE + a[i]) % MOD;

  return t;
}

Int128 Convert(ll x) {
  Int128 val = {0};
  val[0] = x % BASE;
  val[1] = x / BASE;

  return val;
}

void Print(Int128 a, bool SIGN = 1) {
  cout << (SIGN ? "" : "-");

  bool c = 0;
  for (int i = 3; i >= 0; i--) {
    c |= a[i] > 0;
    if (c)
      cout << a[i];
  }

  cout << '\n';
}

void loadData() {
  ll a, b, MOD;
  cin >> a >> b >> MOD;

  Int128 x, y;
  x = Convert(a);
  y = Convert(b);

  Print(Plus(x, y));
  Print(Minus(x, y));
  Print(Multi(x, y));

  cout << Modulo(x, MOD) << '\n';
  cout << Modulo(y, MOD) << '\n';
}

int Solve() {
  loadData();
  return 0;
}

int main() { Solve(); }