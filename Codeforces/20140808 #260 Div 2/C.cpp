#include <map>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
ll dp[100001];

int main()
{
	ll ans=0;
	int n;	cin>>n;
	int tmp=0,max=0;
	map<int,int> m;	m.clear();
	map<int,int>::key_compare kcm=m.key_comp();
	for(int nc=0;nc<n;nc++)
	{
		scanf("%d",&tmp);
		if(max<tmp) max=tmp;
		m[tmp]++;
	}
	map<int,int>::iterator it=m.end();	*it--;
	int cnt=0,lf,ls,nf,ns;
	for(;it!=m.begin();*it--,cnt++)
	{
		//cout<<it->first<<":"<<it->second<<endl;
		nf=it->first,ns=it->second;
		if(cnt==0) dp[0]=(ll)nf*ns;
		else if(nf+1 < lf) dp[cnt]=dp[cnt-1]+(ll)nf*ns;
		else 
		{
			if(cnt>1) dp[cnt]=Max(dp[cnt-1] , dp[cnt-2]+(ll)nf*ns);
			else dp[cnt]=Max(dp[cnt-1],(ll)nf*ns);
		}
		lf=nf,ls=ns;
	}
	//BEGIN FOGGOTTEN!
	//cout<<it->first<<":"<<it->second<<endl;
	nf=it->first,ns=it->second;
	if(nf+1 < lf) dp[cnt]=dp[cnt-1]+(ll)nf*ns;
	else 
	{
		if(cnt>1) dp[cnt]=Max(dp[cnt-1] , dp[cnt-2]+(ll)nf*ns);
		else dp[cnt]=Max(dp[cnt-1],(ll)nf*ns);
	}
	
	//for(int i=0;i<=cnt;i++)	cout<<dp[i]<<endl;
	cout<<dp[cnt];
	/*do
	{
		cout<<it->first<<":"<<it->second<<endl;
	} while (kcm((*it++).first, max) );*/
	
	return 0;
}
