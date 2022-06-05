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
const int N = 110;
int n, m, q, a[N];
struct node {
  int x, y, b[N][N];
  node() { memset(b, 0, sizeof(b)); x = 0, y = 0;}
  node operator * (const node &B) const {
    node ret;
    ret.x = x, ret.y = B.y;
    FOR (i, 1, x) 
      FOR (j, 1, B.y) 
        FOR (k, 1, y)
          ret.b[i][j] ^= b[i][k] * B.b[k][j];  
    return ret;
  }
} g[40], f;
signed main () {
  n = read(), m = read(), q = read();
  FOR (i, 1, n) 
    a[i] = read();
  g[0].x = g[0].y = n;
  FOR (i, 1, m) {
    int u = read(), v = read();
    g[0].b[u][v] = g[0].b[v][u] = 1;
  } 
  for (int i = 1; i < 32; i++) 
    g[i] = g[i - 1] * g[i - 1];
  FOR (i, 1, q) {
    int x = read();
    f.x = 1, f.y = n;
    memcpy(f.b[1] + 1, a + 1, sizeof(a));
    for (int w = 1, i = 0; w <= x; w <<= 1, ++i) 
      if (x & w) f = f * g[i];
    printf("%lld\n", f.b[1][1]);
  }
  return 0;
}