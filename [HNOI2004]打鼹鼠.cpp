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
const int N = 2e4;
int n, m, dp[N], a[2000][2000];
struct node { int tim, x, y; } f[N];
int calc(node x, node y) {
  int ans = abs(x.x - y.x) + abs(x.y - y.y);
  return ans;  
}
signed main () {
  n = read(), m = read();
  FOR (i, 1, n) {
    f[i].tim = read(), f[i].x = read(), f[i].y = read();
    a[ f[i].x ][ f[i].y ] = f[i].tim;
  }
  FOR (i, 1, m) {
    FOR (j, 1, m) {
      
    }
  }
  return 0;
}
/*
dp[i][j] 表示当前是第 i 个点，上一个是第 j 个点
*/