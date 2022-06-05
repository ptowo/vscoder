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
const int N = 200;
int r, s, p;
double dp[N][N][N], ans1 = 0.0, ans2 = 0.0, ans3 = 0.0;
signed main () {
  r = read(), s = read(), p = read();
  dp[r][s][p] = 1;
  for (int i = r; i >= 0; i--) {
    for (int j = s; j >= 0; j--) {
      for (int k = p; k >= 0; k--) {
        double tot = i * j + j * k + i * k;
        if (i && k) dp[i - 1][j][k] += 1.0 * dp[i][j][k] * k * i / tot;
        if (j && i) dp[i][j - 1][k] += 1.0 * dp[i][j][k] * i * j / tot;
        if (k && j) dp[i][j][k - 1] += 1.0 * dp[i][j][k] * j * k / tot;
        if (i && !j && !k) ans1 += dp[i][j][k];
        if (j && !i && !k) ans2 += dp[i][j][k];
        if (k && !i && !j) ans3 += dp[i][j][k];
      }
    }
  }
  printf("%.9lf %.9lf %.9lf\n", ans1, ans2, ans3);
  return 0;
}