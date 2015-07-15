#include<cstdio>  
#include<string>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
  
int mark[201];   
  
int main()  
{  
    int n=0;  
    scanf("%d",&n);  
    memset(mark,0,sizeof(mark));  
    for(int i=1;i<=n;i++)  
    {  
        int now=0;  
        scanf("%d",&now);  
        mark[now+100]=1;  
    }  
    int flag=0;  
    for(int j=0;j<=200;j++)  
    {  
        if(flag==1&&mark[j]==1)  
        {  
            printf("%d",j-100);   
            return 0;  
        }  
        if(flag==0&&mark[j]==1) flag=1;  
    }  
    printf("NO");  
    return 0;  
}  
