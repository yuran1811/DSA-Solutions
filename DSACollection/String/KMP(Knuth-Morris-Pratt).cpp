#include <iostream>
#include <vector>

using namespace std;

vector<int> KMP;
string s, t;

void Build_KMP(const string &s) {
  for (int i = 1, k; i < int(s.size()); i++) {
    k = KMP[i - 1];
    while (k && s[i] != s[k]) k = KMP[k - 1];
    if (s[i] == s[k]) k++;
    KMP[i] = k;
  }
}

void Count_Appear_Times_Of_Each_Prefix(const string &s) {
  vector<int> f(s.size() + 1);
  KMP.resize(s.size());

  Build_KMP(s);

  for (int i : KMP) f[i]++;

  for (int i = s.size() - 1; i; i--) f[KMP[i - 1]] += f[i];

  for (int i = 1; i <= int(s.size()); i++) cout << ++f[i] << " ";
}

void Find(const string &s, const string &t) {
  int n = s.size(), m = t.size();

  KMP.resize(n);
  Build_KMP(t);

  int k = 0;
  for (int i = 0; i < n; i++) {
    while (k && s[i] != t[k]) k = KMP[k - 1];
    if (s[i] == t[k]) k++;
    if (k == m) cout << i - k + 2 << " ", k = KMP[k - 1];
  }
}

void Load_Data() { cin >> s >> t; }

int main() {
  Load_Data();
  Find(s, t);

  return 0;
}