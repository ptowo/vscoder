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
const int N = 450, L = 30, inf = 1e17;
int n, m, t, k, a[N];
struct mt {
  int n, m, a[N][N];
  mt operator * (const mt &b) const {
    mt res; res.n = n, res.m = b.m;
    for (int i = 1; i <= n; i++) 
      for (int j = 1; j <= b.m; j++) res.a[i][j] = -inf;
    for (int i = 1; i <= n; i++) 
      for (int k = 1; k <= m; k++) 
        for (int j = 1; j <= b.m; j++) 
          res.a[i][j] = max(res.a[i][j], a[i][k] + b.a[k][j]);
    return res;
  }
}A, G[40];
struct node {int t, x, y; } ask[N];
signed main() {
  //freopen("delicacy.in", "r", stdin);
  //freopen("delicacy.out", "w", stdout);
  n = read(), m = read(), t = read(), k = read();
  G[0] = {5 * n, 5 * n};
  for (int i= 1; i <= 5 * n; i++) 
    for (int j = 1; j <= 5 * n; j++)
      G[0].a[i][j] = -inf;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 0; j <= 4; j++) G[0].a[j * n + i][(j + 1) * n + i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read(), w = read();
    G[0].a[(w - 1) * n + u][v] = a[v];
  }
  for (int i = 1; i <= L; i++) G[i] = G[i - 1] * G[i - 1];
  ask[0] = {0, 0, 0}; ask[k + 1] = {t, 0, 0};
  for (int i = 1; i <= k; i++) ask[i].t = read(), ask[i].x = read(), ask[i].y = read();
  sort(ask + 1, ask + k + 1, [&](node x,node y) {return x.t < y.t;});
  A = {1, 5 * n}; A.a[1][1] = a[1];
  for (int i = 2; i <= 5 * n; i++) A.a[1][i] = -inf;
  for (int i = 1; i <= k + 1; i++) {
    int s = ask[i].t - ask[i - 1].t;
    for (int j = 0; j <= L; j++, s >>= 1) if (s & 1) A = A * G[j];
    A.a[1][ask[i].x] += ask[i].y;
  }
  if (A.a[1][1] < 0) puts("-1");
  else printf("%lld\n", A.a[1][1]);
  return 0;
}
