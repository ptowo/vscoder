// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
namespace io {
  const int SIZE = (1 << 21) + 1;
  char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
  #define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
  inline void flush () {  fwrite (obuf, 1, oS - obuf, stdout); oS = obuf; }
  inline void putc (char x) { *oS ++ = x; if (oS == oT) flush (); }
  inline int gi () {
    int x = 0;
    for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
    for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f; return x;
  }
  string getstr(void) {
    string s = ""; char c = gc();
    while (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF) c = gc();
    while (!(c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF))s.push_back(c), c = gc();
    return s;
  }
  template <class I>
  inline void print (I x) {
    if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
    while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
    while (qr) putc (qu[qr --]);
  }
  struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
const int N = 3e5;
int n, m, _x0, h[N], s[N], x[N], toa[N][22], tob[N][22];
set < pair<int,int> > s1;
pair <int, pair<int,int> > pt[7];
signed main () {
  n = gi();
  for (int i = 1; i <= n; i++)
    h[i] = gi();
  for (int i = 1; i <= n; i++) {
    if (s1.size() == 1) {
      tob[i][0] = 1, toa[i][0] = 0;
    }  else if (s1.size() > 1) {
      int num = 0;
      s1.insert( {h[i], i} );
      auto it = s1.find( {h[i], i} );
      auto it2 = it; 
      it2++;
      if (it2 != s1.end()) {
        ++num; pt[num] = { abs( (*it).first - (*it2).first ) , {(*it2).first, (*it2).second} };
        it2++;
        if (it2 != s1.end()) {
          ++num; pt[num] = { abs( (*it).first - (*it2).first ) , {(*it2).first, (*it2).second} };
        }
      }
      it2 = it;
      if (it2 != s1.begin()) {
        it2--;
        ++num; pt[num] = { abs( (*it).first - (*it2).first ) , {(*it2).first, (*it2).second} };
        if (it2 != s1.begin()) {
          it2--;
          ++num; pt[num] = { abs( (*it).first - (*it2).first ) , {(*it2).first, (*it2).second} };
        }
      }
      sort(pt + 1, pt + num + 1);
      tob[i][0] = pt[1].second.second;
      toa[i][0] = pt[2].second.second;
      s1.erase(it);
    }
    s1.insert( {h[i], i} );
  }
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i <= n; i++) {
      toa[i][j] = toa[ toa[i][j - 1] ][j - 1];
      tob[i][j] = tob[ tob[i][j - 1] ][j - 1];
    }
  }
  _x0 = gi(), m = gi();
  for (int i = 1; i <= m; i++)
    s[i] = gi(), x[i] = gi();
  cout << "qwq\n";
  return 0;
}
/*
一直向东行驶 <-
A 会驾驶到下一个距离自己第二近的城市
B 会驾驶到距离自己最近的城市
就，感觉很奇怪的感觉的说 >_<
我咋感觉这东西 bf 模拟巨大多分（
貌似有 70 的模拟
直接预处理出 A 在 i， B 在 i 时会走到哪个点去，然后暴力模拟，70 分。
复杂度 nm /yiw
然后咋做，不会了。
嘻嘻，我又要看题解了😅😅
傻了啊，就差一步😭😭果然我是🤡
考虑建图，然后倍增，然后比较 easy 
用 set 寻找在第 i 个点的时候，A，B 会走到哪里去
首先 1 节点会 g，首先 2 节点会 g，然后 3 节点无论如何都不会 g
好难写啊，我日，鬼写这个东西，给我 2h 写差不多
哦，建图建完了，然后对于接下来就是倍增求解的过程了
大概之后咋做不会，拜拜拜，润润润，寄寄寄
*/