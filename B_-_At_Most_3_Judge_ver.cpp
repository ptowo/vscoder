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
const int N = 6e6;
int n, w, a[N], vis[N];
signed main () {
  n = read(); w = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) {
    int x = a[i]; vis[x] = 1;
    for (int j = i + 1; j <= n; j++) {
      int y = a[j]; vis[x + y] = 1;
      for (int k = j + 1; k <= n; k++) {
        int z = a[k]; vis[x + y + z] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= w; i++) ans += (vis[i] == 1);
  cout << ans;
  return 0;
}