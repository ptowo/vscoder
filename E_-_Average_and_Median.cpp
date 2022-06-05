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
const int N = 2e6;
int n, a[N];
double dp[N][3], b[N];
bool check(double x,int t) {
  FOR(i, 1, n) {
    if(t == 1) b[i] = a[i] - x;
    else b[i] = (a[i] >= x ? 1 :-1.000001);
  }  dp[0][0] = dp[0][1] = 0;
  FOR(i, 1, n) {
    dp[i][0] = dp[i - 1][1];
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + b[i];
  }
  return max(dp[n][0], dp[n][1]) >= 0;
}
double solve(int t) {
  double r = 1e9, l = 0, eps = 0.00001;
  while(r - l > eps) {
    double mid = (l + r) / 2;
    if(check(mid, t)) l = mid;
    else r= mid;
  }
  return l;
}
signed main () {
  n = read();  FOR(i, 1, n) a[i] = read();
  printf("%.3lf\n%.0lf",solve(1),solve(2));
  return 0;
}