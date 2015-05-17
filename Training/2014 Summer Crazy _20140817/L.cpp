#include <cmath>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int main()
{
	int n,h[100011];
	long long ans=0;
	cin>>n;	ans+=n;
	for(int ni=1;ni<=n;ni++)	cin>>h[ni];
	ans+=h[1];
	for(int i=2;i<=n;i++)	ans+=(1+abs(h[i]-h[i-1]));
	cout<<ans;	return 0;
}
