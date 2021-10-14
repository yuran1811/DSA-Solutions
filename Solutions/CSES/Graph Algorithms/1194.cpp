// https://cses.fi/problemset/task/1194
#include <bits/stdc++.h>
#define f first
#define s second
#define Yuran ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N=1e4, oo=1e9;
 
int n, m, a, b, u, v;
int dx[4]={0, 0, -1, 1}, dy[4]={-1, 1, 0, 0};
int MonsterCatchYou[N][N], EscFromMonsters[N][N];
 
char c[N][N];
string res="", dir="RLDU";
 
pair  <int, int> start, path, tmp;
queue <pair <int, int>> q, qM;
 
void init()
{
    Yuran cin >> n >> m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        cin >> c[i][j];
        if (c[i][j]=='A')
        {
            start={i, j};
            q.push(start);
        }
        EscFromMonsters[i][j]=oo;
        if (c[i][j]=='M')
        {
            qM.push({i, j});
            MonsterCatchYou[i][j]=0;
        }
        else MonsterCatchYou[i][j]=oo;
    }
    EscFromMonsters[start.f][start.s]=0;
}
 
bool kt(int x, int y)
{
    return (c[x][y]!='#' && x>0 && y>0 && x<=n && y<=m);
}
 
void Safe_Path()
{
    while (!q.empty())
    {
        a = q.front().f;
        b = q.front().s;
        q.pop();
        for (int i=0; i<=3; i++)
        {
            u = a + dx[i];
            v = b + dy[i];
            if (kt(u, v) && EscFromMonsters[u][v]==oo)
            {
                EscFromMonsters[u][v]=EscFromMonsters[a][b]+1;
                q.push({u, v});
            }
        }
    }
}
 
void Monster_Path()
{
    while (!qM.empty())
    {
        a = qM.front().f;
        b = qM.front().s;
        qM.pop();
        for (int i=0; i<=3; i++)
        {
            u = a + dx[i];
            v = b + dy[i];
            if (kt(u, v) && MonsterCatchYou[u][v]==oo)
            {
                MonsterCatchYou[u][v]=MonsterCatchYou[a][b]+1;
                qM.push({u, v});
            }
        }
    }
}
 
void trace(int x, int y)
{
    path={x, y};
    while (path!=start)
        for (int i=0; i<=3; i++)
        {
            tmp.f = path.f + dx[i];
            tmp.s = path.s + dy[i];
            if (kt(tmp.f, tmp.s) && EscFromMonsters[tmp.f][tmp.s] < EscFromMonsters[path.f][path.s])
                {
                    res+=dir[i]; path=tmp; break;
                }
        }
    reverse(res.begin(), res.end());
    cout << "YES\n" << res.size() << '\n' << res;
    exit(0);
}
 
int main()
{
    init(); Safe_Path(); Monster_Path();
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        if ((i==1 || j==1 || i==n || j==m) && EscFromMonsters[i][j]!=oo && (EscFromMonsters[i][j] < MonsterCatchYou[i][j]))
            trace(i, j);
    cout << "NO";
    return 0;
}
