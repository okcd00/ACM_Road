#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
bool cmp(const int a, const int b)
{
	return a > b;
}

ll ans=0LL,tmp=0LL;
ll dp[200086]={0};
int mrk[200086]={0},tmrk[200086]={0};

int main()
{
	int n=0, now=0, i=0;	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&dp[i]);
	}
	int m=0;	cin>>m;
	for(i=0;i<m;i++)
	{
		scanf("%d",&now);
		mrk[now]++;
		tmrk[now]++;
	}
	if(n==2)
	{
		printf("%I64d",(dp[2]-dp[1])*(mrk[1]+mrk[2]-1));
		return 0;
	}
	int mr=min(mrk[1],mrk[n]);
	for(int i=2;i<=n-1;i++)
	{
		tmrk[i]/=2;
		mr=min(mr,tmrk[i]);
	} 
	if(mrk[1]>1 || mrk[n]>1 || mr>=1)
	{
		int round=min(mrk[1],mrk[n]);
		round=min(mr,round);
		mrk[1]-=round; mrk[n]-=round;
		for(int i=2;i<=n-1;i++)
		mrk[i]-=round*2;
		ans+=(dp[n]-dp[1])*2*round;
//		cout<<round<<":"<<mrk[1]<<mrk[2]<<mrk[3];
//		cout<<"now"<<ans<<endl;
	}
	if(m==n*2-2)
	{
		ll dist=dp[2]-dp[1];
		if(n!=2) for(int i=3;i<=n;i++)
		{
			if(dp[i]-dp[i-1]!=dist)
			{
				printf("-1");
				return 0;
			}
		}
		cout<<(ll)(dp[n]-dp[1])*2LL-dist<<endl;
		return 0;
	}
	int f1=0,f2l=0,f2r=0;
	int l1=0,l2=0,
		r1=0,r2=0;
	i=1;	while(mrk[i]==0)i++; 
	if(mrk[1]==1 && mrk[2]==2)
	{
		mrk[1]=2;
		f2l=l2=1;
		while(mrk[l2]==2 && l2<=n)l2++;l2--;
	} 
	if(mrk[n]==1 && mrk[n-1]==2)
	{
		mrk[n]=2;
		f2r=1;
		r2=n;
		while(mrk[r2]==2 && r2>=1)r2--;r2++;
	}
	for(i=max(l2,i);i<=n;i++)
	{
		if(f1==0 && mrk[i]==1)
		{
			f1=1;
			l1=r1=i;
			while(mrk[r1]==1 && r1<=n) r1++;r1--;
		}
	}
	//ALL	l2===================r2 <already considered>
	//f2l\f2r\f1 =========l2/l1--------------r1/r2============
	//f2l		==========l2
	//f2r		r2========== 
	//f1\f2r     l1-------------r1/r2=============
	//f1\f2l	============l2/l1------------
	//f1		l1---------------------l2
	
	//cout<<l1<<":"<<r1<<"  "<<l2<<":"<<r2<<endl;
	if(f1) ans+=(ll)(dp[r1]-dp[l1]);
	if(f2l) ans+=(ll)(dp[l2]-dp[1])*2LL;
	if(f2r) ans+=(ll)(dp[n]-dp[r2])*2LL;
	if(f1&&f2l) ans+=(ll)(dp[l1]-dp[l1-1]);
	if(f1&&f2r) ans+=(ll)(dp[r1+1]-dp[r1]);
	cout<<ans<<endl;
	return 0;
}
