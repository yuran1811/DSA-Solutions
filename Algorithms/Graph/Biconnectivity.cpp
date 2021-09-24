#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 50;

vector <int> a[N], s;

int Low[N], Num[N], cnt = 0, res = 1;
int NumCpn = 0, lastvs[N];
int n, m;

bool mnz(int &a, int b) {return a > b ? a = b, 1 : 0;}
bool mxm(int &a, int b) {return a < b ? a = b, 1 : 0;}

void BICONNECTIVITY(int u)
{
    Low[u] = Num[u] = ++cnt;
    for (int v : a[u])
        if (Num[v]) mnz(Low[u], Num[v]); else
        {
            s.push_back(u);
            BICONNECTIVITY(v);
            mnz(Low[v], Low[u]);
            
            if (Low[v] >= Num[u])
            {
                int tmp = 0;
                NumCpn++;
                do 
                {
                    v = s.back();
                    tmp += mxm(lastvs[v], NumCpn);
                    s.pop_back();
                } while (u != v);
                mxm(res, tmp);
            }
        }
    s.push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++)
        cin >> u >> v,
        a[u].push_back(v),
        a[v].push_back(u);

    for (int u = 1; u <= n; u++)
        if (!Num[u]) BICONNECTIVITY(u);
    cout << res;
    return 0;
}
