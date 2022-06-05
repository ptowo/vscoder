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
const int N = 2e6;
int n, m, a[N], b[N], c[N];
signed main () {
  n = read(), m = read();
  int tot = 0;
  FOR (i, 1, n) 
    a[++tot] = read(); a[++tot] = m, n = tot;
  int ans = 0, las = 0, op = 1;
  FOR (i, 1, n) {
    if (op) b[i] = (a[i] - a[i - 1]);
    else c[i] = (a[i] - a[i - 1]);
    op ^= 1;
  }
  FOR (i, 1, n) b[i] += b[i - 1];
  FOR (i, 1, n) c[i] += c[i - 1];
  ans = b[n];
  int cur = c[n];
  FOR (i, 1, n) {
    if (i % 2 == 1) {
      cur += a[i] - a[i - 1];
      ans = max(ans, cur - 1);
    }  else {
      cur -= (a[i] - a[i - 1]);
      ans = max(ans, cur + a[i] - a[i - 1] - 1);
    }
  }
  cout << ans << "\n";
  return 0;
}

/*
考虑插入一个数，要么是插左边要么是插右边的数
先前面依次插着走
然后每次插入一个数后面会有影响
md，hzx 是sb吗？？

*/