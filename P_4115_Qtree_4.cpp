// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 3e5, inf = 2e7;
int n, m, a[N], num, nex[N], first[N], v[N], di[N], vis[N], siz[N], son[N], cent, SUM, sz[N], f[N], dep[N], top[N], ff[N], col[N], w[N];
void add(int from,int to,int val) { nex[++num] = first[from]; first[from] = num; v[num] = to; w[num] = val;}
void getroot(int u,int fa) {
  siz[u] = 1; son[u] = 0;
  for (int i = first[u]; i; i = nex[i]) { int to = v[i]; if (to == fa || vis[to]) continue; getroot(to, u); siz[u] += siz[to]; son[u] = max(son[u], siz[to]); }
  son[u] = max(son[u], SUM - son[u]); if (son[u] < son[cent]) cent = u;
}
void solve(int u) {
  vis[u] = 1;
  for (int i = first[u]; i; i = nex[i]) {int to = v[i]; if (vis[to]) continue; SUM = siz[to]; cent = 0; son[0] = inf; getroot(to, 0); int now = cent; f[cent] = u; solve(cent); }
}
void dfs1(int x,int fa) {
  ff[x] = fa, dep[x] = dep[fa] + 1, siz[x] = 1; son[x] = 0;
  for (int i = first[x]; i; i = nex[i]) { int to = v[i]; if (to == fa) continue; di[to] = di[x] + w[i]; dfs1(to, x); siz[x] += siz[to]; if (siz[to] > siz[ son[x] ]) son[x] = to; }
}
void dfs2(int now,int x) {
  top[now] = x; if (son[now]) dfs2(son[now], x);
  for (int i = first[now]; i; i = nex[i]) { int to = v[i]; if (to == ff[now] || to == son[now]) continue;  dfs2(to, to); }
}
int LCA(int x,int y) {
  while (top[x] != top[y]) { if (dep[ top[x] ] >= dep[ top[y] ]) x = ff[top[x]]; else y = ff[top[y]]; }
  return dep[x] < dep[y] ? x : y;
}
int getdis(int x,int y) { return di[x] + di[y] - di[LCA(x, y)] * 2; }
multiset <int> s[N];
void update(int x) {
  for (int i = x; i; i = f[i]) {
    int dis = getdis(x, i);
    if (col[x] == 0) s[i].insert(dis);
    else if (s[i].find(dis) != s[i].end()) s[i].erase(s[i].find(dis));
  }
  col[x] ^= 1;
}
int ask(int x) {
  int ans = inf;
  for (int i = x; i; i = f[i]) {
    int now = getdis(x, i);
    if (s[i].size()) ans = min(ans, now + *s[i].begin());
  }
  if (ans == inf) return -1;
  return ans;
}
signed main () {
  n = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read(), val = read(); 
    add(u, v, val), add(v, u, val);
  }
  vis[0] = 1; SUM = n; son[0] = n; cent = 0; getroot(1, 0); int qwq = cent;  solve(cent); dfs1(qwq, 0), dfs2(qwq, qwq); m = read();
  for (int i = 1; i <= m; i++) {
    int op = read(), x = read();
    if (op == 0) update(x);
    else {
      if (!col[x]) printf("%d\n", ask(x));
      else printf("%d\n", 0);
    }
  }
  return 0;
}