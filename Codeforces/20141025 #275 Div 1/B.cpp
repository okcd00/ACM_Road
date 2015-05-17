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

bool cmp(const int a, const int b)
{
	return a > b;
}

int num[100086][32]={0};
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
		while(q)
		{
			int lb=lowbit(q);
			for(int i=l;i<=r;i++)
			{
				int pwr=log2(lb);
				if(num[i][pwr]==0)
				{
					num[i][pwr]=1;
					num[i][0]+=lb;
				}
				else
				{
					printf("NO");
					return 0;
				}
			}
		}
	}
	return 0;
}
