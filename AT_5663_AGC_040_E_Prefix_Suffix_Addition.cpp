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
int ans, n, a[N], tmp[2], tmp2[3], pos[2];
signed main () {
  n = read();
  FOR (i, 1, n) a[i] = read();
  FOR (i, 1, n + 1) {
    tmp2[0] = tmp2[1] = 1e9;
    tmp[0] = 0;  tmp[1] = a[i] - a[i - 1];
    if (tmp[0] < tmp[1]) swap(tmp[0], tmp[1]);
    FOR (j, 0, 1) 
      FOR (k, 0, 1) 
        chkmin(tmp2[j + k], wmax(tmp[j] + pos[k], 0));
    if (tmp2[0] > a[i]) ans ++, pos[0] = tmp2[1], pos[1] = 0;
    else pos[0] = tmp2[0], pos[1] = tmp2[1];
  }
  cout << ans << "\n";
  return 0;
}