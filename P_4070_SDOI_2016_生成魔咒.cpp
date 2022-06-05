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
const int N = 3e6;
int n, num = 200, f1[N], f2[N], sa[N], tong[N], height[N], ch[N], rk[N];
void SA() {
  FOR(i, 1, num) tong[i] = 0;  FOR(i, 1, n) ++tong[ f1[i] = ch[i] ];
  FOR(i, 1, num) tong[i] += tong[i - 1];  DFR(i, n, 1)  sa[ tong[f1[i]]-- ] = i;
  for(int l = 1; l <= n; l <<= 1) {  int cnt = 0;
    FOR(i, n - l + 1, n) f2[++cnt] = i;  FOR(i, 1, n) if(sa[i] > l) f2[++cnt] = sa[i] - l;
    FOR(i, 1, num) tong[i] = 0;  FOR(i, 1, n) ++tong[f1[i]];  FOR(i, 1, num) tong[i] += tong[i - 1];
    DFR(i, n, 1) sa[ tong[ f1[ f2[i] ] ] -- ] = f2[i], f2[i] = 0;  swap(f1, f2);
    f1[ sa[1] ] = 1;  cnt = 1;
    FOR(i, 2, n) f1[ sa[i] ] = ( f2[ sa[i] ] == f2[ sa[i - 1] ] && f2[ sa[i] + l ]  == f2[ sa[i - 1] + l] ) ? cnt : ++cnt;
    if(cnt == n) break;  num = cnt;
  }
  FOR(i, 1, n) rk[i] = f1[i];
}
void Getheight() {
  int k = 0;  FOR(i, 1, n) {
    if(k) k--;  int j = sa[f1[i] - 1];
    while (ch[i + k] == ch[j + k]) k++;  height[ f1[i] ] = k;
  }
}
int f[N][20], lg[N];
void buildst(int *a,int n) {
  FOR (i, 1, n) f[i][0] = a[i];
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      f[i][j] = wmin(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int query(int l,int r) {  int k = lg[r - l + 1];  
  return wmin(f[l][k], f[r - (1 << k) + 1][k]);
}
set <int> s;
int bhc[N], clz;
signed main () {
  n = read();
  REP (i, 2, N) lg[i] = lg[i >> 1] + 1;
  FOR (i, 1, n) ch[i] = read();  reverse(ch + 1, ch + n + 1);  
  FOR (i, 1, n) bhc[i] = ch[i];
  sort(bhc + 1, bhc + n + 1);
  clz = unique(bhc + 1, bhc + n + 1) - (bhc + 1);
  FOR (i, 1, n) ch[i] = lower_bound(bhc + 1, bhc + clz + 1, ch[i]) - bhc;
  num = n;
  SA();  Getheight();
  buildst(height, n);
  int ans = 0;
  DFR (i, n, 1) {
    s.insert( rk[i] );
    auto it = s.find( rk[i] );    
    int k = 0;
    if (it != s.begin()) {
      int p = *(--it);
      k = query(p + 1, rk[i]);  ++it;
    }
    ++it;
    if (it != s.end()) {
      int p = *it;
      k = wmax(k, query(rk[i] + 1, p));
    }
    ans += n + 1 - i - k;
    printf("%lld\n", ans);
  }
  return 0;
}

/*
8 9 4 6 2 3 5 10 7 1 
1
3
6
9
13
17
24
31
39
48
*/