// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, l, r) for (int i = (l); i <= r; ++i)
#define REP(i, l, r) for (int i = (l); i < r; ++i)
#define DFR(i, l, r) for (int i = (l); i >= r; --i)
#define DRP(i, l, r) for (int i = (l); i > r; --i)
#define FORV(i, ver) for (int i = 0; i < ver.size(); i++)
#define FORP(i, ver) for (auto i : ver)
template <class T>
T wmin(const T& a, const T& b) {
  return a < b ? a : b;
}
template <class T>
T wmax(const T& a, const T& b) {
  return a > b ? a : b;
}
template <class T>
bool chkmin(T& a, const T& b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
bool chkmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int mod = 1e9 + 7, N = 2000;
int n, m, k;
char a[N], b[N];
int f[2][201][201], s[2][201][201];
signed main() {
  n = read(), m = read(), k = read();
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  int now = 1, past = 0;
  f[0][0][0] = 1;
  for (int e = 1; e <= n; e++) {
    f[now][0][0] = 1;
    for (int j = 1; j <= m; j++) {
      for (int t = 1; t <= k; t++) {
        if (a[e] == b[j])
          s[now][j][t] = (s[past][j - 1][t] + f[past][j - 1][t - 1]) % mod;
        else
          s[now][j][t] = 0;
        f[now][j][t] = (f[past][j][t] + s[now][j][t]) % mod;
      }
    }
    swap(now, past);
  }
  cout << f[past][m][k];
  return 0;
}
/*
dp[k][i][j] 表示使用了 k 段，匹配到了 [1..i] 和 [1..j]
dp[k][i][j] = dp[k][i - 1][j - 1]
 + (a[i] == b[j]) sum[k - 1][i - 1 ~ 1][j - 1]
*/