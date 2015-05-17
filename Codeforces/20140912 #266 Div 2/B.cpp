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

int main()
{
	ll n,a,b;
	cin>>n>>a>>b;
	if(a*b>=n*6)
	{
		cout<<a*b<<endl;
		cout<<a<<" "<<b<<endl;
		return 0;
	}
	ll s=n*6;
	for(ll i=a;i<=s/b+1;i++)
	{
		if(s%i==0 && s/i>=b)
		{
			cout<<s<<endl;
			cout<<i<<" "<<s/i<<endl;
			return 0;
		}
	}
	for(ll i=b;i<=s/a+1;i++)
	{
		if(s%i==0 && s/i>=a)
		{
			cout<<s<<endl;
			cout<<s/i<<" "<<i<<endl;
			return 0;
		}
	}
	if((s/b+1)*b < (s/a+1)*a)
	{
		cout<<(s/b+1)*b<<endl;
		cout<<(s/b+1)<<" "<<b<<endl;
		return 0;
	}
	else 
	{
		cout<<a*(s/a+1)<<endl;
		cout<<a<<" "<<(s/a+1)<<endl;
		return 0;
	}
	/*
	ll a1=a,b1=b,min=123456789;
	ll posa,posb;
	while(1)
	{
		if(a1*b1==6*n)
		{
			cout<<a1*b1<<endl;
			cout<<a1<<" "<<b1<<endl;
			return 0;
		}
		else if(a1*b1>6*n)	break;
		else a1++,b1++;
	}
	for(ll i=a;i<=a1;i++)
	{
		ll now=i*b1;
		if(now>=6*n && now<min)	min=now,posa=i,posb=b1;
	}
	for(ll j=b;j<=b1;j++)
	{
		ll now=j*a1;
		if(now>=6*n && now<min) min=now,posa=a1,posb=j;
	}
	cout<<min<<endl;
	cout<<posa<<" "<<posb<<endl;
	return 0;
	*/
}
