// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 2e5;
int n, k, a[N], pre[N], no[N], dp[N][65];
class SegmentTree {
  public: int s[N], tag[N];
  public: inline int ls(int p) { return p << 1; }
  public: inline int rs(int p) { return p << 1 | 1; }
  public: void pushup(int p) { s[p] = max(s[ls(p)], s[rs(p)]); }
  public: void f(int p,int val) { s[p] += val; tag[p] += val; }
  public: void pushdown(int p,int l,int r) { int mid = (l + r) >> 1; f(ls(p), tag[p]); f(rs(p), tag[p]); tag[p] = 0; }
  public: void update(int p,int l,int r,int nx,int ny,int val) {
    if (ny < nx) return;
    if (nx <= l && r <= ny) { s[p] += val; tag[p] += val; return; }
    pushdown(p, l, r); int mid = (l + r) >> 1;
    if (nx <= mid) update(ls(p), l, mid, nx, ny, val); 
    if (ny > mid) update(rs(p), mid + 1, r, nx, ny, val);
    pushup(p);
  }
  public: int ask(int p,int l,int r,int nx,int ny) {
    if (ny < nx) return 0;
    if (nx <= l && r <= ny) return s[p];
    pushdown(p, l, r); int mid = (l + r) >> 1, ans = 0;
    if (nx <= mid) ans = max(ans, ask(ls(p), l, mid, nx, ny)); 
    if (ny > mid) ans = max(ans, ask(rs(p), mid + 1, r, nx, ny));
    pushup(p); return ans;
  }
  public: void build(int p,int l,int r,int id) {
    tag[p] = s[p] = 0;
    if (l == r) { s[p] = dp[id - 1][l - 1]; return; }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid, id), build(rs(p), mid + 1, r, id);
    pushup(p);
  }
} s[2];
signed main () {
  n = read(), k = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) { pre[i] = no[ a[i] ] + 1; no[ a[i] ] = i;}
  int las = 0;
  for (int i = 1; i <= k; i++) {
    s[las].build(1, 1, n, i);
    for (int j = 1; j <= n; j++) {
      s[las].update(1, 1, n, pre[j], j, 1);
      int mx = s[las].ask(1, 1, n, i, j);
      dp[i][j] = mx;
    }
  }
  cout << dp[k][n] << "\n";
  return 0;
}