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
const int N = 2e5, inf = 1e17;
int n, m, v, e, c[N], d[N];
double k[N], dp[3005][3005][2], ans = inf, dis[305][305];
void chkmin(double &x,double y) { if (y < x) x = y; }
signed main () {
  n = read(), m = read(), v = read(), e = read();
  for (int i = 1; i <= n; i++) c[i] = read(); 
  for (int i = 1; i <= n; i++) d[i] = read();
  for (int i = 1; i <= n; i++) scanf("%lf", &k[i]);
  for (int i = 1; i <= v; i++) 
    for (int j = 1; j <= v; j++)
      dis[i][j] = inf;
  for (int i = 1; i <= e; i++) {
    int a = read(), b = read(), c = read();
    dis[a][b] = dis[b][a] = min(dis[a][b], (double)c);
  }
  for (int k = 1; k <= v; k++)
    for (int i = 1; i <= v; i++)
      for (int j = 1; j <= v; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  for (int i = 1; i <= v; i++) dis[i][0] = dis[0][i] = dis[i][i] = 0;
  for (int i = 0; i <= n; i++) 
    for (int j = 0; j <= m; j++)
      dp[i][j][0] = dp[i][j][1] = inf;
  dp[1][1][1] = dp[1][0][0] = 0;
  for (int i = 2; i <= n; i++) {
    dp[i][0][0] = dp[i - 1][0][0] + dis[c[i - 1]][c[i]];
    for (int j = 1; j <= min(i, m); j++) {
      chkmin(dp[i][j][0], dp[i - 1][j][0] + dis[c[i - 1]][c[i]]);
      chkmin(dp[i][j][0], dp[i - 1][j][1] + (double) (1.0 - k[i - 1]) * dis[c[i - 1]][c[i]] + (double) k[i - 1] * dis[d[i - 1]][c[i]]);
      chkmin(dp[i][j][1], dp[i - 1][j - 1][0] + (double) (1.0 - k[i]) * dis[c[i - 1]][c[i]] + (double) k[i] * dis[c[i - 1]][d[i]] );
      chkmin(dp[i][j][1], dp[i - 1][j - 1][1] + (double) k[i - 1] * k[i] * dis[d[i - 1]][d[i]] + (double) k[i - 1] * (1.0 - k[i]) * dis[d[i - 1]][c[i]] + (double) (1.0 - k[i - 1]) * (1.0 - k[i]) * dis[c[i - 1]][c[i]] + (double) (1.0 - k[i - 1]) * k[i] * dis[c[i - 1]][d[i]] );
    }
  }
  for (int i = 0; i <= m; i++) {
    ans = min(ans, dp[n][i][0]); ans = min(ans, dp[n][i][1]);
  }
  printf("%.2lf\n", ans);
  return 0;
}