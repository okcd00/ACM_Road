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
	int cases=0;
	scanf("%d",&cases);
	for(int _case=1;_case<=cases;_case++)
	{
		ll l,r,t,p=1;	cin>>l>>r;
		for(ll i=0;i<63;i++)
		{
			ll t=l|p;
			if(t>r)break;
			l=t,p<<=1;
			//cout<<t<<endl;
		}
		cout<<l<<endl;
	}
	return 0;
}
