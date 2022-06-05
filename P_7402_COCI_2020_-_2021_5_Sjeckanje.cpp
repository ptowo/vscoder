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
const int N = 2e6, inf = 2e10;
inline int ls(int p) { return p << 1; }
inline int rs(int p) { return p << 1 | 1; }
int n, f[N][2][2], a[N], c[N], q;
void pushup(int p,int mid) {
  FOR (a, 0, 1) {
    FOR (b, 0, 1) {
      f[p][a][b] = -inf;
      FOR (i, 0, 1) {
        FOR (j, 0, 1) {
          if (i == 1 && j == 1 && c[mid] * c[mid + 1] < 0) continue;
          f[p][a][b] = max(f[p][a][b], f[ls(p)][a][i] + f[rs(p)][j][b]);
        }
      }
    }
  }
}
void change(int p,int l,int r, int pos) {
  if (r < pos || l > pos) return;
  if (l == r) {  f[p][1][1] = abs(c[l]); return; }
  int mid = (l + r) >> 1;
  change(ls(p), l, mid, pos), change(rs(p), mid + 1, r, pos);
  pushup(p, mid);
}
signed main () {
  n = read(), q = read();
  FOR (i, 1, n) {
    a[i] = read(), c[i] = (i == 1) ? 0 : a[i] - a[i - 1];
    change(1, 1, n, i);
  }
  FOR (i, 1, q) {
    int l = read(), r = read(), x = read();
    if (l != 1) 
      c[l] += x, change(1, 1, n, l);
    if (r != n) 
      c[r + 1] -= x, change(1, 1, n, r + 1);
    int ans = max(f[1][1][1], f[1][1][0]);
    ans = max(f[1][0][1], ans), ans = max(ans, f[1][0][0]);
    printf("%lld\n",ans);
  }
  return 0;
}