#include <cmath>     
#include <cstdio>    
#include <string>    
#include <cstring>
#include <cstdlib>     
#include <iostream>    
#include <algorithm>    
#define FLT   30000  
#define MAXN  60001  
#define INF -129999  
using namespace std;    
int n,res,ran,Spt[MAXN];  
  
int main()  
{  
    bool flag=false;  
    memset(Spt,INF,sizeof Spt);  
    scanf("%d",&n);  
    for(int ncnt=1;ncnt<=n;ncnt++)  
    {  
        scanf("%d%d",&res,&ran);  
        Spt[res+FLT]=res+ran;  
        if(Spt[res+ran+FLT]!=INF&&Spt[res+ran+FLT]==res)flag=true;  
    }  
    printf(flag?"YES":"NO");  
    return 0;  
}  
