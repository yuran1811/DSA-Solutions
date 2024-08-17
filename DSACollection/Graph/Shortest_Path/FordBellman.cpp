#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
  int u, v, w;
};

const int INF = 1e9 + 7;

int n, m;

void fordBellman(int s, int t, vector<Edge> &edges) {
  vector<int> dist(n, INF);
  dist[s] = 0;

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      int u = edges[j].u;
      int v = edges[j].v;
      int w = edges[j].w;

      if (dist[u] != INF && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
      }
    }
  }

  if (dist[t] == INF) {
    cout << "No path from " << s << " to " << t << endl;
  } else {
    cout << "Shortest path from " << s << " to " << t << " is " << dist[t]
         << endl;
  }
}
