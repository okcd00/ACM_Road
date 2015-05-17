#include <cmath>   
#include <cstdio>  
#include <string>  
#include <cstring>  
#include <iostream>  
#include <algorithm>
using namespace std;
typedef __int64 ll;
/*
ll jc[31];
void j_init()
{
	memset(jc,0LL,sizeof jc);
	jc[0]=1LL;
	for(int i=1;i<31;i++)
		jc[i]=jc[i-1]*(ll)i;
}
*/

ll C(int n,int m)
{
	ll ans=1LL;
	if(n<m)			return 0;
	if(n==m||m==0)	return 1LL;
	if(m==1||n-m==1)return (ll)n;
	for(int i=1;i<=m;i++)
	{
		ans*=(ll)(n-i+1);
		ans/=(ll)i;
	}
	return ans;
}

int main()
{
	int T;
	cin>>T;
	//j_init();
	//cout<<jc[30];
	for(int i=1;i<=T;i++)
	{
		int N,M;
		cin>>N>>M;
		cout<<C(N,M)<<endl;
	}
	return 0;
} 
