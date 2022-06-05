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
const int N = 2e5;
int n, t[N];
string s[N];
map <string,int> vis;
signed main () {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  int ans = 0, pos = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> t[i];
    if (!vis[s[i]]) {
      if (t[i] > ans)
        ans = max(ans, t[i]), pos = i;
      vis[ s[i] ]++;
    }
  }
  cout << pos;
  return 0;
}