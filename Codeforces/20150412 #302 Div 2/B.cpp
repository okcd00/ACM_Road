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

int mp[101][101]={0};

int main()
{
	int n,k;	cin>>n>>k;
	if((n*n+1)>>1<k)
	{
		cout<<"NO"<<endl;
		return 0;
	} 
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if((i+j)%2==0 && k) mp[i][j]=1,k--;
			else mp[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mp[i][j]==1) printf("L");
			else printf("S");
		}
		if(i<n-1)printf("\n");
	}
	return 0;
}
