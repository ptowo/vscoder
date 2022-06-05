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
const int N = 2e6;
int n, m, num, nex[N], first[N], v[N];
void add(int from,int to) { nex[++num] = first[from]; first[from] = num; v[num] = to; }
int st[N], scc[N], sc, in[N], dfn[N], low[N], cnt, tp;
void tarjan(int u, int fa) {
  dfn[u] = low[u] = ++cnt; st[++tp] = u;
  for (int i = first[u]; i; i = nex[i]) {
    int to = v[i];
    if (!dfn[to]) {
      tarjan(to, u);
      low[u] = min(low[u], low[to]);
      if (low[to] == dfn[u]) {
        scc[u] = ++sc;
        while (st[tp] != u) scc[st[tp]] = sc, tp--;
      }
    }
    else if(to != fa) low[u] = min(low[u], dfn[to]);
  }
  if (low[u] == dfn[u]) tp--;
}
vector <int> ver[N];
pair <int,int> e[N];
int dep[N], mx, pos;
void dfs(int x,int fa) {
  for (int i = 0; i < ver[x].size(); i++) {
    int to = ver[x][i];
    if (to == fa) continue;
    dep[to] = dep[x] + 1, dfs(to, x);
  }
  if (dep[x] > mx) 
    mx = dep[x], pos = x;
}
signed main () {
  n = read(), m = read();
  FOR (i, 1, m) { int x = read(), y = read(); add(x, y), add(y, x);  e[i] = {x, y}; }
  tarjan(1, 1);
  FOR (i, 1, n) if (!scc[i]) scc[i] = ++sc;
  FOR (i, 1, m) {
    int x = e[i].first, y = e[i].second;
    //cout << x << " " << y << " " << scc[x] << " " << scc[y] << "\n";
    if (scc[x] != scc[y]) 
      ver[ scc[x] ].emplace_back( scc[y] ), ver[ scc[y] ].emplace_back( scc[x] );
  }
  dfs(1, 0), dep[pos] = 0, dfs(pos, 0);
  cout << mx << "\n";
  return 0;
}
/*
1 2 1 1
2 3 1 1
3 1 1 1
4 1 2 1
5 2 3 1
2
*/