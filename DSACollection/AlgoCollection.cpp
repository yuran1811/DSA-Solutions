#include <bits/stdc++.h>

#define sz(s) (int(s.size()))

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
const int P = 1e7 + 5;
const int oo = 1e9 + 7;

int n, m, ans, a[N];
char s[N];

struct Trie {
  struct Node {
    Node *child[26];
    int cnt;

    Node() {
      for (int i = 0; i < 26; i++) child[i] = NULL;
      cnt = 0;
    }
  };

  Node *root = new Node();

  void add(const string &s) {
    Node *p = root;

    for (char c : s) {
      int pos = c - 'a';
      if (p->child[pos] == NULL) p->child[pos] = new Node();
      p = p->child[pos];
    }

    ++p->cnt;
  }

  bool find(const string &t, string &x) {
    Node *p = root;

    for (char c : t) {
      int pos = c - 'a';
      x += c;

      if (p->child[pos] == NULL) return false;

      p = p->child[pos];
    }

    return p->cnt > 0;
  }
};

class TrieClass {
 public:
  struct TrieNode {
    int a[26], val;

    TrieNode() {
      for (int i = 0; i < 26; i++) a[i] = 0;
      val = 0;
    }

    int &operator[](int i) { return a[i]; }
  };

  vector<TrieNode> a;

  TrieClass() { clear(); }

  int &operator[](char *s) {
    int pos = 0, c;

    for (int i = 0; c = s[i]; i++) {
      if (!a[pos][c - 'a']) {
        a.push_back(TrieNode());
        a[pos][c - 'a'] = a.size() - 1;
      }

      pos = a[pos][c - 'a'];
    }
    return a[pos].val;
  }

  void clear() {
    a.clear();
    a.push_back(TrieNode());
  }

  void dfs(int u, int cnt) {
    if (a[u].val == 1) ans = max(ans, ++cnt);

    for (int i = 0; i < 26; i++)
      if (a[u][i]) dfs(a[u][i], cnt);
  }

  int find() {
    ans = 0;
    dfs(0, 0);
    return ans;
  }
};

struct SegmentTree {
  int t[4 * N];

  void build(int l, int r, int i) {
    if (l == r) return (void)(t[i] = a[l]);

    int m = (l + r) >> 1;
    build(l, m, i << 1);
    build(m + 1, r, i << 1 | 1);

    t[i] = min(t[i << 1], t[i << 1 | 1]);
  }

  void update(int l, int r, int i, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) return (void)(t[i] = val);

    int m = (l + r) >> 1;
    update(l, m, i << 1, pos, val);
    update(m + 1, r, i << 1 | 1, pos, val);

    t[i] = min(t[i << 1], t[i << 1 | 1]);
  }

  int get(int l, int r, int i, int u, int v) {
    if (r < u || v < l) return oo;
    if (u <= l && r <= v) return t[i];

    int m = (l + r) >> 1;
    return min(get(l, m, i << 1, u, v), get(m + 1, r, i << 1 | 1, u, v));
  }
};

struct SegmentTreeLazy {
  struct Node {
    ll val, lz;
  };

  vector<Node> t;

  SegmentTreeLazy() {}
  SegmentTreeLazy(int n) { init(n); }

  void init(int n) { t.resize(4 * n + 5); }

  void build(int l = 1, int r = n, int i = 1) {
    if (l == r) return void(t[i].val = a[l]);

    int m = (l + r) >> 1;
    build(l, m, i << 1);
    build(m + 1, r, i << 1 | 1);

    t[i].val = t[i << 1].val + t[i << 1 | 1].val;
  }

  void update(int l, int r, int i, int u, int v, int val) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
      t[i].val += (r - l + 1) * val;
      t[i].lz += val;
      return;
    }

    int m = (l + r) >> 1;
    update(l, m, i << 1, u, v, val);
    update(m + 1, r, i << 1 | 1, u, v, val);

    t[i].val = t[i << 1].val + t[i << 1 | 1].val + t[i].lz * (r - l + 1);
  }

  ll get(int l, int r, int i, int u, int v) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return t[i].val;

    int m = (l + r) >> 1;
    return get(l, m, i << 1, u, v) + get(m + 1, r, i << 1 | 1, u, v) +
           t[i].lz * (min(r, v) - max(l, u) + 1);
  }
};

struct DSU {
  vector<int> f;
  int n;

  DSU() {}
  DSU(int n) : n(n) { init(n); }

  void init(int n) { f.resize(n + 5, -1); }
  int root(int u) { return f[u] < 0 ? u : f[u] = root(f[u]); }
  bool merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return 0;
    if (f[u] > f[v]) swap(u, v);
    return f[u] += f[v], f[v] = u, 1;
  }
};

