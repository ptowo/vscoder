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
int n, tot, now, las, ans[N], a[N], c[N];
struct node { int op, x; } b[N];
signed main () {
  n = read();
  int tt = 1e18, num = 0;
  FOR (i, 1, n) {
    int x = read(), y = read();
    b[++tot] = node{1, x};
    b[++tot] = node{-1, y + 1};
    a[++num] = x, a[++num] = y + 1;
  }
  a[++num] = 0;
  sort(a + 1, a + num + 1);
  num = unique(a + 1, a + num + 1) - (a + 1);
  FOR (i, 1, tot) {
    int ti = lower_bound(a + 1, a + num + 1, b[i].x) - a;
    c[ti] = b[i].x, b[i].x = ti;
    chkmin(tt, ti);
  }
  sort(b + 1, b + tot + 1, [](node x, node y) { return x.x != y.x ? x.x < y.x : x.op < y.op; });
  int j = 1;
  while (j <= tot && b[j].x == 1) now += b[j].op, j++;
  FOR (i, 2, num) { //扫描每个更新位置
    ans[now] += c[i] - c[i - 1];
    //cout << now << " " << i << " " << i - 1 << " " << c[i] << " " << c[i - 1] << "\n";
    while (j <= tot && b[j].x == i) now += b[j].op, j++;
  }
  FOR (i, 1, n) 
    printf("%lld ", ans[i]);
  return 0;
}