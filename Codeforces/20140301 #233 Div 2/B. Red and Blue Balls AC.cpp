#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <stack> //Add stack
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define RD(a) scanf("%d",&a)
#define PT(a) printf("%d",a)
using namespace std;
/*
int powr( int a, int b )
{
    int r = 1, base = a;
    while( b != 0 )
    {
        if( b & 1 )
            r *= base;
        base *= base;
        b >>= 1;
    }
    return r;
}
*/
long long quickpow(long long m , long long n)
{ 
    long long ans = 1; 
    while(n)
    { 
        if( n & 1 )//如果n是奇数 
            ans = (ans * m); 
        n = n >> 1;//位运算“右移1类似除1” 
        m = (m * m) ; 
    } 
    return ans; 
} 

int main()
{
    long long n;
    cin>>n;
    int add=0;
    long long ans=0;
    char tmp;
    for(int i=0;i<n;i++)
    {
              cin>>tmp;
              if(tmp=='B') ans += quickpow(2,add);
              add++;
    }
    cout<<ans;
}
