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
int ans, n, l, a[N], s[N];
priority_queue <int, vector <int>, greater<int> > q;
signed main () {
  n = read(), l = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) l -= a[i], q.push(a[i]);
  if (l) q.push(l);
  while (q.size() > 1) {
    int x = q.top(); q.pop(); int y = q.top(); q.pop();    
    ans += x + y; q.push(x + y);
  }
  printf("%lld\n", ans);
  return 0;
}