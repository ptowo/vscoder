// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, l, r) for(int i = (l); i <= r; ++i)
#define REP(i, l, r) for(int i = (l); i <  r; ++i)
#define DFR(i, l, r) for(int i = (l); i >= r; --i)
#define DRP(i, l, r) for(int i = (l); i >  r; --i)
#define FORV(i, ver) for(int i = 0; i < ver.size(); i++)
#define FORP(i, ver) for(auto i : ver)
template<class T>T wmin(const T &a, const T &b) {return a < b ? a : b;}
template<class T>T wmax(const T &a, const T &b) {return a > b ? a : b;}
template<class T>bool chkmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
template<class T>bool chkmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 205;
int n, mp[N], tot, tot2, vip[N];
string a[N], b[N], c[N], d[N];
map <string,int> vis, vib;
signed main () {
  n = read();
  FOR (i, 1, n) 
    cin >> a[i], vis[ a[i] ]++;
  FOR (i, 1, n) 
    cin >> b[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  FOR (i, 1, n) {
    if (vis[ b[i] ]) {
      vis[ b[i] ]--;
      mp[i] = 1;
      vib[ b[i] ]++;
      continue;
    }
    c[++tot] = b[i];
  }
  FOR (i, 1, n) {
    if (vib[ a[i] ]) {
      vib[ a[i] ]--;
      continue;
    }
    d[++tot2] = a[i];
  }
  sort(c + 1, c + tot + 1);
  sort(d + 1, d + tot2 + 1);
  int ans = 0;
  FOR (i, 1, tot) {
    int now = n, pos = 0;
    FOR (j, 1, tot2) {
      if (vip[j]) continue;
      if (d[j].size() != c[i].size()) break;
      int cnt = 0;
      REP (k, 0, d[j].size()) 
        if (d[j][k] != c[i][k]) cnt++;
      if (cnt < now) { now = cnt; pos = j;}
    }
    ans += now;
    vip[pos] = 1;
  }
  cout << ans << "\n";
  return 0;
}
/*
首先排序，然后排序之后
dp_{ij} = 
*/