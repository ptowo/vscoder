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
const int N = 2e6, mod = 1e9 + 7;
int n, m, num, c[N], a[N], b[N], bx[N], by[N], len1, len2;
pair <int,int> d[N];
int lowbit (int x) { return x & (-x); }
void change(int x,int val) {
  for (int i = x; i <= len1 + len2; i += lowbit(i)) c[i] += val, c[i] %= mod;
}
int ask(int x) {
  int ans = 0;
  for (int i = x; i; i -= lowbit(i)) ans += c[i], ans %= mod;
  return ans;
}
int cmp(pair <int,int> x,pair <int,int> y) {
  return (x.first ^ y.first) ? x.first < y.first : x.second > y.second;
}
signed main () {
  n = read(), m = read();
  FOR (i, 1, n) a[i] = read();
  FOR (i, 1, m) b[i] = read();
  sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
  FOR (i, 1, n) {
    int pos = upper_bound(b + 1, b + m + 1, a[i]) - b;
    if (pos - 1 >= 1 && pos <= m) {
      bx[++len1] = a[i] - b[pos - 1];  by[++len2] = b[pos] - a[i];
      d[++num] = make_pair(a[i] - b[pos - 1], b[pos] - a[i]);
    }
  }
  sort(bx + 1, bx + len1 + 1);  sort(by + 1, by + len2 + 1);
  len1 = unique(bx + 1, bx + len1 + 1) - (bx + 1);
  len2 = unique(by + 1, by + len2 + 1) - (by + 1);
  FOR (i, 1, num) {
    d[i].first = lower_bound(bx + 1, bx + len1 + 1, d[i].first) - bx;
    d[i].second = lower_bound(by + 1, by + len2 + 1, d[i].second) - by;
  }
  sort(d + 1, d + num + 1, cmp);  num = unique(d + 1, d + num + 1) - (d + 1);  
  int ans = 1;
  FOR (i, 1, num) {
    int now = ask(d[i].second) + 1;
    change(d[i].second + 1, now);  ans += now; ans %= mod;
  }
  write(ans), putchar('\n');  
  return 0;
}