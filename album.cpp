#include<algorithm>
#include<ctype.h>
#include<cstdio>
#define N 2020
using namespace std;
inline int read(){
    int x=0,f=1;char c;
    do c=getchar(),f=c=='-'?-1:f; while(!isdigit(c));
    do x=(x<<3)+(x<<1)+c-'0',c=getchar(); while(isdigit(c));
    return x*f;
}
int n,x,ma1,ma2,ma3,ma4;
int main(){
    freopen("album.in","r",stdin);
    freopen("album.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        x=read();
        if(x==0){
            ma1++;
            ma3=max(ma2,ma3)+1;
        }
        else{
            ma2=max(ma1,ma2)+1;
            ma4=max(ma3,ma4)+1;
        }
    }
    printf("%d\n",max(ma3,ma4));
return 0;
}
