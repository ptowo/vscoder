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
const int N = 1e6, mod = 198999;
int d, offset, n, m, a[27][27];
int las, now, cnt[2]; //las,now滚动 cnt[2] 滚动的总合法方案数
int v[N][2], dp[N][2], nex[N], first[N], Endx, Endy;
int ans;
//0 1 2 没有插头 左括号 右括号
struct node2 { int s[27]; };
node2 unzip(int sta) { 
  node2 code; code.s[0] = sta & 3;
  FOR (i, 1, m) code.s[i] = (sta >> (i << 1) ) & 3;
  return code;
}
int zip(node2 code) {
  int sta = 0;
  FOR (i, 1, m) sta |= (code.s[i] << (i << 1) );  
  sta |= code.s[0];
  return sta;
}
void insert(int sta,int val) {
  int key = sta % mod;
  for (int i = first[key]; i; i = nex[i]) 
    if (sta == v[i][now]) { dp[i][now] += val; return; }
  ++cnt[now];
  v[ cnt[now] ][now] = sta, dp[ cnt[now] ][now] = val;
  nex[ cnt[now] ] = first[key], first[key] = cnt[now];
}
char ch[20];
signed main () {
  cin >> n >> m;
  FOR (i, 1, n) {
    cin >> (ch + 1);
    FOR (j, 1, m) 
      if (ch[j] == '.') a[i][j] = 1, Endx = i, Endy = j; 
  }
  insert(0, 1);
  FOR (i, 1, n) {
    FOR (j, 1, m) {
      las = now, now ^= 1; cnt[now] = 0;
      memset(first, 0, sizeof(first));
      for (int k = 1; k <= cnt[las]; k++) {
        node2 code = unzip(v[k][las]);
        int Left = code.s[0], Up = code.s[j]; // 左插头，上插头
        int DP = dp[k][las];
        if (!a[i][j]) { //当前为障碍节点
          if (!Left && !Up) insert( zip(code), DP );
          // 如果左插头和上插头都不到这里来，那就可以延续
        }
        else if (!Left && !Up) {
          if (a[i + 1][j] && a[i][j + 1]) 
            code.s[0] = 2, code.s[j] = 1, insert( zip(code), DP);
          // 如果当前要铺线，并且下边和右边都可以铺线
          // 那么我就需要向下铺一条，向右铺一条
          // 因此插头方向可以确定出来，所以向下的为 ( 向右的为 )
          // 对应起来，原本 sj 为 ( ,s0 为 )
          // 原先啥都没有，往下铺一条，往右铺一条，右边为 2,下边为 1 于是 s0 = 2, sj = 1
          // u + mi[j - 1] + (mi[j] << 1)
        }
        else if (!Left && Up) {
          /*
          如果当前要铺线，并且左边没有铺线，但是上边有铺线
          那么有两种铺线方式，一种是向下，一种是向右
          向下，可以直接什么都不变
          向右，如果原先上面是什么括号，则是一个 swap 的过程
          */
          if (a[i + 1][j]) insert( zip(code), DP);
          if (a[i][j + 1]) 
            code.s[0] = Up, code.s[j] = 0, insert( zip(code), DP);
          //u + q * mi[j - 1] - q * mi[j]
        }
        else if (Left && !Up) {
          if (a[i][j + 1]) insert(zip(code), DP);
          if (a[i + 1][j]) 
            code.s[0] = 0, code.s[j] = Left, insert( zip(code), DP);
          /*
          如果左边有插头，上边没有，那么可以向下扑，可以向右铺
          最终的效果就是，首先依次判断连通性
          然后如果是要向下铺，那么就好了
          如果向右铺，那么不变
          */
          // u + p * mi[j] - p * mi[j - 1]
        }
        else if (Left == 1 && Up == 1) {
          int p, tot = 1;
          for (p = j + 1; p <= m; p++) {
            if (code.s[p] == 1) tot++;
            if (code.s[p] == 2) tot--;
            if (!tot) break;
          }
          code.s[0] = code.s[j] = 0, code.s[p] = 1;
          insert( zip(code), DP);
        }
        else if (Left == 2 && Up == 2) {
          int p, tot = -1;
          for (p = j - 1; p ; p--) {
            if (code.s[p] == 1) tot++;
            if (code.s[p] == 2) tot--;
            if (!tot) break;
          }
          code.s[0] = code.s[j] = 0, code.s[p] = 2;
          insert(zip(code), DP);
        }
        else if (Left == 2 && Up == 1) 
          code.s[0] = code.s[j] = 0, insert(zip(code), DP);
        else if (Left == 1 && Up == 2) {
          code.s[0] = code.s[j] = 0;
          int flag = 0;
          if (i == Endx && j == Endy) ans += DP;
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
/*
1663358344520 1663358344520 1663358344520 1663358344520 1663358344520 1663358344520 1663358344520 
150
*/