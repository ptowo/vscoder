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
const int N = 2e5, inf = 900000; 
int n, q, d[N];
int st[N], tp;
int sum[N][22], to[N][22];
signed main () {
  n = read(), q = read();
  FOR (i, 1, n) 
    d[i] = read(), sum[i][0] = read();
  FOR (i, 1, 20) sum[0][i] = inf;
  d[0] = inf;
  for (int i = n; i; i--) {
    while (tp && d[ st[tp] ] <= d[i]) tp--;
    to[i][0] = st[tp];  ++tp, st[tp] = i;
  }
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i <= n; i++) {
      to[i][j] = to[ to[i][j - 1] ][j - 1];
      sum[i][j] = sum[i][j - 1] + sum[ to[i][j - 1] ][j - 1];
    }
  }
  FOR (i, 1, q) {
    int r = read(), v = read();
    for (int j = 20; ~j; j--) 
      if (sum[r][j] < v) 
        v -= sum[r][j], r = to[r][j];
    cout << r << "\n";
  }
  return 0;
}
/*
考虑找到每个数后面第一个比他大的地方涅。
然后，倍增求捏。
*/