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
int n, m, a[N], vis[N];
signed main () {
  n = read(), m = read();
  FOR (i, 1, n) 
    a[i] = read();
  sort(a + 1, a + n + 1);
  while (m--) {
    int k = read(), ans = 0;
    if ( !k || n == 1 ) {
      FOR (i, 1, n) ans += pow(a[i], 2);
      printf("%lld\n", ans); continue;
    }
    int t = __gcd(n, k), p = n / t;
    if (vis[p]) { printf("%lld\n", vis[p]); continue; }
    for (int i = 1; i <= n; i += p) {
      REP (j, 0, p - 2) ans += (a[i + j] * a[i + j + 2]);
      ans += (a[i] * a[i + 1] + a[i + p - 1] * a[i + p - 2]);
    }
    printf("%lld\n", ans); vis[p] = ans;
  }
  return 0;
}