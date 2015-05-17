#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll solve(ll now)
{
	if(now==1) return 3;
	if(now%4==3) return now+1;
	else if(now%2==1) return (now<<1)+1;
	else return (now<<2)+1;
}

int main()
{
	int t;	cin>>t;
	for(int tcs=1;tcs<=t;tcs++)
	{
		ll now;	cin>>now;
		cout<<solve(now)<<endl;
	}
    return 0;
}
