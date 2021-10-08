string Multi(string a, int b)
{
	string res = "";
	reverse(a.begin(), a.end());
 
	int dept = 0, i = 0;
	while (i < sz(a) || dept)
	{
		int x = (i < sz(a)) ? (a[i] - '0') : 0;
		int val = (x * b + dept) % 10;
		res += char (val + '0');
		dept = (dept + x * b) / 10;
		++i;
	}
	reverse(res.begin(), res.end());
	return res;
}
