// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
#define int long long
using namespace std;
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
const int N = 6e5, mod = 998244353;
int t, n, num;
int nex[N], first[N], v[N], w[N], inv[N], mn[N], now[N], ans[N];
vector <int> f[N];
int power(int a,int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}
int w1[N], w2[N];
void add(int from,int to,int val1, int val2) {
  nex[++num] = first[from];  first[from] = num; v[num] = to;
  w1[num] = val1, w2[num] = val2;
}
void ins(int x,int y) {
  int k = x;
  for (auto t : f[x]) {
    while (k % t == 0) k /= t, now[t] += y;
    mn[t] = wmin(mn[t], now[t]);
  }
}
void dfs(int x, int fa) {
  for (int i = first[x]; i; i = nex[i]) {
    int to = v[i], xt = w1[i], yt = w2[i];
    if (to == fa) continue;
    ins(yt, 1);  ins(xt, -1); 
    ans[to] = ans[x] * yt % mod * inv[xt] % mod;
    dfs(to, x);  ins(xt , 1);  ins(yt, -1);
  }
}
signed main () {
  inv[1] = 1; FOR (i, 2, 2e5) inv[i] = power(i, mod - 2);
  FOR (i, 2, 2e5) {
    if ( !f[i].size() ) {
      for (int j = i; j <= 2e5; j += i) {
        f[j].push_back( i );
      }
    }
  }
  t = read();
  while (t--) {
    n = read();
    FOR (i, 1, n) mn[i] = now[i] = 0;
    REP (i, 1, n) {
      int u = read(), v = read(), x = read(), y = read();
      int z = __gcd(x, y);  x /= z, y /= z;
      add(u, v, x, y);  add(v, u, y, x);
    }
    ans[1] = 1;  dfs(1, 0);
    int p = 1, sum = 0;
    FOR (i, 1, n) while( mn[i] < 0 ) p *= i, ++mn[i], p %= mod;
    FOR (i, 1, n) ans[i] = ans[i] * p % mod;
    FOR (i, 1, n) sum += ans[i], sum %= mod;
    printf("%lld\n", sum);
    FOR (i, 1, num) nex[i] = first[i] = v[i] = w1[i] = w2[i] = 0;
    num = 0;
  }
  return 0;
}
/*
n-1条边构成一棵树
得到任意配料的一个解，其他配料都可以通过比例推出
随便取一点为根，先找到根的解

*/