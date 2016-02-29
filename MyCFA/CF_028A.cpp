#include <cmath>   
#include <vector>  
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
  
struct point  
{  
    int x;  
    int y;  
}a[505];//list  

int n=0,m=0;  
int len[505], ans[505], mrk[505];  
  
void print()  
{  
    puts("YES");  
    for ( int i=1; i<=n; i++ )  
        printf("%d ",ans[i] ? ans[i] : -1);  
}  
  
bool judge(int i, int j)  //绳长是否与两个"钉间距"相等   
{  
    return len[j] == ( abs(a[i-1].x - a[i].x) + abs(a[i-1].y - a[i].y) ) 
			+ ( abs(a[i+1].x - a[i].x) + ( abs(a[i+1].y - a[i].y ) ) ) ;
}  
  
int main()  
{  
    memset(len,0,sizeof(len));  
    memset(ans,0,sizeof(ans));  
    memset(mrk,0,sizeof(mrk));  
    cin>>n>>m;  
    for(int i=1;i<=n;i++)    cin>>a[i].x>>a[i].y;  
    for(int j=1;j<=m;j++)    cin>>len[j];  
    //consider about the head and tail  
    a[0].x = a[n].x;  
    a[0].y = a[n].y;  
    a[n+1].x = a[1].x;  
    a[n+1].y = a[1].y;  
    //start from 1st or 2nd  
    int type = 1 ,flag = 0, t = 0;  
    for(int i=type;i<=n;i+=2)  
    {  
        flag = 0;  
        for (int j=1; j<=m; j++)   
        if (!mrk[j] && judge(i,j))    
        {  
            flag = 1;  
            ans[i] = j;  
            mrk[j] = 1;  
            break;   
        }  
        if ( flag == 0 ) { t = 1; break; }  
    }  
    if ( !t ) print();  
    else  
    {  
        type++;  
        memset(ans,0,sizeof(ans));  
        memset(mrk,0,sizeof(mrk));  
        for(int i=type;i<=n;i+=2)  
        {  
            flag = 0;  
            for (int j=1; j<=m; j++)   
            if (!mrk[j] && judge(i,j))    
            {  
                flag = 1;  
                ans[i] = j;  
                mrk[j] = 1;  
                break;   
            }  
            if ( flag == 0 ) { puts("NO");return 0;}  
        }  
        print();  
    }     
    return 0;  
}  
