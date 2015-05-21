#include <cmath>   
#include <cctype>  
#include <cstdio>  
#include <string>  
#include <cstdlib>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
using namespace std;  

//“上司即ROOT”-压缩

int  pre[1050]; //pre 上司节点   
bool t[1050];   //t 用于标记独立块的根结点  
  
int Find(int x) //获得x所在树的根节点   
{  
    int r=x, i=x, tmp;  
    while(r!=pre[r]) r=pre[r];  
    while(pre[i]!=r)    //一路向上，把路上的所有上司直接前指向root   
    {  
        tmp=pre[i];  
        pre[i]=r;  
        i=tmp;  
    }  
    return r;  
}  
  
void mix(int x,int y)  
{  
    int fx=Find(x), fy=Find(y);  
    if(fx!=fy)  pre[fy]=fx;  
}   
  
int main()  
{  
    int n,m,a,b,i,j,ans;  
    while(scanf("%d",&n) && n)  
    {  
        scanf("%d",&m);   
        for(i=1;i<=n;i++) pre[i]=i;  
        for(i=1;i<=m;i++)          //吸收并整理数据   
        {  
            scanf("%d%d",&a,&b);  
            mix(a,b);  
        }  
        memset(t,0,sizeof(t));  
        for(i=1;i<=n;i++)          //标记根结点  
        {  
            int tf=Find(i);  
            //cout<<i<<":"<<tf<<endl;  
            t[tf]=1;  
        }  
        for(ans=0,i=1;i<=n;i++)  if(t[i]) ans++;  
        printf("%d\n",ans-1);  
    }  
    return 0;  
}  
