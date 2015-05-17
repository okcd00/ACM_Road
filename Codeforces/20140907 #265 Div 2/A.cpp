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

int val[101],ans[101];

int main()
{
	int n;
	string s;
	cin>>n>>s;
	memset(val,0,sizeof val);
	memset(ans,0,sizeof ans);
	for(int i=0;i<n;i++)
		val[i]=s[i]-'0';
	int flag=0;
	for(int pos=0;pos<n;pos++)
	{
		if(val[pos]==0 && flag==0)
		{
			ans[pos]=1;
			flag=1;
		}	
		else if(val[pos]==1 && flag==0)
		{
			ans[pos]=0;
			flag=0;
		}
		else ans[pos]=val[pos];
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(ans[i]!=val[i])cnt++;
		//cout<<ans[i]<<":"<<val[i]<<endl;
	}
	cout<<cnt<<endl;
	return 0;
}
