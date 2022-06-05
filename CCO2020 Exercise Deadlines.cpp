#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define N 200010
using namespace std;
int f[N],d[N];
set<int>s;
int a[N],n;
void add(int x){for(;x;x-=x&-x) a[x]++;}
int qry(int x){int v=0;for(;x<=n;x+=x&-x) v+=a[x];return v;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) s.insert(i);
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);
    for(int i=n;i;i--)
    {
        auto p=s.upper_bound(d[i]);
        if(p==s.begin()){puts("-1");return 0;}
        f[i]=*--p,s.erase(p);
    }
    long long ans=0;
    for(int i=1;i<=n;i++) ans+=qry(f[i]),add(f[i]);
    printf("%lld\n",ans);
    return 0;
}
