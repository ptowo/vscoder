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
const int N = 2e5 + 5, mod = 1e9 + 7;
int n, m, siz, bel, L[N], R[N], pos[N];
long long s[515], pre[515][515], suf[515][515], a[N];
long long ask1(int l,int r) {
  long long ans = 0;
  int pl = pos[l], pr = pos[r];
  if(pl == pr) {
    FOR(i, l, r) ans += a[i];  return ans;
  }  else {
    FOR(i, pl + 1, pr - 1) ans += s[i];
    FOR(i, l, R[pl]) ans += a[i];
    FOR(i, L[pr], r) ans += a[i];  return ans;
  }
}
long long ask2(int l,int r) {
  long long ans = ask1(l, r) % mod;
  for(int i = 1; i < siz; i++) {
    int Lb = (l - 1) / i + 1, Rb = (r - 1) / i + 1;
    if(Lb == Rb) {
      ans -= pre[i][(l - 1) % i];  ans += pre[i][(r - 1) % i + 1];
    }  else ans = ans + (Rb - Lb - 1) * pre[i][i] % mod + suf[i][(l - 1) % i + 1] + pre[i][(r - 1) % i + 1];
  }
  ans %= mod;  ans += mod; ans %= mod;
  return ans % mod;
}
signed main () {
  n = read(), m = read();
  siz = sqrt(n);
  FOR(i, 1, n) a[i] = read();
  FOR(i, 1, siz) {
    L[i] = (i - 1) * siz + 1, R[i] = wmin(i * siz, n);  R[siz] = n;
    FOR(j, L[i], R[i]) pos[j] = i, s[i] += a[j], s[i] %= mod;
  }
  FOR(i, 1, m) {
    int op = read(), x = read(), y = read();
    if(op == 1) {
      int z = read();
      if(x >= siz) {
        for(int j = y; j <= n; j += x) {
          a[j] += z;  s[pos[j]] += z;
        }
      }  else {
        for(int j = y; j <= x; j++) pre[x][j] = pre[x][j] + z;
        for(int j = y; j >= 1; j--) suf[x][j] = suf[x][j] + z;
      }
    }  else printf("%lld\n", ask2(x, y));
  } 
  return 0;
}
/*
修改操作时对一个数往后跳 +x,+2x...
查询操作仍然是查询区间。
唔，根号分治？
对于x>sqrtn的暴跳
对于x<sqrtn的存下询问，然后下来一起转移？
想想，对于一个x<sqrt(n)
我们可以知道从哪些地方是起点。
别离线，在线。
在线的话，考虑分块。
哦，我直接对每个块维护一下他被加多少次，然后对于边角块我本来就是在暴力
然后在对块打个标记，然后暴力的时候顺带改改，就完了？
就算我这个块被打了n个标记，但是我暴力根号，复杂度nsqrtn对的啊。
我擦，这种题我想了半小时？？
常熟大被卡了，滚去看题解了。
*/