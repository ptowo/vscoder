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
const int N = 6000;
int r, c;
char ch[N][N];
bool check1(int n,int r) {
  if(ch[n][r] == '+' && ch[n - 1][r] == '|' && ch[n - 2][r] == '|' && ch[n - 3][r] == '+' && ch[n - 3][r + 1] =='-' && ch[n - 3][r + 2] =='-' && ch[n - 3][r + 3] =='-') return 1;
  return 0;
}
signed main () {
  ios::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
  cin >> r >> c;
  string qwq;  getline(cin, qwq);
  FOR(i, 1, r) {
    string a = " ";
    getline(cin, a);
    //cout << a<<"\n";
    FOR(j, 1, c) ch[i][j] = a[j- 1];
  }
  //读入  
  int ans = 0;
  int fl = 0;
  for(int i = 1; i <= c; i++) {
    if(ch[r][i] == '+' && ch[r][i + 1] == '-' && ch[r][i + 2] == '-' && ch[r][i + 3] == '-') {
      fl++;  i = i + 3;  continue;
    }
  }
  //底边
  int pos = 0;
  for(int i = c; i >= 1; i--) {
    if(ch[r - 1][i] == '/') {  pos = i;  break;  }
  }
  int d = 1, now = r - 1;
  while(1) {
    if( pos + 2 >= c || now - 2 <= 0 || ch[now - 2][pos + 2] != '/' ) break;
    d++;  now -= 2, pos += 2;
  }
  //底边
  int h = 0;
  for(int i = r; i >= 1; i--) {
    if(ch[i][1] == '+' && ch[i - 1][1] == '|' && ch[i - 2][1] == '|') {
      h++; i = i - 2;  continue;
    }
  }
  //高
  
  int jb = 0;
  for(int i = 1; i <= c; i++) {
    if(ch[r][i] != '+') break;
    if(ch[r][i] == '+' && ch[r][i + 1] == '-' && ch[r][i + 2] == '-' && ch[r][i + 3] == '-') {
      int now = r, lie = i, ft = 0;
      //ans = 0;
      for(; ; ) {
        if(now <= 3 || lie > c) break;
        if( check1(now, lie) == 1) {
          ans += d - ft, now -= 3;
          //cout << "RAbbit : " << ft << " " << now << " " << lie  << " +: " << d - ft << "\n";
        }
        else {
          lie += 2;  ft++;  now -= 2;
        }

      }
      //cout << "The Fangkuai is : " << i << " Hs : " << ans << "\n";
      i = i + 3;  continue;
      //jb += ans;
    }
  }
  cout << ans << "\n";
  //cout << fl << " " << d << " " << h << " " << jb << "\n";
  return 0;
}
/*
遍历倒数第二层的 / 在那里出现，并且往上延申，可以知道底面宽
遍历最后一层得到地面

RAbbit : 0 11 1 +: 2
RAbbit : 0 8 1 +: 2
RAbbit : 0 5 1 +: 2
The Fangkuai is : 1 Hs : 6
RAbbit : 0 11 5 +: 2
RAbbit : 0 8 5 +: 2
RAbbit : 1 3 7 +: 1
The Fangkuai is : 5 Hs : 5
RAbbit : 0 11 9 +: 2
RAbbit : 1 6 11 +: 1
The Fangkuai is : 9 Hs : 3
3 2 3 0
*/