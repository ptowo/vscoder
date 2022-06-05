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
const int N = 2e6;
int ans = INT_MAX, n, a[N], b[N], c[N], dp[N][2];
signed main () {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  dp[1][1] = a[1];  dp[1][0] = INT_MAX;
  for (int i = 2; i <= n; i++) {
    dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + a[i];
    dp[i][0] = dp[i - 1][1];
  }
  dp[1][1] = INT_MAX; dp[1][0] = a[n];
  int ans = min(dp[n][0], dp[n][1]);
  for (int i = 2; i < n; i++) {
    dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + a[i];
    dp[i][0] = dp[i - 1][1];
  }
  ans = min(ans, dp[n - 1][1]);
  ans = min(ans, dp[n - 1][0]);
  cout << ans;
  return 0;
}
/* 
dp[i][0/1] 使用/不用 a[i] 时，让每个动物被喂的价值
dp[i][1] = min(dp[i-1][1],dp[i-1][0]) + a[i]
dp[i][0] = dp[i-1][1]
*/