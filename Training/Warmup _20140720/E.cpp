#include <cmath>   
#include <cstdio>  
#include <string>  
#include <cstring>  
#include <iostream>  
#include <algorithm>
using namespace std;
int dp[50010];
int main()
{
	int T;	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		//memset(a,0,sizeof a);
		memset(dp,0,sizeof dp);
		printf("Case %d:\n",cs);
		int N;	scanf("%d",&N);
		for(int i=1;i<=N;i++)	
		{
			int a;	scanf("%d",&a);
			dp[i]+=dp[i-1]+a;
		}
		char huiche,c;
		while(1)
		{
			scanf("%c",&huiche);
			scanf("%c",&c);
			int i,j;
			if(c=='Q')
			{
				while(c!=' ')scanf("%c",&c);
				scanf("%d%d",&i,&j);
				cout<<dp[j]-dp[i-1]<<endl;
			}
			else if(c=='A')
			{
				while(c!=' ')scanf("%c",&c);
				scanf("%d%d",&i,&j);
				for(int k=i;k<=N;k++)dp[k]+=j;
			}
			else if(c=='S')
			{
				while(c!=' ')scanf("%c",&c);
				scanf("%d%d",&i,&j);
				for(int k=i;k<=N;k++)dp[k]-=j;
			}
			else if(c=='E')
			{
				int two=2;
				while(two--)scanf("%c",&c);
				break;	
			}
		}
	}
	return 0;
} 
