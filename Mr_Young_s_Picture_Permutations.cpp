// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
int n, a[6], dp[31][31][31][31][31];
signed main () {
  while (1) {
    n = read(); if (!n) break;
    memset(a, 0, sizeof(a)); memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) a[i] = read();
    dp[0][0][0][0][0] = 1;
    for (int i = 0; i <= a[0]; i++) {
      for (int j = 0; j <= a[1]; j++) {
        for (int k = 0; k <= a[2]; k++) {
          for (int l = 0; l <= a[3]; l++) {
            for (int t = 0; t <= a[4]; t++) {
              if (i) dp[i][j][k][l][t] += dp[i - 1][j][k][l][t];
              if (j && j <= i) dp[i][j][k][l][t] +=  dp[i][j - 1][k][l][t];
              if (k && k <= j) dp[i][j][k][l][t] += dp[i][j][k - 1][l][t];
              if (l && l <= k) dp[i][j][k][l][t] += dp[i][j][k][l - 1][t];
              if (t && t <= l) dp[i][j][k][l][t] += dp[i][j][k][l][t - 1];
            }
          }
        }
      }
    }
		printf("%d\n", dp[a[0]][a[1]][a[2]][a[3]][a[4]]);
  }
  return 0;
}