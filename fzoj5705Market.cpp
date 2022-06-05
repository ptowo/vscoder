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
const int N = 2e5, inf = 2e14;
int n, m, sum, num, dp[305][N];
struct node { int c, v, t; } a[N];
signed main () {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) 
    a[i].c = read(), a[i].v = read(), a[i].t = read(), sum += a[i].v;
  sort(a + 1, a + n + 1, [&](node x, node y) { return x.t < y.t; } );
  for (int i = 0; i <= n; i++) 
    for (int j = 0; j <= sum; j++) dp[i][j] = inf;
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
      dp[i][j] = min(dp[i - 1][j], dp[i][j]);
      if (j >= a[i].v) dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i].v] + a[i].c);
    }
  }
  for (int i = 1; i <= n; i++) 
    for (int j = sum - 1; j >= 0; j--) 
      dp[i][j] = min(dp[i][j], dp[i][j + 1]);
  for (int i = 1; i <= m; i++) {
    int t = read(), mx = read();
    int l = 1, r = n, pos = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[mid].t <= t) pos = mid, l = mid + 1;
      else r = mid - 1;
    }
    l = 1, r = sum; int ans = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (dp[pos][mid] <= mx) ans = mid, l = mid + 1;
      else r = mid - 1;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
/*
价值为 c，单价为 v，开张时间为 t
dp[i][j] // 表示前 i 个商店达到 j 的价值需要的钱
300 * 300 = 9e4
*/