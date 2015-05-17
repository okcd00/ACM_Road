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
int mrk[63]={0},c=0;
ll pow2[63]={0};

int ppc(ll x)
{
	int ret=0,tmp=x;
	while(tmp)
	{
		mrk[c++]=tmp&1;
		//cout<<c-1<<":"<<mrk[c-1]<<endl;
		ret+=1-tmp&1;
		tmp>>=1;
	}
	return ret;
}

void init_pow2()
{
	ll t=1;
	pow2[0]=1;
	for(int i=1;i<=62;i++)
	{
		t<<=1;
		pow2[i]=t;
		//cout<<t<<endl;
	}
}

int main()
{
	int cases=0;
	scanf("%d",&cases);
	init_pow2();
	for(int _case=1;_case<=cases;_case++)
	{
		ll l,r;	scanf("%I64d%I64d",&l,&r);
		if(l==r)
		{
			cout<<l<<endl;
			continue;
		}
		ll ans=l;
		int f=0;
		for(int i=0;pow2[i]<=r;i++)
		{
			//cout<<i<<endl;
			if(pow2[i]>ans) ans=pow2[i]-1,f=1;
			if(i==59) 
			{
				cout<<pow2[59]-1<<endl;
				continue;
			}
		}
		//cout<<ans;
		//ans=max(l,ans);
		c=ppc(ans);
		//cout<<c;
		if(ans<=r && f==1)
		{
			while(1)
			{
				if(ans<=r) ans<<=1,ans+=1;
				else break;
			}
			//cout<<(ans<<1)<<endl
			cout<<(ans>>1)<<endl;
			continue;
		}
		else
		{
			//cout<<"here";
			int flag=0;
			for(int i=0;i<=62;i++)
			{
				//cout<<mrk[i];
				if(!mrk[i])
				{
					//cout<<i;
					if( (ans+(1<<i))>r )
					{
						cout<<ans<<endl;
						flag=1;
						break;
					}
					ans+=(1<<i);	
				}
				//cout<<ans<<endl;
			}
			if(!flag)cout<<ans<<endl;
		}

	}
	return 0;
}
