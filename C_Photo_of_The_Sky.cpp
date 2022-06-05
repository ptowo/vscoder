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
int n, a[N];
void solve() {
  int mid = n >> 1;
  int ans = (a[mid] - a[1]) * (a[n] - a[mid + 1]);
  for (int i = 2; i <= mid; i++) 
    ans = min(ans, (a[mid + i - 1] - a[i]) * (a[n] - a[1]));
  printf("%lld\n", ans);
}
signed main() {
  n = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  sort(a + 1, a + n + 1);
  solve();
  return 0;
}
/*
ans = (max(x) - min(x)) * (max(y) - min(y))
最大化这个值
假设最大值与最小值都在 x 或者 y，那么要最小化这个
*/