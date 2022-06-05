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
int n, q, nex[N], first[N], v[N], w[N], dis[N], a[N], num;
void add(int from,int to, int val) {
  nex[++num] = first[from]; first[from] = num;
  v[num] = to; w[num] = val;
}
int dep[N], siz[N], son[N], ff[N], top[N];
void dfs(int x,int fa) {
  dep[x] = dep[fa] + 1; ff[x] = fa; siz[x] = 1;
  for (int i = first[x]; i; i = nex[i]) {
    int to = v[i];
    if (to == fa) continue;
    dis[to] = dis[x] + w[i];
    dfs(to, x); siz[x] += siz[to];
    if (siz[to] > siz[ son[x] ]) son[x] = to;
  }
}
void dfs2(int now,int x) {
  top[now] = x;
  if (son[now]) dfs2(son[now], x);
  for (int i = first[now]; i; i = nex[i]) {
    int to = v[i];
    if (to == ff[now] || to == son[now]) continue;
    dfs2(to, to);
  }
}
int LCA(int x,int y) {
  while (top[x] != top[y]) {
    if (dep[ top[x] ] > dep[ top[y] ]) x = ff[top[x]];
    else y = ff[top[y]];
  }
  return dep[x] < dep[y] ? x : y;
}
int dp[N], DP[N], g[N];
void dfs3(int x,int fa) {
  dp[x] = a[x];
  for (int i = first[x]; i; i = nex[i]) {
    int to = v[i], val = w[i];
    if (to == fa) continue;
    dfs3(to, x);
    dp[x] += max(0ll, dp[to] - val * 2);
  }
}
void d2p(int x,int fa) {
  for (int i = first[x]; i; i = nex[i]) {
    int to = v[i];
    if (to == fa) continue;
    DP[to] = dp[to] + max(0ll, DP[x] - max(0ll, dp[to]- w[i] * 2) - w[i] * 2);
    g[to] = g[x] + min(dp[to], w[i] * 2);
    d2p(to, x);
  }  
}
signed main () {
  n = read(), q = read();
  FOR (i, 1, n)
    a[i] = read();
  REP (i, 1, n) {
    int u = read(), v = read(), w = read();
    add(u, v, w), add(v, u, w);
  }
  dfs(1, 0), dfs2(1, 1);
  dfs3(1, 0); DP[1] = dp[1]; d2p(1, 0);
  FOR (i, 1, q) {
    int u = read(), v = read(), l = LCA(u, v);
    int ans = g[u] + g[v] - 2 * g[l] + DP[l];
		ans -= (dis[u] - dis[l]) + (dis[v] - dis[l]);
    cout << ans << "\n";
  }
  return 0;
}