struct MaxHeap {
  // MinHeap : change the sign where "***"

  int heap[N], top = 0;

  void up(int x) {
    int p = x / 2;
    if (x == 1 || heap[p] >= heap[x]) return;  // ***
    swap(heap[p], heap[x]);
    up(p);
  }

  void down(int x) {
    int c = x * 2;
    if (c > top) return;
    if (c < top && heap[c] < heap[c + 1]) c++;  // ***
    if (heap[c] > heap[x]) {                    // ***
      swap(heap[x], heap[c]);
      down(c);
    }
  }

  void pop() {
    heap[1] = heap[top--];
    down(1);
  }

  void push(int x) {
    heap[++top] = x;
    up(top);
  }
};

#define E (int)1e9 +
const long long BASE = 311, K = 3;
const long long MOD[] = {E 1927, E 1957, E 1969};
// 1927 : năm sáng tác Đường Kách Mệnh
// 1957 : Hội Nhà văn Việt Nam ra đời
// 1969 : năm sáng tác bài thơ tiểu đội xe không kính

ll Pow[N][K];

void buildPow(int n) {
  for (int nmod = 0; nmod < K; nmod++) {
    Pow[0][nmod] = 1;
    for (int i = 1; i <= n; i++)
      Pow[i][nmod] = Pow[i - 1][nmod] * BASE % MOD[nmod];
  }
}

struct Hashing {
  vector<ll> val;

  Hashing() { val.assign(K, 0); }
  Hashing(char x) {
    for (int i = 0; i < K; i++) val[i] = x;
  }

  Hashing operator+(const Hashing &x) const {
    Hashing res;

    for (int nmod = 0; nmod < K; nmod++) {
      res.val[nmod] = val[nmod] + x.val[nmod];
      if (res.val[nmod] >= MOD[nmod]) res.val[nmod] -= MOD[nmod];
    }

    return res;
  }

  Hashing operator-(const Hashing &x) const {
    Hashing res;

    for (int nmod = 0; nmod < K; nmod++) {
      res.val[nmod] = val[nmod] - x.val[nmod];
      if (res.val[nmod] < 0) res.val[nmod] += MOD[nmod];
    }

    return res;
  }

  Hashing operator*(int k) const {
    Hashing res;
    for (int nmod = 0; nmod < K; nmod++)
      res.val[nmod] = val[nmod] * Pow[k][nmod] % MOD[nmod];
    return res;
  }

  bool operator<(const Hashing &x) const {
    for (int nmod = 0; nmod < K; nmod++)
      if (val[nmod] != x.val[nmod]) return val[nmod] < x.val[nmod];
    return false;
  }

  bool operator==(const Hashing &x) const {
    for (int nmod = 0; nmod < K; nmod++)
      if (val[nmod] != x.val[nmod]) return false;
    return true;
  }
};

struct StringHashing {
  vector<Hashing> h;
  string s;
  int n;

  void build(string x) {
    n = x.size();
    s = " " + x;
    h.resize(n + 1);

    for (int i = 1; i <= n; i++) h[i] = h[i - 1] + Hashing(s[i]) * i;
  }

  Hashing get(int i, int j) { return (h[j] - h[i - 1]) * (n - j); }
};

struct Matrix {
  int size;
  vector<vector<int>> v;

  Matrix() {}
  Matrix(int size) : size(size) { v.assign(size, vector<int>(size, 0)); }

  friend Matrix operator*(const Matrix &a, const Matrix &b) {
    const int sz = a.size;

    Matrix c(sz);

    for (int i = 0; i <= sz; i++)
      for (int j = 0; j <= sz; j++)
        for (int p = 0; p <= sz; p++)
          c.v[i][j] = (c.v[i][j] + a.v[i][p] * b.v[p][j] % MOD[0]) % MOD[0];

    return c;
  }

  friend Matrix operator^(const Matrix &a, const int &k) {
    if (k == 1) return a;

    Matrix t = a ^ (k >> 1);
    t = t * t;
    return k & 1 ? t * a : t;
  }
};

struct FenwickTreeMin {
  const int INF = 1e9 + 7;

  int n;
  vector<int> f;

  FenwickTreeMin(int n) : n(n) { f.assign(n, INF); }

  FenwickTreeMin(const vector<int> &a) : FenwickTreeMin(a.size()) {
    for (int i = 0; i < n; i++) update(i, a[i]);
  }

  int get(int r) {
    int _ = INF;
    for (; r >= 0; r = (r & (r + 1)) - 1) _ = min(_, f[r]);
    return _;
  }

  void update(int idx, int val) {
    for (; idx < n; idx = idx | (idx + 1)) f[idx] = min(f[idx], val);
  }
};
