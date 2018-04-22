#include<algorithm>
#include<ctype.h>
#include<cstdio>
#define N 10000005
using namespace std;
inline int read(){
    int x=0,f=1;char c;
    do c=getchar(),f=c=='-'?-1:f; while(!isdigit(c));
    do x=(x<<3)+(x<<1)+c-'0',c=getchar(); while(isdigit(c));
    return x*f;
}
int n,k,l,top,top1;
int p[N],s[N],s1[N];
long long ans,tmp,f1[N],f2[N];
int main(){
    freopen("wyr.in","r",stdin);
    freopen("wyr.out","w",stdout);
    n=read();k=read();l=read();
    for(int i=1;i<=n;i++){
        p[i]=read();
        if(p[i]<=l>>1) s[++top]=p[i];
        else s1[++top1]=l-p[i];
    }
    for(int i=1;i<=top1 && i<=top1-i+1;i++)
        swap(s1[i],s1[top1-i+1]);
    for(int i=1;i<=top;i++){
        if(i<=k) f1[i]=s[i];
        else f1[i]=f1[i-k]+s[i];
    }
    for(int i=1;i<=top1;i++){
        if(i<=k) f2[i]=s1[i];
        else f2[i]=f2[i-k]+s1[i];
    }
    ans=(f1[top]+f2[top1])*2;
    for(int i=top-k;i<=top;i++){
        tmp=(f1[i]+f2[max(top1-k+top-i,0)])*2+l;
        ans=min(ans,tmp);
    }
    printf("%lld",ans);
return 0;
}
