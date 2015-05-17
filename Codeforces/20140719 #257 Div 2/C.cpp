#include <cmath>   
#include <cstdio>  
#include <string>  
#include <cstring>  
#include <iostream>  
#include <algorithm>
#define update(x) ans=ans>x?ans:x
using namespace std;
typedef long long ll;

int main()
{
	ll n,m,k,ans=0;
	cin>>n>>m>>k;
	if(k>n+m-2){cout<<"-1";return 0;}
	//if(k==n+m-2){cout<<"1";return 0;}
	if(k<m)	update(n*(m/(k+1)));
	if(k<n) update(m*(n/(k+1)));
	if(k>=m)	update(n/(k-m+2));
	if(k>=n)    update(m/(k-n+2));
	cout<<ans;
	return 0;
}

/*
int main()
{
	ll n,m,k;
	cin>>n>>m>>k;
	if(k>n+m-2){cout<<"-1";return 0;}
	if(k==n+m-2){cout<<"1";return 0;}
	ll ansn=0,ansm=0,ansb=0;
	if(k+1<=n) ansn=n*m/(k+1);
	if(k+1<=m) ansm=n*m/(k+1);
	if(k%2==0)
	{
		ll a=k/2+1,b=k/2+1;
		if(a>m){b=b+a-m,a=m;}
		if(b>m){a=a+b-m,b=m;}
		if(a>n){b=b+a-n,a=n;}
		if(b>n){a=a+b-n,b=n;}
		ansb=(m/a) * (n/b);
	} 
	else 
	{
		
		ll a=k/2+2,b=k/2+1;
		if(a>m){b=b+a-m,a=m;}
		if(b>m){a=a+b-m,b=m;}
		if(a>n){b=b+a-n,a=n;}
		if(b>n){a=a+b-n,b=n;}
		ansb=max ((m/a)*(n/b),(m/b)*(n/a));
	}
	cout<<max(ansn,max(ansm,ansb));
	return 0;
} 
*/
