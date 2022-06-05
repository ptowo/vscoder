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
int n, p[N], bel, num, nex[N], first[N], v[N], w[N], t[N];
void add(int from,int to) {
  nex[++num] = first[from]; first[from] = num; v[num] = to; 
}
int tot, cnt, dfn[N], dep[N], siz[N], rt[N];
void dfs(int x,int fa) {
  dfn[x] = ++cnt, siz[x] = 1, w[cnt] = x;
  for (int i = first[x]; i; i = nex[i]) {
    int to = v[i];
    if (to == fa) continue;
    dfs(to, x), siz[x] += siz[to];
  }
}
int s[N], lc[N], rc[N];
void update(int k,int pre,int &now,int l,int r) {
  now = ++tot; lc[now] = lc[pre];  rc[now] = rc[pre];
  s[now] = s[pre] + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (k <= mid) update(k, lc[pre], lc[now], l, mid);
  else update(k, rc[pre], rc[now], mid + 1, r);
}
int ask(int pre,int now,int nx,int ny,int l,int r) {
  if (nx <= l && r <= ny) return s[now] - s[pre];
  int mid = (l + r) >> 1, ans = 0;
  if (nx <= mid) ans += ask( lc[pre], lc[now], nx, ny, l, mid);
  if (ny > mid) ans += ask( rc[pre], rc[now], nx, ny, mid + 1, r);
  return ans;
}
signed main () {
  n = read();
  FOR (i, 1, n)
    p[i] = read(), t[i] = p[i];
  bel = n;
  t[++bel] = INT_MAX;
  sort(t + 1, t + n + 1);
  bel = unique(t + 1, t + n + 1) - (t + 1);
  FOR (i, 2, n) {
    int fa = read(); add(fa, i);
  }
  dfs(1, 0);
  FOR (i, 1, n) 
    p[i] = lower_bound(t + 1, t + bel + 1, p[i]) - t;
  FOR (i, 1, n) {
    int now = w[i]; 
    update(p[now], rt[i - 1], rt[i], 1, bel);
  }
  FOR (i, 1, n) {
    if (siz[i] == 1) {  printf("0\n"); continue; }
    int L = dfn[i], R = dfn[i] + siz[i] - 1;
    int ans = ask(rt[L], rt[R], p[i] + 1, bel, 1, bel);
    printf("%lld\n", ans);
  }
  return 0;
}