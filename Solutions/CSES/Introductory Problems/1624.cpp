// https://cses.fi/problemset/task/1624
#include <bits/stdc++.h>
using namespace std;
 
bool ld[15], rd[15], row[7];
char a[8][8];
int c = 0;
 
void btr(int j)
{
	if (j == 8) return (void) (c++);
	for (int i = 0; i < 8; i++)
		if (a[i][j] == '.' && !ld[i - j + 7] && !rd[i + j] && !row[i])
		{
			ld[i - j + 7] = rd[i + j] = row[i] = 1;
			btr(j + 1);
			ld[i - j + 7] = rd[i + j] = row[i] = 0;
		}
}
 
int main()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> a[i][j];
	btr(0);
	cout << c;
	return 0;
}
