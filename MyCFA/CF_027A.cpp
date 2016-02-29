#include <cmath>   
#include <cctype>  
#include <cstdio>  
#include <string>  
#include <cstdlib>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define Min(a,b) ((a)<(b)?(a):(b))  
  
bool mark[3001];  
  
int main()  
{  
    memset(mark,false,sizeof(mark));  
    int n=0;  cin>>n;  
    for(int i=1;i<=n;i++)  
    {  
        int now;  
        cin>>now;  
        mark[now]=true;  
    }  
    for(int j=1;j<=n+1;j++)  
    {  
        //cout<<mark[j];  
        if(mark[j]==false)  
        {  
            cout<<j;  
            return 0;  
        }  
    }  
    return 0;  
}  
