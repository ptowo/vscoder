// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
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
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return ;
}
const int N = 1e7 + 6;
const unsigned long long M = 12345678901;
int n, k, m, sum, a[N], fa[N], b[N];
unsigned long long fac[N];
int getfa(int x) {  if (fa[x] != x) fa[x] = getfa(fa[x]);  return fa[x]; }
void merge(int x,int y) {
  int A = getfa(x), B = getfa(y);
  if (A == B) return;  fa[A] = B;
}
int getdis(int l,int r) {  if (r >= l) return r - l;  return n - l + r;   }
signed main () {
  n = read(), k = read();
  FOR (i, 1, n) a[i] = read(), sum += a[i];
  fac[0] = 1;  FOR (i, 1, n) fac[i] = fac[i - 1] * M;  m = wmin(n, k);
  FOR (i, 1, n) fa[i] = i; fa[0] = n;
  int las = -1, s = 0, s2 = 0;
  FOR (i, 1, n) {
    if (a[i] == 1) merge(i, i - 1);
    if (a[i] > 1) las = i;
    if (!a[i]) s++;
    if (a[i] > 1) s2++;
  }
  for (int i = las; s && s2; i = getfa(i - 1) ) {
    if (a[i] > 1) {las = i; continue; }
    if (a[las] <= 1 || getdis(i, las) > k) continue;
    a[las]--, a[i]++; s--;
    merge(i, i - 1);
    if (a[las] <= 1) s2--, merge(las, las - 1);
  }
  FOR (i, 1, n) b[i] = wmin(a[ (i - 1 + n - k % n) % n  + 1], 1) + wmax(0, a[i] - 1);
  unsigned long long ans = 0;
  FOR (i, 1, n) ans += (unsigned long long)(b[i] + 1) * fac[i];
  cout << ans;
  return 0;
}