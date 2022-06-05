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
const int N = 2005;
int n, m, k;
struct mt {
  double f[N];
  mt() {memset(f, 0, sizeof(f)); }
  mt operator * (mt const &x) {
    mt res;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        res.f[i] += f[j] * x.f[(i - j + n) % n + 1];
      }
    }
    return res;
  }
}base, ans;
mt ksm(int k,mt a) {
  while (k) { if (k & 1) ans = ans * a; a = a * a; k >>= 1; } 
  return ans;
}
signed main () {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= n; i++) cin >> ans.f[i];
  double A = (double)1.0 * (m - 1) / m;
  double B = (double) 1.0 / m;
  base.f[1] = A; base.f[2] = B;
  mt ans2 = ksm(k, base);
  for (int i = 1; i <= n; i++) printf("%.3lf\n", ans.f[i]);
  return 0;
}