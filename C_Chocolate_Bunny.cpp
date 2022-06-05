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
const int N = 2e6;
int n, a[N], b[N], ans[N], vis[N];
signed main () {
  cin >> n;
  int mx = 0;
  for (int i = 2; i <= n; i++) {
    cout << "? " << i << " " << 1 << "\n"; cout.flush();
    cin >> a[i];
    if (a[i] > mx) mx = a[i];
  }
  ans[1] = mx + 1; mx = 0;
  for (int i = 1; i <= n; i++) {
    if (i == 1) continue;
    cout << "? " << i << " " << 2 << "\n"; cout.flush();
    cin >> b[i];
    if (b[i] > mx) mx = b[i];
  }
  ans[2] = mx + 1;
  vis[ ans[1] ] = 1; vis[ ans[2] ] = 1;
  for (int i = 3; i <= n; i++) {
    for (int k = 1; k <= n; k++) {
      if (vis[k]) continue;
      if (k % ans[1] == a[i] && k % ans[2] == b[i]) {
        ans[i] = k;
        vis[k] = 1;
        break;
      }
    }
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout.flush();
  return 0;
}
/*
每次询问 i != j 的 p[i] % p[j]
最多询问 2n 次，p 为 1~n
要求通过 2n 次询问得到 p
首先，询问 [1,2], [1,3],[1,4]..[1,n] 总共 n-1 次
如果这里面的最大值为 x 那么 p[1] = x + 1
然后，也不一定构造出来唯一的说
于是拿 a[2] 再问一遍
然后对于 a[3] 要满足为
*/