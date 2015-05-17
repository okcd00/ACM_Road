#include <map>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

int x[1001]={0};
int y[1001]={0};
map<pair<int,int>,int> m;

int main()
{
	int n;	cin>>n;
	cin>>x[0]>>y[0];
	for(int ni=1;ni<=n;ni++) 
	{
		scanf("%d%d",&x[ni],&y[ni]);
		x[ni]=x[ni]-x[0],y[ni]=y[ni]-y[0];
		int g=__gcd(x[ni],y[ni]);
		if(g==0) g=Max(x[ni],y[ni]);
		m[make_pair(x[ni]/g,y[ni]/g)]++;
	}
	cout<<m.size();
	return 0;
}
