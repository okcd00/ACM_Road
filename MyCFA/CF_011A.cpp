#include <algorithm>  
#include <iostream>  
#include <cstdio>  
using namespace std;  
//http://blog.csdn.net/okcd00/article/details/24443263
int main()  
{  
    int n,d,cnt=0;  
    scanf("%d%d",&n,&d);  
    int val[n];  
    for(int i=0;i<n;i++)  
        scanf("%d",&val[i]);  
      
    for(int i=1;i<n;i++)  
    {  
        if(val[i]>val[i-1])continue;  
        else   
        {  
            int temp=val[i-1]-val[i];  
            val[i]+=(temp/d+1)*d;  
            cnt+=(temp/d+1);  
        }  
    }  
    printf("%d",cnt);  
    return 0;  
}   