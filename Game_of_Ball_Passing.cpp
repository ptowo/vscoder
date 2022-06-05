// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
#define int long long
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
const int N = 5e6;
int T, n, a[N], vib[N];
signed main () {
  T = read(); 
  while(T--) {
    n = read();  int ans = 0, mx = 0; 
    FOR(i, 1, n) a[i] = read(), ans += a[i];
    if(!ans) {  printf("0\n");  continue;  }
    FOR(i, 1, n) mx = max(mx, a[i]);
    int cnt = 0, p = mx;
    FOR(i, 1, n) {
      if(a[i] != p || (a[i] == p && cnt == 1)) {
        mx -= a[i];
      }
      if(a[i] == p && cnt == 0) cnt = 1; 
    }
    if(mx > 0) printf("%lld\n",mx);
    else printf("1\n");
  }
  return 0;
}