#include <cstring>
#include <iostream>
#include <vector>

#define fi first
#define se second

using namespace std;

const int N = 1e5 + 5;
const int oo = 1e9 + 7;

bool isVisited[N];

int n, m, s, t;
int trace[N], d[N];
int pos[N], heap[N], top;

vector<pair<int, int>> a[N];

void loadGraph() {
  cin >> n >> m >> s >> t;
  for (int i = 1, u, v, w; i <= m; i++)
    cin >> u >> v >> w, a[u].push_back({v, w}), a[v].push_back({u, w});
}

void Reset(int s) {
  memset(pos, 0, sizeof pos);
  memset(isVisited, 0, sizeof isVisited);
  for (int i = 1; i <= n; i++) d[i] = oo;
  d[s] = top = 0;
}

namespace Heap {
void update(int index) {
  int c = pos[index];
  if (!c) top++, c = top;
  int parent = c / 2;

  while (parent > 0 && d[heap[parent]] > d[index]) {
    heap[c] = heap[parent];
    pos[heap[c]] = c;
    c = parent;
    parent = c / 2;
  }

  heap[c] = index;
  pos[index] = c;
}

int pop() {
  int rt, v, c;
  int val = heap[1];
  v = heap[top];
  top--;
  rt = 1;

  while (rt * 2 <= top) {
    c = rt * 2;
    if (d[heap[c]] >= d[v]) break;
    heap[rt] = heap[c];
    pos[heap[rt]] = rt;
    rt = c;
  }

  heap[rt] = v;
  pos[v] = rt;
  return val;
}
}  // namespace Heap

void Dijkstra(int s) {
  Heap::update(1);

  do {
    int u = Heap::pop();
    if (u == t) break;

    isVisited[u] = false;

    for (auto x : a[u])
      if (d[x.fi] > d[u] + x.se) {
        d[x.fi] = d[u] + x.se;
        trace[x.fi] = u;
        Heap::update(x.fi);
      }
  } while (top);

  if (d[t] == oo) return void(cout << -1);

  cout << d[t] << '\n';

  vector<int> st;
  while (t != s) st.push_back(t), t = trace[t];
  st.push_back(s);

  while (st.size()) cout << st.back() << " ", st.pop_back();
}

int main() {
  loadGraph();
  Reset(s);
  Dijkstra(s);
  return 0;
}