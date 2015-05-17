#include <cmath> 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[100001]={0};
int dp[100001]={0};

int main()
{
	int n,cnt=0,flag=0;	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(!flag)
		{
			if(!i && a[i]>=a[i-1])continue;
			if(a[i]<a[i-1]) 
			{
				if(a[i]<=a[0])cnt=1,flag=1;
				else 
				{		
					flag=cnt=-1;
					break;
				}
			}
		}
		else
		{
			if(a[i]>=a[i-1])cnt++;
			else if(a[i]<a[i-1])
			{
				flag=cnt=-1;
				break;
			}
			if(a[i]>a[0])
			{
				flag=cnt=-1;
				break;
			}
		}
		//cout<<i<<":"<<cnt<<endl;
	}
	if(flag==0)cout<<0<<endl;
	else cout<<cnt<<endl;
	return 0;
}
