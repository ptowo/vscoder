// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 3e6, mod = 1e9 + 7;
int n, m, a, b, pt, pt2, k, ans, fac[N], ifac[N], dp[3005][3005], g[3005];
int power(int a,int b) { int ans = 1; while (b) { if (b & 1) ans = ans * a % mod; a = a * a % mod; b >>= 1;} return ans; }
int binom(int n,int m) { return fac[n] * ifac[m] % mod * ifac[n - m] % mod; }
int s[N], p[N], q[N];
signed main () {
  n = read(), m = read(), a = read(), b = read(), k = read(); 
  fac[0] = 1; for (int i = 1; i <= k; i++) fac[i] = fac[i - 1] * i % mod;
  ifac[k] = power(fac[k], mod - 2); for (int i = k - 1; ~i; i--) ifac[i] = ifac[i + 1] * (i + 1) % mod;
  pt = a * power(b, mod - 2) % mod; pt2 = 1 - pt; pt2 += mod; pt2 %= mod;
  for (int i = 0; i <= k && i <= m; i++) g[i] = binom(k, i) * power(pt, i) % mod * power(pt2, k - i) % mod;
  dp[0][m] = 1;  p[0] = g[0]; 
  for (int i = 1; i <= m; i++) p[i] = p[i - 1] + g[i], p[i] %= mod;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) s[j] = s[j - 1] + dp[i - 1][j], s[j] %= mod;
    for (int j = 1; j <= m; j++) q[j] = q[j - 1] + g[j] * s[j] % mod, q[j] %= mod;
    for (int r = 1; r <= m; r++) dp[i][r] = g[m - r] * ( (s[m] - s[m - r] + mod) % mod * p[r - 1] % mod - q[r - 1] + mod) % mod;
  }
  for (int i = 1; i <= m; i++) { ans += dp[n][i]; ans %= mod;}
  printf("%lld\n", ans);
  return 0;
}