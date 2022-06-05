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
const int N = 2e5;
int n, m, k, l, r;
struct node { int a[N]; } a, b;
node change(node a, node b) {
  node c;
  FOR (i, 1, n) c.a[i] = a.a[ b.a[i] ];

  return c;
}
void power(int qb) {
  while (qb) {
    if (qb & 1) b = change(b, a);
    a = change(a, a);
    qb /= 2;
  }
}
signed main () {
  n = read(), m = read(), k = read();
  FOR (i, 1, n) a.a[i] = b.a[i] = i;
  FOR (i, 1, m) {
    l = read(), r = read();
    reverse(a.a + l, a.a + r + 1);
  }
  power(k);
  FOR (i, 1, n) printf("%d\n", b.a[i]);
  return 0;
}