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

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	int n=0;	cin>>n;
	ll sum1=0,sum2=0;
	int num1[200048]={0},v1=0;
	int num2[200048]={0},v2=0;
	int last=0;
	for(int i=0;i<n;i++)
	{
		int tmp;	scanf("%d",&tmp);
		if(tmp>0) 	sum1+=tmp,num1[v1++]=tmp;
		else 		sum2+=-tmp,num2[v2++]=-tmp;
		if(i==n-1)last=tmp;
	}
	if(sum1>sum2)cout<<"first";
	else if(sum2>sum1)cout<<"second";
	else 
	{
		if(v1>v2)
		{
			for(int i=0;i<v2;i++)
			{
				if(num1[i]==num2[i])continue;
				else if(num1[i]>num2[i])
				{
					cout<<"first"; 
					return 0;
				}
				else
				{
					cout<<"second"; 
					return 0;
				}
			}
			cout<<"first";
			return 0;
		}
		else
		{
			for(int i=0;i<v1;i++)
			{	
				if(num1[i]==num2[i])continue;
				else if(num1[i]>num2[i])
				{
					cout<<"first"; 
					return 0;
				}
				else
				{
					cout<<"second"; 
					return 0;
				}
			}
			if(v1==v2 && last<0)cout<<"second";
			else if(v1==v2) cout<<"first";
			else cout<<"second";
			return 0;
		}
	}
	return 0;
}
