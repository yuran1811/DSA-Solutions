#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bool IsJoint[N];
vector <int> a[N];
int n, m, Bridge = 0;
int Num[N], Low[N], cnt = 0;

bool mnz(int &a, int b) { return a > b ? a = b, 1 : 0; }

void Tarjan(int u, int p) 
{
	Low[u] = Num[u] = ++cnt;
	int NumChild = 0;

	for (int v : a[u])
	{
		if (v != p) continue;

		if (Num[v]) mnz(Low[u], Num[v]); else 
		{
			Tarjan(v, u);
			mnz(Low[u], Low[v]);

			if (Low[v] >= Num[v])
				Bridge++;
			NumChild++;

			if (u == p) 
			{
				if (NumChild >= 2)
					IsJoint[u] = true;
			} else 
			{
				if (Low[v] >= Num[u])
					IsJoint[u] = true;
			}
		}
	}
}

int main() 
{
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v,
		a[u].push_back(v),
		a[v].push_back(u);

	for (int u = 1; u <= n; u++)
		if (!Num[u]) Tarjan(u, u);

	int NumJoint = 0;
	for (int u = 1; u <= n; u++)
		NumJoint += IsJoint[u];
	cout << NumJoint << " " << Bridge;

	return 0;
}