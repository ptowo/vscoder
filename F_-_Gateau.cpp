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
const int N = 4e6;
int n, m, s[N], s2[N];
pair <int,int> calc(int sum) {
	int l = 0, r = sum;
  REP (i, 1, n) {
    chkmax(r, l + s[i]), chkmax(l, r - s2[i]); 
    assert(r - l <= s2[i]);  assert(r - l >= s[i]);
  }
  return {l, r};
}
bool chk(int x) {
  REP (i, 0, n) {  s2[i] = x - s[i + n];  if (s[i] > s2[i]) return false; }
  int l = s[0], r = s2[0] + 1, ans = 0;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (calc(mid).second <= x) ans = mid, l = mid;
    else r = mid;
  }
  pair <int,int> qwq = calc(l);
  return qwq.first <= l && qwq.second <= x;
}
signed main () {
  n = read(); m = 2 * n;
  REP (i, 0, m) s[i] = read();
  int l = -1, r = 1e9;
  int ans = 0;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (chk(mid)) { ans = mid; r = mid; }  else l = mid;
  }  
  cout << r << "\n";
  return 0;
}
