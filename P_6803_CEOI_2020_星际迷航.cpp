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
#define Fedge(i, x) for (int i = first[x]; i; i = nex[i])
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
const int N = 5e6, mod = 1e9 + 7;
int n, d, num = 1, nex[N], first[N], v[N];
void add(int from,int to) {
  nex[++num] = first[from]; first[from] = num; v[num] = to;
}
void ins(int x,int y) {  add(x, y), add(y, x);  }
int tx, ty, cnt, dep[N];
int dp[N], s[N][2], r[N], s0[N], dp2[N], r2[N];
void dfs(int u,int fa) {
  Fedge (i, u) {
    int to = v[i];
    if (to == fa) continue;  dfs(to, u);
    s0[u] += !dp[to];
    s[u][ dp[to] ] += r[to];
  }
  dp[u] = (s0[u] > 0);
  if (s0[u] == 1) r[u] = s[u][0];
  else if (s0[u] == 0) r[u] = s[u][1] + 1;
}
void dfs2(int u,int fa) {
  if (!dp[u]) ++cnt;  r2[u] = r[u]; dp2[u] = dp[u];
  Fedge (i, u) {
    int to = v[i];
    if (to == fa) continue;
    int s0u = s0[u], dpu = dp[u], ru = r[u], su0 = s[u][0], su1 = s[u][1];
    int s0v = s0[to], dpv = dp[to], rv = r[to], sv0 = s[to][0], sv1 = s[to][1];
    s0[u] -= !dp[to];  dp[u] = (s0[u] > 0);  s[u][dp[to]] -= r[to];
    if (s0[u] == 1) r[u] = s[u][0];
    else if (s0[u] == 0) r[u] = s[u][1] + 1;
    else r[u] = 0;
    dp[to] |= !dp[u];  s0[to] += !dp[u];  s[to][dp[u]] += r[u];
    if (s0[to] == 1) r[to] = s[to][0];
    else if(s0[to] == 0) r[to] = s[to][1] + 1;
    else r[to] = 0;
    dfs2(to, u);
    s0[u] = s0u; dp[u] = dpu; r[u] = ru; s[u][0] = su0; s[u][1] = su1;
    s0[to] = s0v; dp[to] = dpv; r[to] = rv; s[to][0] = sv0; s[to][1] = sv1;
  }
}
int m = 3;
struct node {
  int a[5][5];
  void clear() {  memset(a, 0, sizeof(a));  }
  node operator * (node const &b) const {
    node res; res.clear();
    FOR (i, 0, m) {
      FOR (k, 0, m) {
        FOR (j, 0, m) {
          res.a[i][j] += a[i][k] * b.a[k][j] % mod;
          res.a[i][j] %= mod;
        }
      }
    }
    return res;
  }
  node operator + (node const &b) const {
    node res; res.clear();
    FOR (i, 0, m) {
      FOR (j, 0, m) {
        res.a[i][j] += a[i][j] + b.a[i][j];
        res.a[i][j] %= mod;
      }
    }
    return res;
  }
}a, b;
int tag[N];
node ksm (node x, int k) {
  node ans; ans.clear();
  FOR (i, 0, m) ans.a[i][i] = 1;
  while (k) {
    if (k & 1) ans = ans * x;
    x = x * x; k >>= 1;
  }
  return ans;
}
signed main () {
  n = read(), d = read();
  REP (i, 1, n) { int x = read(), y = read();  ins(x, y); }
  dfs(1, 0); dfs2(1, 0);
  if (d == 1) {
    if (dp2[1] == 1) {
      int ans = (n - r2[1]) * cnt % mod + (n - cnt) * n % mod;  ans %= mod;   cout << ans << "\n";
    }  else cout << r2[1] * cnt % mod;  return 0;
  }
  FOR (i, 1, n) {
    if (!dp2[i]) {
      b.a[0][0] += n - r2[i]; b.a[0][0] %= mod;
      b.a[1][0] += n; b.a[1][0] %= mod;
      b.a[0][1] += r2[i]; b.a[0][1] %= mod;
    }  else if (dp2[i] == 1) {
      b.a[0][0] += r2[i]; b.a[0][0] %= mod;
      b.a[0][1] += n - r2[i]; b.a[0][1] %= mod;
      b.a[1][1] += n; b.a[1][1] %= mod;
    }
  }
  a.a[0][0] = cnt, a.a[0][1] = n - cnt;
  b = ksm(b, d - 1);
  a = a * b;
  int f0 = a.a[0][0], f1 = a.a[0][1];
  if (dp[1]) {
    int ans = (n - r2[1]) * f0 % mod + f1 * n % mod;  ans %= mod;   cout << ans << "\n";
  }  else cout << r2[1] * f0 % mod;
  return 0;
}