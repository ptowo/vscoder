#include<bits/stdc++.h>
using namespace std;
#define MAXN 10
struct ios_in{
 inline char gc(){
  static char buf[MAXN],*l,*r;
  return (l==r)&&(r=(l=buf)+fread(buf,1,MAXN,stdin),l==r)?EOF:*l++;
 }
 template <typename _Tp>
 inline ios_in&operator>>(_Tp&x){
  static char ch,sgn;
  for(sgn=0,ch=gc();!isdigit(ch);ch=gc()) {
   if(!~ch) return *this;
   sgn|=ch=='-';
  }
  for(x=0;isdigit(ch);ch=gc()) x=(x<<1)+(x<<3)+(ch^'0');
   sgn&&(x=-x);
   return *this;
 }
}Cin;
const int N = 3e6;
int n,m,x[N];
int dfn[N],low[N],cnt,nex[N],first[N],v[N],num;
int ins[N],tp,sc,scc[N],sz[N],s[N];
//scc[i]表示i所在scc的编号
void add(int from,int to){nex[++num]=first[from];first[from]=num;v[num]=to;	}
void tarjan(int u){
 low[u]=dfn[u]=++cnt;s[++tp]=u;ins[u]=1;
 for(int i=first[u];i;i=nex[i]){
  int to=v[i];
  if(!dfn[to]){
   tarjan(to);
   low[u]=min(low[u],low[to]);	
  }
  else if(ins[to]){
   low[u]=min(low[u],dfn[to]);	
  }	
 }
 if(dfn[u]==low[u]){
  ++sc;
  while(s[tp]!=u){
   scc[s[tp]]=sc;
   sz[sc]++;
   ins[s[tp]]=0;
   --tp;	
  }
  scc[s[tp]]=sc;
  sz[sc]++;
  ins[s[tp]]=0;
  --tp;	
 }	
} 
signed main(){
 Cin>>n>>m;
 for(int i=1;i<=m;i++){
  int a,b,c,d;
  Cin>>a>>c>>b>>d;
  if(c&&d){
   add(a,b+n);
   add(b,a+n);	
  }
  if(!c&&!d){
   add(a+n,b);
   add(b+n,a);	
  }
  if(c&&!d){
   add(a,b);
   add(b+n,a+n);	
  }
  if(!c&&d){
   add(a+n,b+n);
   add(b,a);	
  }	
 }
 for(int i=1;i<=2*n;i++)
  if(!dfn[i]) tarjan(i);	
 
 for(int i=1;i<=n;i++)
  if(scc[i]==scc[i+n]){printf("IMPOSSIBLE");return 0;}	
 
 printf("POSSIBLE\n");
 for(int i=1;i<=n;i++){
  if(scc[i]>scc[i+n]){//强连通分量小，拓扑序大，答案优秀 
   printf("1 "); 	
  }
  else printf("0 ");	
 }
 return 0;	
}