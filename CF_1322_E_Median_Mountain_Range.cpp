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
int n, ans, num, a[N], b[N], c[N], B[N], lg[N];
class st {
  public: int c[20][N];
  public: void work(int *a) {
    memcpy(c[0], a, (n + 1) << 2);
    REP(j, 1, 20) {
      for(int i = 0; i + (1 << j) - 1 <= n; i++)
      c[j][i] = wmin(c[j - 1][i], c[j - 1][i + (1 << (j - 1))]);
    }
  }
  public: int ask(int x,int d) {
    int l = x - d - 1, r = x + d, t = lg[r - l + 1];
    return wmin(c[t][l], c[t][r - (1 << t) + 1]);    
  }
} mx, mn;
signed main () {
  n = read();  FOR(i, 1, n) a[i] = read();
  lg[0] = -1;  FOR(i, 1, n + 1) lg[i] = lg[i >> 1] + 1;
  a[0] = a[1], a[n + 1] = a[n];
  FOR(i, 0, n) {
    b[i] = -wmin(a[i], a[i + 1]);  c[i] = wmax(a[i], a[i + 1]);
  }
  mn.work(c), mx.work(b);
  FOR(i, 1, n) {
    int l = 0, r = wmin(i - 1, n - i);
    int ta, tb, val = 0;
    while(l <= r) {
      int mid = (l + r) >> 1;
      ta = mn.ask(i, mid), tb = -mx.ask(i, mid);
      val = wmax(val, wmin(ta, tb));
      if(ta > tb) l = mid + 1;
      else r = mid - 1;
    }
    B[i] = val, ans = max(ans, r + 1);
  }
  printf("%lld\n", ans);
  FOR(i, 1, n) printf("%lld ",B[i]);
  return 0;
}