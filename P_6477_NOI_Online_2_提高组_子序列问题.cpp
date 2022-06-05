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
const int N = 2e6, mod = 1e9 + 7;
int n, a[N], c[N], c2[N], b[N], num, ans, pre[N];
vector <int> ver[N];
int lowbit(int x) { return x & (-x); }
void change(int x,int val) {
  for (int i = x; i <= n; i += lowbit(i)) 
    c[i] += val, c[i] %= mod, c2[i] += val * x % mod, c2[i] %= mod;
}
int ask(int x) {
  int ans = 0;
  for (int i = x; i; i -= lowbit(i)) 
    ans += c[i] * (x + 1) - c2[i], ans %= mod;
  return ans;
}
signed main () {
  n = read();
  FOR (i, 1, n) 
    a[i] = read(), b[i] = a[i];
  sort(b + 1, b + n + 1);
  num = unique(b + 1, b + n + 1) - (b + 1); 
  FOR (i, 1, n) 
    a[i] = lower_bound(b + 1, b + num + 1, a[i]) - b;
  FOR (i, 1, n) 
    ver[ a[i] ].emplace_back(i);
  FOR (i, 1, num) {
    for (int j = 1; j < ver[i].size(); j++) 
      pre[ ver[i][j] ] = ver[i][j - 1];
  }
  int now = 0;
  FOR (r, 1, n) {
    now += r - pre[r];
    now += (ask(r) - ask( pre[r]) ) * 2;
    change(pre[r] + 1, 1), change(r + 1, -1);
    ans += now; ans %= mod; now %= mod;
    ans += mod; now += mod; ans %= mod; now %= mod;
  }
  cout << ans << "\n";
  return 0;
}
/*
1 1 1

1
1
1 = 3

0 
1
2
3

*/