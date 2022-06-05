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
const int N = 3e6;
int n, m, k, c[2005][2005], ps[N], cs[N], f1[N], f2[N];
pair <int,int> a[N];
int binom(int n,int m) {
  if (m < 0 || m > n) return 0;
  if (n < 7) return c[n][m];
  return binom(n / 7, m / 7) * c[n % 7][m % 7] % 7;
}
int calc(int n,int m) {
  if (n < 7) {
    int ans = 0;
    for (int j = 0; j < min(m, n + 1); j++) ans = (ans + c[n][j]) % 7;
    return ans;
  }
  int cc = 0;
  for (int j = 0; j < 7; j++) cc += c[n % 7][j];
  int ans = calc(n / 7, m / 7) * cc % 7;
  for (int j = m / 7 * 7; j < m; j++) ans = (ans + binom(n, j)) % 7;
  return ans;
}
signed main () {
  n = read(), m = read(), k = read();
  for (int i = 0; i < m; i++) 
    a[i].first = read(), a[i].second = read();
  for (int i = 0; i < 8; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 7;
  }
  int d = n - k, sum = 0;
  for (int i = 0; i < m; i++) {
    sum += a[i].second; 
    ps[i + 1] = calc(d, sum) % 7; 
    cs[i + 1] = sum;
  }
  for (int i = 0; i < 117649; i++) f1[i] = binom(d % 117649, i), f2[i] = binom(d / 117649, i);
  for (int i = 0; i < k; i++) {
    int ans = 0;
    for (int j = 0; j < m; j++) ans = ans + (ps[j + 1] - ps[j]) * a[j].first;
    ans %= 7; ans += 7; ans %= 7; printf("%lld ", ans);
    for (int j = 0; j <= m; j++) {
      if (cs[j] > 0) {
        ps[j] = ps[j] - f1[(cs[j] - 1) % 117649] * f2[(cs[j] - 1)/117649] % 7;
        cs[j]--;
      }
    }
  }
  return 0;
}