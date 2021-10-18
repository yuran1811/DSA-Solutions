// https://cses.fi/problemset/task/2079
#include <iostream>
#include <vector>
using namespace std;
 
const int N = 2e5 + 5;
 
vector <vector <int>> a;
int n, NumChild[N];
 
void DFS(int u, int p)
{
    NumChild[u] = 1;
    for (int v : a[u])
    {
        if (v == p) continue;
        DFS(v, u);
        NumChild[u] += NumChild[v];
    }
}
 
int Centroid(int u, int p, int cnt)
{
    for (int v : a[u])
    {
        if (v == p) continue;
        if (NumChild[v] * 2 > cnt)
            return Centroid(v, u, cnt);
    }
    return u;
}
 
int Find(int root)
{
    DFS(root, -1);
    int cnt = NumChild[root];
    return Centroid(root, -1, cnt);
}
 
void Load_Data()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    a.resize(n + 5, vector <int> ());
    for (int i = 1, u, v; i < n; i++)
        cin >> u >> v,
        a[u].push_back(v),
        a[v].push_back(u);
}
 
int Solve()
{
    Load_Data();
    cout << Find(1);
    return 0;
}
 
int main() {Solve();}
