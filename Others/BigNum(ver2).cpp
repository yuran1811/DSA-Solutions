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

string Plus(string a, string b, string res = "")
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int id = 0, dept = 0;
	while (dept || id < max(sz(a), sz(b)))
	{
		int x = (id < sz(a)) ? a[id] - '0' : 0;
		int y = (id < sz(b)) ? b[id] - '0' : 0;
		int val = x + y + dept;
		dept = val / 10;
		res += char (val % 10 + '0'); id++;
	}
	reverse(res.begin(), res.end());
	return res;
}

string Minus(string a, string b, string res = "")
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int id = 0, dept = 0;
	while (dept || id < max(sz(a), sz(b)))
	{
		int x = (id < sz(a)) ? a[id] - '0' : 0;
		int y = (id < sz(b)) ? b[id] - '0' : 0;
		int val = x - y - dept;
		if (x < y + dept) val += 10, dept = 1; else dept = 0;
		res += char (val % 10 + '0'); id++;
	}
	while (res.back() == '0') res.pop_back();
	reverse(res.begin(), res.end());
	return res;
}
