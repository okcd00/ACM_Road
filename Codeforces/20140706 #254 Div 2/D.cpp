#include <cmath>   
#include <vector>  
#include <cctype>  
#include <cstdio>  
#include <string>  
#include <cstdlib>  
#include <cstring>  
#include <iostream>  
#include <algorithm>
#define MAXN 100001  
using namespace std;

typedef __int64 ll;
ll n,d,x,a[MAXN],b[MAXN],lst[MAXN];

ll getNextX() 
{
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB() 
{
	ll i;
    for(i = 0; i < n; i++)        a[i] = i + 1;
    for(i = 0; i < n; i++)        
	{
		ll t = getNextX() % (i + 1);
		ll temp = a[i];
		a[i] = a[t];
		a[t] = temp;
	}//swap(a[i], a[getNextX() % (i + 1)]);
    for(i = 0; i < n; i++)
        if (i < d)      b[i] = 1;
        else            b[i] = 0;
    for(i = 0; i < n; i++)        
	{
		ll t = getNextX() % (i + 1);
		ll temp = b[i];
		b[i] = b[t];
		b[t] = temp;
	}//swap(b[i], b[getNextX() % (i + 1)]);
}

ll solve(ll k)
{
	memset(lst,0,sizeof lst);
	ll j,ans=0;
	ll p = 0;
	for(j = 0;j <= k;j++)
	{
		if (b[j] == 0)continue;//jianzhi
		else 
		{
			lst[p] = a[k-j];
			//cout<<p<<"\t"<<a[k-j]<<endl;
			p++;
		}
	}
	//sort(lst,lst+p);
	for(int ii=0;ii<=p;ii++)
	if(lst[ii]>ans)ans=lst[ii];
	return ans;
}

int main()
{
	ll k;
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(lst,0,sizeof lst);
	scanf("%I64d%I64d%I64d",&n,&d,&x);
	initAB();
	//for(k=0;k<n;k++)	printf("%I64d\t%I64d\n",a[k],b[k]);
	for(k=0;k<n;k++)
	{
		printf("%I64d",solve(k));
		if(k<n-1)printf("\n");
	}
	return 0;
}
