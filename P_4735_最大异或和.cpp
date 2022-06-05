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
const int N = 2e6;
int n, m, cnt, tot, cnt[N], a[N], rt[N], tr[N][2];
int s[N];
void insert(int a,int b,int t,int x) {
  if (t < 0) return;
  int y = (x >> t) & 1;
  tr[a][!y] = tr[b][!y];  tr[a][y] = ++tot;
  cnt[ tr[a][y] ] = cnt[ tr[b][y] ] + 1;
  insert(tr[a][y], tr[b][y], t - 1, x);
}
int ask(int a,int b,int t,int x) {
  if (t < 0) return 0;
  int y = (x >> t) & 1;
  if (cnt[ tr[b][!y] ] > cnt[ tr[a][!y] ]) 
    return (1 << t) + ask(tr[a][!y], tr[b][!y], t - 1, x);
  else return ask(tr[a][y], tr[b][y], t - 1, x);
}
signed main () {
  n = read(), m = read();
  rt[0] = ++tot;
  insert(rt[0], 0, 25, 0);
  FOR (i, 1, n) {
    int x = read(); s[i] = s[i - 1] ^ x;
    rt[i] = ++tot; insert(rt[i], rt[i - 1], 25, s[i]);
  }
  FOR (i, 1, m) {
    char op;  int l, r, x;
    scanf("%c", &op);
    if (op == 'A') {
      x = read();
      rt[++n] = x;
      s[n] = s[n - 1] ^ x;
      insert(rt[n], rt[n - 1], 25, s[n]);
    }  else {
      l = read(), r = read(), x = read();
      
    }
  }

  return 0;
}