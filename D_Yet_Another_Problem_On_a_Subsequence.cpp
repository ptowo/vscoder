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
const int N = 2e6, mod = 998244353;
int n, a[N], dp[N], fac[N], ifac[N];
int power(int a,int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}
int c(int n,int m) {
  if (n == m) return 1;
  return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
signed main () {
  n = read();
  FOR (i, 1, n) a[i] = read();
  fac[0] = 1;
  FOR (i, 1, 1000) fac[i] = fac[i - 1] * i % mod;
  ifac[1000] = power(fac[1000], mod - 2);
  DFR (i, 999, 1) ifac[i] = ifac[i + 1] * (i + 1) % mod;
  dp[n + 1] = 1;
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] <= 0 || a[i] + i > n) continue;
    for (int j = i + a[i] + 1; j <= n + 1; j++) {
      dp[i] += c(j - i - 1, a[i]) * dp[j];
      dp[i] %= mod;
    }
  }
  int sum = 0;
  REP (i, 0, n) sum += dp[i], sum %= mod;
  cout << sum << "\n";
  return 0;
}