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
const int N = 2e6;
struct node {
  int val, tag;
} s[N];
inline int ls(int p) { return p << 1; }
inline int rs(int p) { return p << 1 | 1; }
void pushdown(int p,int l,int r) {

}
void update(int p,int l,int r,int pos,int val) {

}
signed main () {
  
  return 0;
}
/*
区间加区间查询
ok，分块，暴力完了
不一定能过，而且细节多，润，并且分块现在不需要练了
想想树形数据结构解法
考虑区间加很简单，然后对于查询区间最长单峰
这种情况，我们猜测他是，线段树推标记
ok，例题有了
维护什么呢
12321
诸如此类的话，划分区间考虑维护标记的数量
首先维护val标记，然后维护区间最大值标记
然后维护懒惰标记实现区间加，然后考虑维护答案
一个区间的上升下降，
维护区间靠右的上升 l2，靠右的下降 r2
维护区间靠左的上升 l1，靠左的下降 r1
维护区间最左边值 lval,维护区间最右边值 rval
维护答案，区间内最长的上升下降长度 mx
ls , rs -> p
p [l,r] <- ls_l2 + rs_l1
p [l,r] <- ls_mx
p [l,r] <- rs_mx
p [l,r] -> p_mx
考虑更新标记 l2, l1, r1, r2
l2 <- (rs_l1 + ls_l2) when (rs_lval > ls_rval)
r2 <- (rs_r1 + rs_r2) when (rs_lval < ls_rval)
l1 <- () 
大概这么更新，随便划一下
不对，好像不是很理解的样子，，先跳了
*/