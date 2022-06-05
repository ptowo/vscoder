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
const int N = 3e5;
int t, n, a[N];
vector<int> b;
deque<int> pos[N];
signed main() {
  t = read();
  while (t--) {
    n = read();
    b.clear();
    FOR (i, 1, n) pos[i].clear();
    FOR(i, 1, n) a[i] = read(), pos[a[i]].push_back(i);
    int now = 0;
    while (now < n) {
      int t = now;
      FOR (i, 0, n) { 
        if (pos[i].empty()) { b.emplace_back(i); break; }
        chkmax(now, pos[i][0]);
      }
      chkmax(now, t + 1);
      FOR (i, 0, n) {
        if (pos[i].empty()) break;
        while (!pos[i].empty() && pos[i][0] <= now) pos[i].pop_front();
      }
    }
    printf("%d\n", b.size());
    FORP (to, b)
      printf("%d ", to); printf("\n");
  }
  return 0;
}
/*
考虑当前的 mex 值为 x
如果后面仍然有一个值为 x ，那么我将其并入进去会得到更优的答案
那么模拟整个过程，直到后面 mex 值不能增加即可？
贪心的每次选一段前缀 mex 与当前 mex 相同
*/