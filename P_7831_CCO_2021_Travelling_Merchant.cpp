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
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return ;
}
const int N = 2e6, inf = 2e10;
int n, m, deg[N], ans[N], vis[N];
struct node {  int a, b, r, p; } ask[N];
vector <int> ver[N];
int cmp(node x, node y) {  return x.r > y.r;  }
queue <int> q;
signed main () {
  n = read(), m = read();
  FOR (i, 1, n) ans[i] = inf;
  FOR (i, 1, m) {  ask[i].a = read(), ask[i].b = read(), ask[i].r = read(), ask[i].p = read();  deg[ ask[i].a ]++; }
  FOR (i, 1, n) if ( !deg[i] ) q.push(i);
  sort(ask + 1, ask + m + 1, cmp);
  FOR (i, 1, m) ver[ ask[i].b ].emplace_back( i );
  FOR (i, 1, m) {
    while (!q.empty()) {
      int u = q.front(); q.pop();
      FORP (j, ver[u]) {
        if (vis[j]) continue; -- deg[ ask[j].a ];
        vis[j] = 1;   if ( !deg[ask[j].a] )  q.push(ask[j].a);
        if (ans[u] != inf) chkmin( ans[ask[j].a], wmax(ask[j].r, ans[u] - ask[j].p) );
      }
    }
    if (!vis[i]) {
      vis[i] = 1; --deg[ ask[i].a ];
      if (!deg[ ask[i].a ]) q.push(ask[i].a);
      chkmin( ans[ ask[i].a ], ask[i].r );
    }
  }
  FOR (i, 1, n) write( ans[i] == inf ? -1 : ans[i] ), putchar(' ');
  return 0;
}
/*
考虑 -1 是什么情况
*/