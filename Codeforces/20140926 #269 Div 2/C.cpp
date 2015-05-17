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

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	ll c=1;
	ll n;	cin>>n;
	ll var=0;
	while(1)
	{
		ll rest=n-c*2,md=(n-c*2)%3;
		if( rest<0 || rest/3<(c-1)*c/2 )break;
		else if( rest/3==(n-1)*n/2) {var++;break;}
		else if( md!=0 ) c++;
		else var++,c++;
		//cout<<c<<endl;
	}
	cout<<var<<endl;
	return 0;
}
