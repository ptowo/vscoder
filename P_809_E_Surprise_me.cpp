// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
// 其实 vflower 也很可爱（（（
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, l, r) for(int i = (l); i <= r; ++i)
#define REP(i, l, r) for(int i = (l); i <  r; ++i)
#define DFR(i, l, r) for(int i = (l); i >= r; --i)
#define DRP(i, l, r) for(int i = (l); i >  r; --i)
#define FORV(i, ver) for(int i = 0; i < ver.size(); i++)
#define FORP(i, ver) for(auto i : ver)
#define Fedge(i, x) for (int i = first[x]; i; i = nex[i])
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
const int N = 6e5, mod = 1e9 + 7;
int n, num, nex[N], first[N], v[N], a[N], phi[N], vis[N], mu[N], pr[N], cnt;
int power(int a,int b) {  int ans = 1;  while (b) { if (b & 1) ans = ans * a % mod; a = a * a % mod; b >>= 1; } return ans;  }
void add(int from,int to) { nex[++num] = first[from]; first[from] = num; v[num] = to; }
void getphi(int n) {
  mu[1] = phi[1] = vis[1] = 1;  FOR (i, 2, n) {  if (!vis[i]) pr[++cnt] = i, phi[i] = i - 1, mu[i] = -1;
    for (int j = 1; j <= cnt && i * pr[j] <= n; j++) {
      vis[i * pr[j]] = 1;  if (i % pr[j]) phi[i * pr[j]] = phi[i] * phi[pr[j]], mu[i * pr[j]] = -mu[i];
      else {phi[i * pr[j]] = phi[i] * pr[j]; mu[i * pr[j]] = 0; break;}
    }
  }
}
int dep[N], ff[N], siz[N], top[N], son[N], dfn[N], tot;
void dfs(int x,int fa) {
  dep[x] = dep[fa] + 1; siz[x] = 1;  ff[x] = fa;  dfn[x] = ++tot;
  Fedge (i, x) {  int to = v[i];  if (to == fa) continue;  dfs(to, x);  (siz[to] > siz[ son[x] ] ) && (son[x] = to);  siz[x] += siz[to]; }
}
void dfs2(int now,int x) {
  top[now] = x;  if (son[now]) dfs2(son[now], x);
  Fedge (i, now) {  int to = v[i]; if (to == son[now] || to == ff[now]) continue;  dfs2(to, to);  }
}
int LCA(int x, int y) {
  while (top[x] != top[y]) {  if (dep[top[x]] <= dep[top[y]])  y = ff[top[y]];  else  x = ff[top[x]];  }
  return dep[x] < dep[y] ? x : y;
}
vector <int> p[N];
int vert[N], vg[N], dp[N], ans, F[N], f[N];
int cmp(int x,int y) {  return dfn[x] < dfn[y];  }
void DP(int x,int fa) {
  dp[x] = 0;
  if (vg[x]) ans = (ans + 2 * phi[ a[x] ] * phi[ a[x] ] * dep[x] % mod) % mod, dp[x] = phi[ a[x] ];
  FORP (to, p[x]) {  if (to == fa) continue; DP(to, x); ans = (ans + 4 * dp[x] * dp[to] % mod * dep[x] % mod) % mod;  
    dp[x] = (dp[x] + dp[to]) % mod; dp[to] = 0;
  }
}
signed main () {
  n = read();  getphi(n);  FOR (i, 1, n) a[i] = read();
  REP (i, 1, n) {  int x = read(), y = read();  add(x, y), add(y, x);  }  dfs(1, 0);  dfs2(1, 1);
  FOR (i, 1, n) vis[i] = 0; FOR (i, 1, n) vis[a[i]] = i; num = 0;
  FOR (i, 1, n) {
    if (i > n / 2) continue;
    int now = a[i], sum = 0, re = 0; num = 0;
    for (int j = i; j <= n; j += i) {
      vg[ vis[j] ] = 1;  vert[++num] = vis[j];
      sum = (sum + phi[j] * dep[ vis[j] ] % mod) % mod;
      re = (re + phi[j]) % mod;
    } 
    sort (vert + 1, vert + num + 1, cmp); int gg = num;
    FOR (j, 2, gg) {  int lca = LCA(vert[j], vert[j - 1]);  vert[++num] = lca;  }
    sort (vert + 1, vert + num + 1);  num = unique(vert + 1, vert + num + 1) - (vert + 1);  sort (vert + 1, vert + num + 1, cmp);
    FOR (j, 2, num) {  int lca = LCA(vert[j], vert[j - 1]);  p[lca].push_back(vert[j]);  }
    DP(vert[1], vert[1]);
    FOR (j, 1, num) p[ vert[j] ].clear(), vg[ vert[j] ] = 0;
    sum *= re; sum %= mod;  dp[1] = 0; F[i] = (sum * 2 - ans + mod) % mod; ans = 0; num = 0;
  }
  cout << "\n";
  FOR (i, 1, n) {
    for (int j = i; j <= n; j += i) {
      f[i] += F[j] * mu[j / i];  f[i] = (f[i] + mod) % mod;
    }
  }
  FOR (i, 1, n) ans = (ans + i * power(phi[i], mod - 2) % mod * f[i] % mod) % mod;
  ans = ans * power(n, mod - 2) % mod;  ans = ans * power(n - 1, mod - 2) % mod;
  write(ans); putchar('\n');
  return 0;
}