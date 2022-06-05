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
int n, m, a[N], num, nex[N], first[N], v[N];
void add(int from,int to) {
  nex[++num] = first[from]; first[from] = num; v[num] = to;
}
int vis[N], siz[N], son[N], cent, SUM, sz[N], f[N];
void getroot(int u,int fa) {
  siz[u] = 1; son[u] = 0;
  for (int i = first[u]; i; i = nex[i]) {
    int to = v[i]; if (to == fa || vis[to]) continue;
    getroot(to, u); siz[u] += siz[to]; son[u] = max(son[u], siz[to]);
  }
  son[u] = max(son[u], SUM - son[u]);
  if (son[u] < son[cent]) cent = u;
}
vector <int> c[2][N], G[N];
void solve(int u) {
  vis[u] = 1; sz[u] = SUM + 1;
  c[0][u].resize(sz[u] + 6);
  c[1][u].resize(sz[u] + 6);
  for (int i = first[u]; i; i = nex[i]) {
    int to = v[i]; if (vis[to]) continue;
    SUM = siz[to]; cent = 0; son[0] = inf;
    getroot(to, 0); int now = cent; f[cent] = u;  G[u].push_back(cent);
    solve(cent);
  }
}
int lowbit(int x) { return x & (-x);}
void change(int pos,int val,int op,int u) {
  pos++;
  for (int i = pos; i <= sz[u]; i += lowbit(i)) c[op][u][i] += val;
}
int ask(int pos,int op,int u) {
  int ans = 0; pos++; pos = min(pos, sz[u]);
  for (int i = pos; i; i -= lowbit(i)) ans += c[op][u][i];
  return ans;
}
int las, dep[N], top[N], ff[N];
void dfs1(int x,int fa) {
  ff[x] = fa, dep[x] = dep[fa] + 1, siz[x] = 1; son[x] = 0;
  for (int i = first[x]; i; i = nex[i]) {
    int to = v[i]; if (to == fa) continue;
    dfs1(to, x); siz[x] += siz[to]; if (siz[to] > siz[ son[x] ]) son[x] = to;
  }
}
void dfs2(int now,int x) {
  top[now] = x; if (son[now]) dfs2(son[now], x);
  for (int i = first[now]; i; i = nex[i]) {
    int to = v[i]; if (to == ff[now] || to == son[now]) continue; 
    dfs2(to, to);
  }
}
int LCA(int x,int y) {
  while (top[x] != top[y]) {
    if (dep[ top[x] ] >= dep[ top[y] ]) x = ff[top[x]];
    else y = ff[top[y]];
  }
  return dep[x] < dep[y] ? x : y;
}
int getdis(int x,int y) {
  return dep[x] + dep[y] - dep[LCA(x, y)] * 2;
}
void update(int u,int val) {
  for (int i = u; i; i = f[i]) change(getdis(u, i), val, 0, i);
  for (int i = u; f[i]; i = f[i]) change(getdis(u, f[i]), val, 1, i);
}
signed main () {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read(); 
    add(u, v), add(v, u);
  }
  
  vis[0] = 1;
  SUM = n; son[0] = n; cent = 0; getroot(1, 0);
  int qwq = cent;  solve(cent);
  for (int i = 1; i <= n; i++) {
    cout << i << " ";
    for (auto it : G[i]) cout << it << " ";
    cout << "\n";
  }/*
  dfs1(qwq, 0), dfs2(qwq, qwq);
  for (int i = 1; i <= n; i++) update(i, a[i]);
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    int op = read(), x = read(), y = read(); x ^= las; y ^= las;
    if (op == 1) {
      update(x, y - a[x]); a[x] = y;
    }  else {
      ++cnt;
      int ans = ask(y, 0, x); 
      for (int i = x; f[i]; i = f[i]) {
        int dis = getdis(x, f[i]);
        if (y >= dis) ans += ask(y - dis, 0, f[i]) - ask(y - dis, 1, i);
      }
      las = ans; printf("%lld\n", ans);
    }
  }*/
  return 0;
}
