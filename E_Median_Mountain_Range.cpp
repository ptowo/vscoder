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
int n, a[N];
class Segment {

};
signed main () {
  n = read();  FOR(i, 1, n) {  a[i] = read();  }
  /*
  首先考虑一个 01 序列会怎么变化
  我们发现，对于 00 或者 11 这样的连续段是不会有变化的
  那么在 01 序列中等价于只有 01 或者 10 这种序列是会进行变化的
  但是如果是 001 那么是 0 -> 1 
  如果是 011 那么是 1 -> 1
  所以我们发现，真正会改变的还只会有 01 这种连续段
  那么考虑讲原序列转化为 01 序列，经典想法是二分一个数 x
  将 >= x 的设置为 1 ， < x 的设置为 0
  然后对于这个 01 序列的答案也就是最长的 01 序列连续段长度
  */
  return 0;
}