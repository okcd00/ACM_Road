#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn= 100001;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

struct Nod
{
	int v[32]={0};
}node[maxn<<2];

int lowbit(int x){return x & -x;}
int log2(int value)
{  
    int x=0;  
    while(value>1)  
    {  
        value>>=1;  
        x++;  
    }  
    return x;  
}  

int main()
{
	int n,m;	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int l,r,q;
		scanf("%d%d%d",&l,&r,&q);
		
	}
	
	return 0;
}
