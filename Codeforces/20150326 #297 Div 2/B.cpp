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
	string s;
	int m=0,now=0,a[100086]={0},b[200086]={0};
	cin>>s>>m;
	int len=s.length();
	for(int i=0;i<m;i++)
	{
		scanf("%d",&now);
		a[now-1]=1-a[now-1];
	}
	int rev=0;
	for(int i=0;i<len/2;i++)
	{
		if(a[i]!=0) rev=1-rev;
		b[i]=b[len-i-1]=rev;
	}
	for(int i=0;i<len;i++)
	{
		if(b[i]==1) printf("%c",s[len-i-1]);
		else printf("%c",s[i]);
	}
	return 0;
}
