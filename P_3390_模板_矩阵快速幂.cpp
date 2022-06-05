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
template<class T>T min(const T &a, const T &b) {return a < b ? a : b;}
template<class T>T max(const T &a, const T &b) {return a > b ? a : b;}
template<class T>bool chkmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
template<class T>bool chkmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 105, mod = 1e9 + 7;
int n, k;
struct node {
  int a[N][N];
  void clear() {
    memset(a, 0, sizeof(a));
    FOR (i, 1, n) a[i][i] = 1;
  }
  void clear2() {
    memset(a, 0, sizeof(a));
  }
  node operator *  (const node &b) {
    node res;  res.clear2();
    FOR (i, 1, n) 
      FOR (k, 1, n)
        FOR (j, 1, n) 
          res.a[i][j] += a[i][k] * b.a[k][j] % mod, res.a[i][j] %= mod;    
    return res;
  }
}a, b;
node ksm2(node x, int k) {
  node ans;  ans.clear();
  while (k) {
    if (k & 1) ans = ans * x;
    k >>= 1;
    x = x * x;
  }
  return ans;
}
signed main () {
  n = read(), k = read();
  FOR (i, 1, n) {
    FOR (j, 1, n) a.a[i][j] = read();
  }
  node ans = ksm2(a, k);
  FOR (i, 1, n) {
    FOR (j, 1, n ) {
      printf("%lld ", ans.a[i][j]);
    }
    printf("\n");
  }
  return 0;
}