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
int n, a[N];
signed main () {
  n = read();
  FOR (i, 1, n)
    a[i] = read();
  
  return 0;
}
/*
又要自己思考了。
2n 个位置，知道是左右脚。
要求奇数偶数为左右脚且大小相同，求最小调换次数。
不会。19：30 去看题解。
首先，对于奇数位置，必须全部为 -，偶数为 +。
遍历所有奇数位置，对于偶数位置，如果是一个负数，存下来，和奇数上的偶数交换，问题在于交换怎么交换。
ojbk，还是不会，滚去看题解，不会贪心，倒是会部分分 dp。
哦，看到题解了。foreverlasting 哥哥就是牛逼。
哥哥牛逼，但是我还是没懂，我就是傻逼。
*/