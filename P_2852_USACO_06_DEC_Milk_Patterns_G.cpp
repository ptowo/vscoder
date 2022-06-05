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
int n, num = 200, f1[N], f2[N], sa[N], tong[N], height[N], ch[N];
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
}
void Getheight() {
  int k = 0;  FOR(i, 1, n) {
    if(k) k--;  int j = sa[f1[i] - 1];
    while (ch[i + k] == ch[j + k]) k++;  height[ f1[i] ] = k;
  }
} 
int k;
bool check(int now) {
  int cnt = 0, fl = 0;
  FOR(i, 2, n) {
    if(height[i] >= now) {
      cnt++;
      if(cnt >= k - 1) return 1;
    }  else cnt = 0;
  }
  return 0;
}
int qwq[N], tot;
signed main () {
  n = read();  k = read();  FOR(i, 1, n) ch[i] = read();  
  FOR(i, 1, n) qwq[i] = ch[i];
  sort(qwq + 1, qwq + n + 1);  tot = unique(qwq + 1, qwq + n + 1) - (qwq + 1);
  FOR(i, 1, n) ch[i] = lower_bound(qwq + 1, qwq + tot + 1, ch[i]) - qwq;
  num = tot;
  SA();  Getheight();
  int l = 1, r = n, ans = 0;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if( check(mid) ) {
      ans = mid;
      l = mid + 1;
    }  else r = mid - 1;
  }
  cout << ans << "\n";
  return 0;
}