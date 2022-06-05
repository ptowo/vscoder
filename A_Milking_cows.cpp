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
int n, cnt, ans, a[N];
signed main () {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) {
    if (a[i]) cnt++;
    else ans += cnt;
  }
  printf("%lld\n", ans);
  return 0;
}
/*
每头奶牛有两个方向，一个是向左，一个是向右
给奶牛挤奶的时候
所有看得到当前奶牛的都会海派并失去 1 单位牛奶
朝左边的奶牛看到所有低于她的指数的奶牛
*/