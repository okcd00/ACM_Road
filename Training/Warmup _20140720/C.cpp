#include <cmath>   
#include <cstdio>  
#include <string>  
#include <cstring>  
#include <iostream>  
#include <algorithm>
using namespace std;
int dp [1001][1001];
int vol[1001];
int val[1001];
int main()
{
	int T;
	cin>>T;
	for(int cases=1;cases<=T;cases++)
	{
		//pair<int,int> bone; //val-vol
		memset(vol,0,sizeof vol);
		memset(val,0,sizeof val);
		int N,V;		cin>>N>>V;
		//priority_queue <pair<int, int> > pq;
		for(int i=1;i<=N;i++)	
		{
			cin>>val[i]>>vol[i];
			//pq.push(bone);
		}
		dp[0][0]=0;
		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<=V;j++)
			if(vol[i]<=j)	dp[i][j]=max(dp[i-1][j],dp[i-1][j-vol[i]]+val[i]);
			else	dp[i][j]=dp[i-1][j];
		}
		cout<<dp[N][V]<<endl;	
	}
	return 0;
} 
