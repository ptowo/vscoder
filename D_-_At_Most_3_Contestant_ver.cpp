// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
int w;
signed main () {
  w = read();
  cout << 300 << "\n";
  for (int i = 1; i <= 100; i++) cout << i << " ";
  for (int i = 100; i <= 10000; i += 100) cout << i << " ";
  for (int i = 10000; i <= 1000000; i += 10000) cout << i << " ";  
  return 0;
}
/*
 考虑 100 进制拆分
 1~100 中的数全部保留，总共  100 个
 对于 100 ~ 10000 中的数全部也保留，总共 100 个
 对于 10000 ~ 1000000 中的数也保留，每隔 1000
 */