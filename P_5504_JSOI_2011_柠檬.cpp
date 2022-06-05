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
int n, s[N], c[N], st[N], dp[N], tp, x[N], y[N];
vector <int> q[N];
double Y(int i) { return y[i]; }
double X(int i) { return x[i];  }
double slope(int i,int j) { return (double) 1.0 * (Y(i) - Y(j)) / (X(i) - X(j)); }
signed main () {
  n = read(); for (int i = 1; i <= n; i++) s[i] = read();
  for (int i = 1; i <= n; i++) st[i] = ++c[ s[i] ];
  for (int i = 1; i <= n; i++) {
    int cur = s[i]; tp = q[cur].size() - 1;
    x[i] = (st[i] - 1) * cur;
    y[i] = x[i] * (st[i] - 1) + dp[i - 1];
    while (tp > 0 && slope(q[cur][tp - 1], q[cur][tp]) < slope(q[cur][tp], i)) q[cur].pop_back(), tp--;
    q[cur].emplace_back(i), tp++;
    while (tp > 0 && slope(q[cur][tp - 1], q[cur][tp]) < 2 * st[i]) q[cur].pop_back(), tp--;
    int tmp = q[cur][tp];
    dp[i] = dp[tmp - 1] + cur * (st[i] - st[tmp] + 1) * (st[i] - st[tmp] + 1);
  }  
  printf("%lld\n", dp[n]);
  return 0;
}