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
	int n;	cin>>n;
	int max=0,min=2147483646,max_cnt=0,min_cnt=0,now;
	for(int ni=0;ni<n;ni++)
	{
		cin>>now;
		if(now>max)	max=now,max_cnt=0;
		if(max==now) max_cnt++;
		if(now<min) min=now,min_cnt=0;
		if(min==now) min_cnt++;
	} 
	if(max==min) cout<<0<<" "<<(ll)max_cnt*(ll)(min_cnt-1)/2<<endl;
	else cout<<(max-min)<<" "<<(ll)max_cnt*(ll)min_cnt<<endl;
	return 0;
}
