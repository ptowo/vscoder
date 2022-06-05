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
const int N = 600, mod = 998244353;
int n, a[N], dp[N][N];
signed main () {
  n = read(); for (int i = 0; i < n; i++) a[i] = read();
  for (int l = n; l >= 1; l--) {
    dp[l][l] = 1;
    for (int r = l + 1; r <= n; r++) {
      dp[l][r] = dp[l + 1][r];
      for (int k = l + 1; k < r; k++) 
        if (a[l] < a[k]) dp[l][r] += dp[l + 1][k] * dp[k][r] % mod, dp[l][r] %= mod;
    } 
  }
  cout << dp[1][n] << "\n";
  return 0;
}