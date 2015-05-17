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

int main()
{
	int a=0,b=0,c=0,d=0;
	cin>>a>>b>>c>>d;
	double mp=max(3*a/10 , a-(a/250*c) );
	double vp=max(3*b/10 , b-(b/250*d) );
	if(mp>vp) cout<<"Misha";
	else if(mp<vp) cout<<"Vasya";
	else cout<<"Tie";
	return 0;
}

