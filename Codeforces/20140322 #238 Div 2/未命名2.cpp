#include <cstdio>
#include <iostream>
#include <algorithm>
//Note: since the size of the input and output could be very large, 
//don't use slow output techniques in your language. For example, 
//do not use input and output streams (cin, cout) in C++.

#define Maxn 1000000
using namespace std;


int main()
{
    int n,sum=0;
    int chs[500000];
    bool hash[1000000];
    memset(hash,true,sizeof(hash));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
            {
             scanf("%d",&chs[i]);
             sum+=chs[i]-1;
             hash[chs[i]]=false;
            }
    if(hash[Maxn-sum]==true){ printf("1\n%d",Maxn-sum);return 0; }
    if(hash[Maxn-sum+1]==true){ printf("2\n%d %d",Maxn-sum+1,Maxn-1);return 0;}
    
    //2014-03-23 01:23:45 GG Rank<100
    return 0;
}

