#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,p1,_max,_min,cnt=0,now;	
	cin>>n>>p1;	_max=_min=p1;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&now);
		if(now>_max) _max=now,cnt++;
		else if(now<_min) _min=now,cnt++;
	}
	cout<<cnt;
	return 0;
}
