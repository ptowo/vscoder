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
template<class T>T min(const T &a, const T &b) {return a < b ? a : b;}
template<class T>T max(const T &a, const T &b) {return a > b ? a : b;}
template<class T>bool chkmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
template<class T>bool chkmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 2e6, mod = 998244353;
int power(int a,int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    b >>= 1; 
    a = a * a % mod;
  }
  return ans;
}
int n, l, ans, c[N];
signed main () {
  n = read(), l = read();
  FOR (i, 1, n) {
    string s;  cin >> s;
    int len = s.size();
    REP (j, 0, len) c[i - 1] |= (1 << (s[j] - 'a'));
  }
  REP (i, 1, (1 << n) ) {
    int cnt = __builtin_popcount(i), now = (1 << 26) - 1;
    REP (j, 0, n)
      if ( i & (1 << j) ) now &= c[j];
    int qwq = __builtin_popcount(now);
    if (cnt % 2 == 1) ans += power(qwq, l), ans %= mod;
    else ans -= power(qwq, l), ans %= mod, ans += mod, ans %= mod;
  }
  cout << ans << "\n";
  return 0;
}