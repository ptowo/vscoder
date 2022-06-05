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
const int N = 2e6;
int n, m, tot, p[N], a[N], tong[N];
class BST {
  public: int c[N];
  public: int lowbit(int x) {
    return x & (-x);
  }
  public: void change(int x,int val) {
    for (int i = x; i <= N; i += lowbit(i)) 
      c[i] += val;
  }
  public: int ask(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
      ans += c[i];
    return ans;
  }
  public: void clear() {
    FOR (i, 1, n)
      c[i] = 0; return;
  }
}t, t2;
signed main () {
  n = read(), m = read();
  REP (i, 0, n)
    p[i] = read();
  //ai 表示之前的小于他的数，统计比他小的数
  REP (i, 0, n) 
    a[i] = i - t.ask(p[i]), tot += a[i], tong[ a[i] ]++, t.change(p[i], 1);
  t.clear(), t2.change(1, tot), tot = 0;
  REP (i, 0, n) {
    tot += tong[i];
    t2.change(i + 2, -(n - tot) );
  }
  REP (i, 0, m) {
    int op = read(), k = read();
    k = min(k, n - 1);
    //cout << "id : " << i << " " << k << " " << "qwq\n";
    if (op == 1) {
      k--;
      if (p[k] < p[k + 1]) {
        swap(p[k], p[k + 1]); swap(a[k], a[k + 1]);
        t2.change(1, 1), t2.change(a[k + 1] + 2, -1);
        a[k + 1]++;
      }  else {
        swap(p[k], p[k + 1]); swap(a[k], a[k + 1]);
        t2.change(1, -1), a[k]--, t2.change(a[k] + 2, 1);
      }
    }  else {
      printf("%lld\n", t2.ask(k + 1));
    }
  }
  return 0;
}
/*
分析操作，每一轮对于前 n-1 个位置查询是否当前位置大于后面位置，是则交换。
假设原先 i 之前比 ai 大的数为 ci
冒泡排序一次之后，ci->max(c_{i}-1,0）
树状数组维护
*/