// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 2e6;
int n, k, b[N], a[N], c[N][2], closed[N];
void solve() {
  int sum = 0, cnt = 0, ans = 0;
  for (int i = n; i >= k; i--) {
    if (b[i] > sum) {
      a[i] = (b[i] - sum) / k + ( (b[i] - sum) % k != 0);
      cnt += a[i], ans += a[i], sum += a[i] * k;
    }
    sum -= cnt;  cnt -= a[i + k - 1];
  }
  for (int i = k - 1; i >= 1; i--) {
    if (b[i] > sum) {
      a[i] = (b[i] - sum) / i + ( (b[i] - sum) % i != 0);
      cnt += a[i], ans += a[i], sum += a[i] * i;
    }
    sum -= cnt; cnt -= a[i + k - 1];
  }
  printf("%lld\n", ans);
}
signed main() {
  n = read(), k = read();
  for (int i = 1; i <= n; i++)
    b[i] = read();
  solve();
  return 0;
}
/*
倒过来做，等价于区间加等差数列，然后上数据结构就是了
然后，每次我们知道当前要执行的次数，然后开一个二元组，存进去，每次取出之后看是否删除即可
*/