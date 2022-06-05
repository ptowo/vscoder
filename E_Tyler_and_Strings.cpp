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
const int N = 2e6, mod = 998244353;
int n, m, s[N], t[N], fac[N], ifac[N], cnt[N];
int power(int a,int b) {
  int ans = 1;  while(b) {
    if(b & 1) ans = ans * a % mod;
    b >>= 1;  a = a * a % mod;
  }
  return ans;
}
class BIT {
  public: int c[N];
  private: int lowbit(int x) {  return x & (-x);  }
  public: void update(int x,int v) {
    for(int i = x; i <= 2e5; i += lowbit(i)) c[i] += v; 
  }
  public: int ask(int x) {
    int ans = 0;
    for(int i = x; i; i -= lowbit(i)) ans += c[i];
    return ans;
  }
};
BIT qwq, b;
signed main () {
  n = read(), m = read();  
  FOR(i, 1, n) s[i] = read();
  FOR(i, 1, m) t[i] = read();
  fac[0] = 1; 
  FOR(i, 1, 2e5) fac[i] = fac[i - 1] * i % mod;  ifac[200000] = power(fac[200000], mod - 2);
  DFR(i, 2e5, 1) ifac[i - 1] = ifac[i] * i % mod;
  FOR(i, 1, n) qwq.update(s[i], 1), cnt[s[i]]++;
  int now = 1 , ans = 0;  FOR(i, 1, 2e5) now = now * ifac[cnt[i]] % mod;
  int ex = 1;
  FOR(i, 1, min(n, m)) {
    ans += fac[n - i] * qwq.ask(t[i] - 1) % mod * now % mod;  ans %= mod;
    if(cnt[ t[i] ] == 0) {
      ex = 0;  break;
    }
    now = now * cnt[ t[i] ] % mod;  cnt[t[i]] --;
    qwq.update(t[i], -1);
  }
  if(n >= m) ex = 0;
  cout << (ans + ex) % mod << "\n";
  return 0;
}