#include<cstdio>
#include<iostream>
#define maxn 100010
#define pr 1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ull pow(ull m,ull n)
{
	ll ans=1;
	while(n)
	{
		if(n&1LL)	ans=(ans*m)%pr;
		n>>=1;
		m=(m*m)%pr;
	}
	return ans;
}
int main()
{
	ull in;	cin>>in;
	if(in==0)	cout<<1<<endl;
	else		cout<<(pow(4,in-1)*2+pow(2,in-1))%pr<<endl;
	return 0;
}
