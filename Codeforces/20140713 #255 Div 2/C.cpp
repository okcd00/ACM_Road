#include <cmath>   
#include <vector>  
#include <cctype>  
#include <cstdio>  
#include <string>  
#include <cstdlib>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#define update(x) ans=(x>ans)?x:ans
using namespace std;
typedef long long ll;
ll n,ccnt,a[100001],dp[111111];
ll chain[100001]; //length of each sequence
ll pos[100001];

void init()
{
	ccnt=0;
	memset(a,0LL,sizeof a);
	memset(dp,0LL,sizeof dp);
	memset(pos,0LL,sizeof pos);
	memset(chain,0LL,sizeof chain);
	for(ll i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(i)
		{
			if(a[i]>a[i-1])dp[i]=dp[i-1]+1;
			else 
			{
				chain[ccnt]=dp[i-1]+1;
				pos[ccnt]=i-1;
				ccnt++;
				//cout<<dp[i-1]<<":m1: \t";
				dp[i]=0;
			}
		}
	}
	chain[ccnt]=dp[n-1]+1;
	pos[ccnt]=n-1;
}

ll solve()
{
	ll ans=0;
	if(ccnt==0)update(chain[0]);
	else 
	{
		update(chain[0]+1);
		for(int i=1;i<=ccnt;i++)
		{
			//cout<<chain[i]<<"\t"<<pos[i]<<endl;
			if(chain[i]==1)	//I am 1
			{
				if(a[pos[i-1]]+1<a[pos[i+1]-chain[i+1]+1])	//then change chain[i]
				update(chain[i+1]+chain[i-1]+1);
				else update(chain[i-1]+1);
			}
			else if(chain[i-1]==1)// my front is 1
				{
					update(chain[i]+1);
				}
			else if(chain[i+1]==1);// my back is 1 _for i+1 judgement
			else if(a[pos[i-1]]+1<a[pos[i]-chain[i]+2]) 	//then change chain[i]'s 1st
				update(chain[i]+chain[i-1]);
			else update(chain[i]+1);
		}
   }
	return ans;
}

int main()
{
	cin>>n;
	init();
	cout<<solve();
	return 0;
}
