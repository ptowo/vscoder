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
const int N = 2e6;
int n, m, c[N];
double dp[N];
struct node { int s, t, w; double p; } a[N];
vector <int> ver[N];
int cmp(int x,int y) {
  return dp[ a[x].t ] + (double) 1.0 * a[x].w / a[x].p > dp[ a[y].t ] + (double) 1.0 * a[y].w / a[y].p;
}
signed main () {
  n = read(), m = read();
  int tot = m;
  REP (i, 1, n) {
    int x = read();  ++tot; 
    a[tot].s = i, a[tot].t = i + 1, a[tot].w = x; a[tot].p = 1.0;
    ver[i].emplace_back(tot);
  }
  FOR (i, 1, m) {
    int s = read(), t = read(); double p; cin >> p;
    int w = read();
    a[i].s = s, a[i].t = t, a[i].w = w; a[i].p = p;
    ver[s].emplace_back(i);
  }
  FOR (i, 1, n) dp[i] = 9999999.0;
  dp[n] = 0;
  DFR (i, n - 1, 1) {
    sort(ver[i].begin(), ver[i].end(), cmp);
    FORP (to, ver[i])
      dp[i] = min(dp[i], dp[i] * (1 - a[to].p) + dp[ a[to].t ] * a[to].p + a[to].w);
  }
  printf("%.2lf", dp[1]);
  return 0;
}