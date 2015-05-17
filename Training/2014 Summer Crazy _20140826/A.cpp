#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,k;	cin>>n>>k;
	int ans=-1234567890;
	for (int i=1;i<=n;i++)
	{
		int f,t,temp=0;	cin>>f>>t;
		if (t>=k) temp=f-(t-k);		else temp=f;
		if (ans<temp) ans=temp;
	}
	cout<<ans;
	return 0;
}
