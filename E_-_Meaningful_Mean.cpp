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
int n, k, a[N], s[N], c[N], b[N], t[N], num, Ans;
int lowbit(int x) { 
  return x & (-x); 
}
void change(int x,int val) {
  for (int i = x; i <= N; i += lowbit(i))
    c[i] += val;
}
int ask(int x) {
  int ans = 0;
  for (int i = x; i; i -= lowbit(i))
    ans += c[i];
  return ans;
}
signed main () {
  n = read(), k = read();
  FOR (i, 1, n)
    a[i] = read(), s[i] = s[i - 1] + a[i];
  FOR (i, 1, n) 
    b[++num] = s[i] - i * k;
  b[++num] = 0;
  sort(b + 1, b + num + 1);
  num = unique(b + 1, b + num + 1) - (b + 1);
  change( lower_bound(b + 1, b + num + 1, 0) - b, 1);
  FOR (i, 1, n) {
    t[i] = s[i] - i * k;
    t[i] = lower_bound(b + 1, b + num + 1, t[i]) - b;
    Ans += ask(t[i]); 
    change(t[i], 1);
  }
  printf("%lld\n", Ans);
  return 0;
}
/*
求有多少个区间的平均值大于等于 k
转化一下，考虑枚举长度
问题转化为对于长度 l，有多少个区间的和大于等于 l*k
暴力怎么做，枚举长度 l，枚举左端点 L，每次统计 [l,L+l] 区间内值是否大于等于 l*k
复杂度 n^2logn，肯定不行啊。
额，首先，有这样区间的合法条件是，原序列中存在大于等于 k 的数
考虑，以他往外扩张，如果不能往外扩张了。
考虑改变思路，题目转化为，每次加入一个数求区间平均值大于等于 k 的方案数
这个咋做，新增加的区间为 [1..k],[2..k],[3..k]..[k-1..k],[k,k] 一共 k 个
如果一个区间 [t-1,k-1] 是合法区间，那么他加入 k 之后有可能不是
然后歪了，md
转化形式为 sum{r}-sum{l-1} >= (r-l+1) *k
sum{r}-sum{l-1}>=rk-lk+k
sum{r}-rk>=sum{l-1}-lk+l
sum{r}-rk>=sum{l-1}-(l-1)k
二维数点即可
*/