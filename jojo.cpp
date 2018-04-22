#include<algorithm>
#include<ctype.h>
#include<cstdio>
#include<queue>
#define N 1000020
using namespace std;
inline int read(){
    int x=0,f=1;char c;
    do c=getchar(),f=c=='-'?-1:f; while(!isdigit(c));
    do x=(x<<3)+(x<<1)+c-'0',c=getchar(); while(isdigit(c));
    return x*f;
}
priority_queue<int,vector<int>,less<int> >q;
int n,m;
long long sum=0;
double ans;
struct Data{
    int x,y;
}a[N];
inline bool cmp(Data a,Data b){
    return a.y<b.y;
}
int main(){
    freopen("jojo.in","r",stdin);
    freopen("jojo.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)
        a[i].x=read();
    for(int i=1;i<=n;i++)
        a[i].y=read();
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<m;i++){
        q.push(a[i].x);
        sum=sum+a[i].x;
    }
    ans=1.0*(sum+a[m].x)/a[m].y;
    for(int i=m+1;i<=n;i++){
        if(!q.empty() && a[i-1].x<q.top()){
            sum-=q.top();
            q.pop();
            sum+=a[i-1].x;
            q.push(a[i-1].x);
        }
        ans=min(ans,1.0*(sum+a[i].x)/a[i].y);
    }
    printf("%d",int(ans));
    return 0;
}
