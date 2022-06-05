// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, l, r) for(int i = (l); i <= r; ++i)
#define REP(i, l, r) for(int i = (l); i <  r; ++i)
#define DFR(i, l, r) for(int i = (l); i >= r; --i)
#define DRP(i, l, r) for(int i = (l); i >  r; --i)
#define FORV(i, ver) for(int i = 0; i < ver.size(); i++)
#define FORP(i, ver) for(auto i : ver)
template<class T>T wmin(const T &a, const T &b) {return a < b ? a : b;}
template<class T>T wmax(const T &a, const T &b) {return a > b ? a : b;}
template<class T>bool chkmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
template<class T>bool chkmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return ;
}
const int N = 4005;
int n, q, dp[N][N], pre[N], nxt[N];
char s[N];
int st[N], tp;
signed main () {
  n = read(), q = read();  scanf("%s", s + 1);
  FOR (i, 1, n) pre[i] = 0, nxt[i] = n + 1;
  FOR (i, 1, n) {
    if (s[i] == '(') st[++tp] = i;
    else if (tp) {  pre[i] = st[tp];  nxt[ st[tp] ] = i; tp--;  }
  }
  FOR (len, 1, n) {
    FOR (l, 1, n) {
      if (l + len - 1 > n) break;  int r = l + len - 1; dp[l][r] = 1;
      if (l <= pre[r] - 1) dp[l][r] += dp[l][pre[r] - 1];
      if (r >= nxt[l] + 1) dp[l][r] += dp[nxt[l] + 1][r];
      if (pre[r] - 1 >= nxt[l] + 1) dp[l][r] -= dp[nxt[l] + 1][pre[r] - 1];
      if ( s[l] == '(' && s[r] == ')' )  dp[l][r] += dp[l + 1][r - 1];
    }
  }
  FOR (i, 1, q) {  int x = read(), y = read();  write(dp[x][y]), putchar('\n');  }
  return 0;
}