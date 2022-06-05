// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  } while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 5005;
int n, m, k, t, a[N][N], dp[N][N];
int l, r;
struct node { int id, val; } q[N];
void pop(int id) {
  while (l != r) {
    if (q[l].id < id) l++;
    else return;
  }
}
void push(int id,int val) {
  while (l != r) {
    if (q[r - 1].val <= val) r--;
    else break;
  }
  q[r++] = {id, val}; return;
}
signed main () {
  n = read(), m = read(), k = read(), t = read();
  for (int i = 1; i <= k; i++) { int x = read(), y = read(), val = read(); a[x][y] += val; }
  for (int i = 1; i <= n; i++) {
    l = r = 1;
    for (int j = 1; j <= t; j++) push(j, dp[i - 1][j]);
    for (int j = 1; j <= m; j++) {
      pop(j - t);
      if (j + t <= m) push(j + t, dp[i - 1][j + t]);
      dp[i][j] = q[l].val + a[i][j];
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) ans = max(ans, dp[n][i]);
  cout << ans << "\n";
  return 0;
}
/*
每次直接暴力？不，单调队列，md，我还是喜欢线段树一些
滑动窗口咋写的来着，看看。
*/