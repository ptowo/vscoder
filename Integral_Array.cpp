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
const int N = 4e6;]
int T, n, num, a[N], s[N], vis[N;
signed main () {
  T = read();  
  while(T--) {
    n = read(); int c = read(); 
    FOR(i, 1, c) vis[i] = 0;
    FOR(i, 1, n) a[i] = read();  sort(a + 1, a + n + 1);
    FOR(i, 1, n) vis[a[i]] = 1;
    num = unique(a + 1, a + n + 1) - (a + 1);
    if(!vis[1]) { printf("No\n"); continue; }
    FOR(i, 1, c) s[i] = 0;
    FOR(i, 1, num) s[a[i]]++;
    FOR(i, 1, c) s[i] += s[i - 1];
    int fl = 0;
    FOR(i, 1, num) {
      int val = a[i];
      if(val == 1) continue;
      for(int j = val * 2; j <= c + val; j += val) {
        int R = wmin(j - 1, c);
        int L = j - val - 1;
        int cnt = s[R] - s[L];
        int need = (j - 1) / val; 
        if(cnt && !vis[need]) { fl = 1; break;  }
      }
    }
    if(fl) printf("No\n");
    else printf("Yes\n");
  }
  return 0;
}