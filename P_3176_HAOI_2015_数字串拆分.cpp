// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, l, r) for(int i = (l); i <= r; ++i)
#define REP(i, l, r) for(int i = (l); i <  r; ++i)
#define DFR(i, l, r) for(int i = (l); i >= r; --i)
#define DRP(i, l, r) for(int i = (l); i >  r; --i)
#define FORV(i, ver) for(int i = 0; i < ver.size(); i++)
#define FORP(i, ver) for(auto i : ver)
template<class T>T min(const T &a, const T &b) {return a < b ? a : b;}
template<class T>T max(const T &a, const T &b) {return a > b ? a : b;}
template<class T>bool chkmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
template<class T>bool chkmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 2e4, M = 30, mod = 998244353;
int s, n, m, a[N];
char ch[N];
struct node {
  int a[5][5];
  void clear() {
    memset(a, 0, sizeof(a));
    REP (i, 1, m) a[i][i] = 1;
  }
  void clear2() {
    memset(a, 0, sizeof(a));
  }
  node operator *  (const node &b) {
    node res;  res.clear2();
    REP (i, 0, m) 
      REP (k, 0, m)
        REP (j, 0, m) 
          res.a[i][j] += a[i][k] * b.a[k][j] % mod, res.a[i][j] %= mod;    
    return res;
  }
  node operator + (const node &b) {
    node res; res.clear2();
    REP (i, 0, m)
        REP (j, 0, m)
          res.a[i][j] += a[i][j] + b.a[i][j], res.a[i][j] %= mod;
    return res;
  }
}w, f[11][N], g[N], I;
node ksm(node ap,int k) {
  node ans;  ans = I;
  while (k) {
    if (k & 1) ans = ans * ap;
    k >>= 1; ap = ap * ap;
  }
  return ans;
}
signed main () {
  scanf("%s", ch + 1);
  m = read();
  n = strlen(ch + 1);
  FOR (i, 1, n) a[i] = ch[i] - '1' + 1;
  REP (i, 0, m) {
    if ( I.a[i][i] = 1, f[1][0].a[i][0] = 1, i) f[1][0].a[i - 1][i] = 1;
  }
  f[0][0] = g[0] = I;
  FOR (i, 1, n) f[0][i] = I, f[1][i] = ksm(f[1][i - 1], 10);
  FOR (i, 2, 9) 
    FOR (j, 0, n) 
      f[i][j] = f[i - 1][j] * f[1][j];
  
  FOR (i, 1, n) {
    node t = f[ a[i] ][0];
    DFR(j, i - 1, 0)
      if (g[i] = g[i] + g[j] * t, j)
        t = t * f[ a[j] ][i - j];
  }
  cout << g[n].a[0][0] << "\n";
  return 0;
}