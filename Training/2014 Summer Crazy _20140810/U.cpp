#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int val[101];

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	int n;	cin>>n;
	int sum=0,mysum=0,cnt=0;
	memset(val,0,sizeof val);
	for(int nc=0;nc<n;nc++)
	{
		cin>>val[nc];
		sum+=val[nc];
	}
	sort(val,val+n,cmp);
	for(int i=0;i<n && mysum<=sum-mysum;i++)
	{
		cnt++;
		mysum+=val[i];
	}
	cout<<cnt;
	return 0;
}
