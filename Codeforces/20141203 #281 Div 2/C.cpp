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
#define update if(posb-posa>afin-bfin){afin=3*n-posa;	bfin=3*m-posb;}
ll a[200048]={0},b[200048]={0};

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	int n;	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
	}	sort(a,a+n);
	int m;	cin>>m;
	for(int i=0;i<m;i++)
	{
		scanf("%I64d",&b[i]);
	}	sort(b,b+m);
	
	int posa=0,posb=0;
	ll afin=3*n,bfin=3*m;
	while(1)
	{
		if(posa==n && posb==m)break;
		//cout<<"NOW posa:"<<posa<<"  posb:"<<posb<<endl;
		if(posa==n)
		{
			posb=m;
			update
		}
		else if(posb==m)
		{
			update
			posa=n;
		}
		else if(a[posa]>=b[posb])
		{
			while(a[posa]>=b[posb] && posb<m) 
			{
				posb++;	
				while(a[posa]==b[posb-1]) posa++;
			}
			update
		}
		else
		{
			update
			while(a[posa]<b[posb] && posa<n) posa++;
		}
			
	}
	
	cout<<afin<<":"<<bfin<<endl;
	return 0;
}
