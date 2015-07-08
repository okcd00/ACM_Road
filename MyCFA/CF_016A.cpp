#include<algorithm>  
#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
using namespace std;  

int n,m,tmp;  
char huiche;  
char clr[100][100];  
  
bool solve()  
{  
    for(int i=0;i<n;i++)  
    {  
        scanf("%c",&huiche);  
        //scanf("%c",&clr[i][0]);  
        for(int j=0;j<m;j++)  
        {  
            scanf("%c",&clr[i][j]);  
            if(j!=0) if(clr[i][j]!=clr[i][0])return false;  
        }  
        if(i!=0) if(clr[i][0]==clr[i-1][0]) return false;  
    }     
    return true;  
}  
  
int main()  
{  
    scanf("%d%d",&n,&m);  
    printf(solve()==true?"YES":"NO");  
    return 0;  
}   