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

int num[600086],pos1[600086],pos2[600086];
ll sum[600086];

int main()
{
	int n;	scanf("%d",&n);
	if(n<3){cout<<0<<endl;return 0;}
	scanf("%d",&num[0]);
	sum[0]=num[0];
	for(int i=1;i<n;i++)
	{
		scanf("%d",&num[i]);
		sum[i]=num[i]+sum[i-1];
	}
	if(sum[n-1]%3!=0) cout<<0<<endl;
	else
	{
		ll div1=sum[n-1]*1/3,div2=sum[n-1]*2/3;
		int c1=0,c2=0;
		for(int i=0;i<n;i++)
		{
			if(sum[i]==div1 && i<n-1) pos1[c1++]=i+1;
			if(sum[i]==div2 && i>=1 && i<n-1) pos2[c2++]=i;
		} 
		//int cnt1=count(sum,sum+n,sum[n-1]*2/3);
		//int cnt2=count(sum,sum+n,sum[n-1]*1/3);
		ll anscnt=0;
		/*************************
		for(int i=0;i<c1;i++)
		{cout<<pos1[i]<<endl;}
		for(int i=0;i<c2;i++)
		{cout<<pos2[i]<<endl;}
		**************************/
		for(int i=0;i<c1;i++)
		{
			for(int j=0;j<c2;j++)
			{
				//cout<<"now is "<<pos1[i]<<":"<<pos2[j]<<endl;
				if(pos1[i] <= pos2[j])
				{
					anscnt++;
					//cout<<pos1[i]<<":"<<pos2[j]<<endl;
				}
			}
		}
		cout<<anscnt<<endl;
	}
		
	return 0;
}
