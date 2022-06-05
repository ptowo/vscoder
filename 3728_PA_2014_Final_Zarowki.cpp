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
const int N = 2e6;
int n, k, now, ans, j = 1, a[N], b[N];
priority_queue <int,vector<int>,greater<int> > q;
priority_queue <int> q2;
signed main () {
  n = read(), k = read();
  FOR (i, 1, n)
    a[i] = read();
  FOR (i, 1, n)
    b[i] = read();
  sort(a + 1, a + n + 1); sort(b + 1, b + n + 1);
  reverse(a + 1, a + n + 1); reverse(b + 1, b + n + 1);
  FOR (i, 1, n) {
    while (a[j] >= b[i]) 
      q.push(a[j++]);
    if (!q.empty()) 
      { ans += q.top(), q2.push( q.top() - b[i] ), q.pop(); continue; }
    k--; ans += b[i];
    if (k < 0) { printf("NIE"); return 0; }
  }
  while (k--) 
    ans -= q2.top(), q2.pop();
  printf("%lld\n", ans);
  return 0;
}