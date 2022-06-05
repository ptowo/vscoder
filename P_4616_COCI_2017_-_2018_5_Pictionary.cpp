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
const int N = 1e5 + 6;
int n, m, q, f[N][22], sum[N][22], dep[N], fa[N];
vector <int> ver[N], val[N];
int getfa(int x) {
  if (fa[x] != x) fa[x] = getfa(fa[x]);
  return fa[x];
}
void merge(int x,int y) {
  x = getfa(x), y = getfa(y);
  if (x != y)
    fa[x] = y;
}
void dfs(int x,int fa) {
  dep[x] = dep[fa] + 1;
  for (int i = 0; i < ver[x].size(); i++) {
    int to = ver[x][i], w = val[x][i];
    if (to == fa) 
      continue;
    dfs(to, x), f[to][0] = x, sum[to][0] = w;
  }
}
int lca(int x,int y) {
  int ans = 0;
  if (dep[x] < dep[y])
    swap(x, y);
  for (int i = 20; ~i; i--) if (dep[x] - (1 << i) >= dep[y]) ans = max(ans, sum[x][i]), x = f[x][i];
  if (x == y) return ans;
  for (int i = 20; ~i; i--) if (f[x][i] != f[y][i]) {
    ans = max(ans, max(sum[x][i], sum[y][i]));
    x = f[x][i], y = f[y][i];
  }
  chkmax(ans, sum[x][0]), chkmax(ans, sum[y][0]);
  return ans;
}
signed main () {
  n = read(), m = read(), q = read();
  FOR (i, 1, n) fa[i] = i;
  FOR (i, 1, m) {
    int now = m - i + 1;
    for (int j = now * 2; j <= n; j += now)  {
      if (getfa(j) != getfa(j - now)) {
        ver[j].emplace_back(j - now), ver[j - now].emplace_back(j);
        val[j].emplace_back(i), val[j - now].emplace_back(i);
        merge(j, j - now);
      }
    }
  }
  dfs(1, 0);
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i <= n; i++) {
      f[i][j] = f[ f[i][j - 1] ][j - 1];
      sum[i][j] = max(sum[i][j - 1], sum[ f[i][j - 1] ][j - 1]);
    }
  }
  FOR (i, 1, q) {
    int a = read(), b = read();
    printf("%lld\n", lca(a, b));
  }
  return 0;
}