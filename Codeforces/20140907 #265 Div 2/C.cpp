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

int val[1024];

int main()
{
	int n,p;	cin>>n>>p;
	string s;	cin>>s;
	if(n==1 && p==1){cout<<"NO"<<endl;return 0;}
	memset(val,0,sizeof val);
	for(int i=0;i<n;i++)
		val[i]=s[i]-'a';
	int pos=n-1;
	val[pos]++;
	while(1)
	{
		if(pos==0)
		{
			if(val[pos]>=p) {cout<<"NO"<<endl;return 0;}
			else {break;}
		}
		else if(val[pos]>=p)
		{
			val[pos]=0;
			pos--;
			val[pos]++;
		}
		else
		{
			if((pos>1 && val[pos]==val[pos-2]) || val[pos]==val[pos-1])	val[pos]++;
			else {break;}
		}
	}
	for(int i=pos+1;i<n;i++)
	{
		for(int j=0;j<p;j++)
		{
			if(i>0 && j==val[i-1])continue;
			else if(i>1 && j==val[i-2])continue;
			else {val[i]=j;break;}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%c",'a'+val[i]);
	}
	return 0;
}
