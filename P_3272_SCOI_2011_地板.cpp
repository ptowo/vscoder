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
const int N = 3e6, ftp = 198999, mod = 20110520;
int d, n, m, a[122][122];
int las, now, cnt[2]; //las,now滚动 cnt[2] 滚动的总合法方案数
int v[N][2], dp[N][2], nex[N], first[N], Endx, Endy;
int ans;
//0 1 2 没有插头 左括号 右括号
struct node2 { int s[120]; };
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
  val %= mod;
  int key = sta % ftp;
  for (int i = first[key]; i; i = nex[i]) 
    if (sta == v[i][now]) { dp[i][now] += val; dp[i][now] %= mod; return; }
  ++cnt[now];
  v[ cnt[now] ][now] = sta, dp[ cnt[now] ][now] = val; //滚动记录状态和 dp 值
  nex[ cnt[now] ] = first[key], first[key] = cnt[now]; //插入新的
}
char ch[102];
signed main () {
  cin >> n >> m;
  if (m > n) {
    FOR (i, 1, n) {
      cin >> (ch + 1);
      FOR (j, 1, m) 
        if (ch[j] == '_') a[j][i] = 1, Endx = j, Endy = i; 
    }
    swap(n, m);
  }  else {
    FOR (i, 1, n) {
      cin >> (ch + 1);
      FOR (j, 1, m) 
        if (ch[j] == '_') a[i][j] = 1, Endx = i, Endy = j; 
    }
  }
  insert(0, 1);
  FOR (i, 1, n) {
    
    FOR (j, 1, m) {
      memset(first, 0, sizeof(first));
      las = now, now ^= 1; cnt[now] = 0;
      //cout << cnt[las] << "\n";
      for (int k = 1; k <= cnt[las]; k++) {
        node2 code = unzip(v[k][las]);
        int Left = code.s[0], Up = code.s[j], DP = dp[k][las];
        if (!a[i][j]) {//当前为障碍格子，那么直接顺延
          if (!Left && !Up) insert( zip(code), DP);
        }
        else if (!Left && !Up) {
          if (a[i][j + 1] && a[i + 1][j]) 
            code.s[0] = 2, code.s[j] = 2, insert( zip(code), DP);
          if (a[i][j + 1])
            code.s[0] = 1, code.s[j] = 0, insert( zip(code), DP);
            //向右添加插头 2
          if (a[i + 1][j]) 
            code.s[0] = 0, code.s[j] = 1, insert( zip(code), DP);
        } //ok
         /*j+1->j j->0*/
         else if (Left == 1 && !Up) {
          if (a[i][j + 1])
            insert( zip(code), DP);
            /*向右添加插头 1*/
          if (a[i + 1][j])
            code.s[j] = 2, code.s[0] = 0, insert( zip(code), DP );
        } //ok
        else if (Left == 1 && Up == 1) {
          if (i == Endx && j == Endy) { ans += DP; ans %= mod; }
          code.s[0] = code.s[j] = 0;
          insert( zip(code), DP);
        } //ok
        else if (!Left && Up == 1) {
          if (a[i + 1][j]) 
           insert( zip(code), DP );
          if (a[i][j + 1])
            code.s[0] = 2, code.s[j] = 0, insert(zip(code), DP);
        } //ok
        else if (!Left && Up == 2) {
          if (a[i + 1][j])
            insert( zip(code), DP);
          code.s[j] = 0;
          insert( zip(code), DP);
          if (i == Endx && j == Endy) { ans += DP; ans %= mod; }
        }  //ok
        else if (Left == 2 && !Up) {
          if (a[i][j + 1])
            insert( zip(code), DP );
          code.s[0] = 0;
          insert( zip(code), DP );
          if (i == Endx && j == Endy) {  ans += DP; ans %= mod; }
        } //ok
      }
    }
  }
  ans %= mod;
  printf("%lld\n", ans);
  return 0;
}