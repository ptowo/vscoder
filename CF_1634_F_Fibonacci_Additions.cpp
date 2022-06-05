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
const int N = 2e6;
int cnt, n, q, mod, a[N], b[N], c[N], d[N], fib[N];
void calc(int pos,int x) {
  x = (x % mod + mod) % mod;
  if (pos > n || !x) return;
  if (a[pos] == 0) cnt++;
  a[pos] = (a[pos] + x) % mod;
  if (a[pos] == 0) cnt--;
}
signed main () {
  n = read(), q = read(), mod = read();
  fib[0] = 0; fib[1] = 1;
  FOR (i, 2, n + 4) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
  FOR (i, 1, n) a[i] = read();
  FOR (i, 1, n) {
    int x = read();
    a[i] -= x;
  }
  DFR (i, n, 2) a[i] -= a[i - 1] + a[i - 2];
  FOR (i, 1, n) a[i] = (a[i] % mod + mod) % mod;
  FOR (i, 1, n) cnt += (a[i] != 0);
  FOR (i, 1, q) {
    char op; int l, r;
    scanf("%c", &op);  l = read(), r = read();
    int val = 0;
    if (op == 'A') val = 1;
    else if(op == 'B') val = -1;
    calc(l, val);  calc(r + 1, -val * fib[r - l + 2]);  calc(r + 2, -val * fib[r - l + 1]);
    if(cnt) puts("NO");
    else puts("YES");
  }
  return 0;
}