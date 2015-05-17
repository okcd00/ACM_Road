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

int des[2048];

int main()
{
	int n,k;	cin>>n>>k;
	memset(des,0,sizeof des);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&des[i]);
	}
	sort(des,des+n,cmp);
	int rest=k,t=0;
	for(int i=0;i<n;i++)
	{
		if(rest>0)
		{
			if(rest==k) t+=2*(des[i]-1);
			rest--;
		}
		if(rest==0) rest=k;
		//cout<<i<<":"<<rest<<":"<<t<<endl;
	}
	cout<<t<<endl;
	return 0;
}
