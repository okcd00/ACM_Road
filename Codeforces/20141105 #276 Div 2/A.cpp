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

int main()
{
	int a,m;	cin>>a>>m;
	int vis[100086]={0};
	while(1)
	{
		if(a==0){cout<<"Yes";return 0;}
		if(vis[a]==1){cout<<"No";return 0;}
		vis[a]=1;
		a=(a+a)%m;
	}
	return 0;
}
