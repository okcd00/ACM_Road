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

int cntl[26]={0},cntu[26]={0};	//cnt
int nedl[26]={0},nedu[26]={0};	//need

int main()
{
	int yay=0,whoops=0;
	string s,t; cin>>s>>t;
	for(int i=0;i<s.length();i++)
	{
		if(isupper(s[i])) nedu[s[i]-'A']++;
		else nedl[s[i]-'a']++;
	}
	for(int i=0;i<t.length();i++)
	{
		if(isupper(t[i])) cntu[t[i]-'A']++;
		else cntl[t[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		if(nedl[i]!=0 && cntl[i]!=0)
		{
			int p=min(nedl[i],cntl[i]);
			nedl[i]-=p,cntl[i]-=p,yay+=p;
		}
		if(nedu[i]!=0 && cntu[i]!=0)
		{
			int p=min(nedu[i],cntu[i]);
			nedu[i]-=p,cntu[i]-=p,yay+=p;
		}
	}
	for(int i=0;i<26;i++)
	{
		if(nedl[i]!=0 && cntu[i]!=0)
		{
			int p=min(nedl[i],cntu[i]);
			nedl[i]-=p,cntu[i]-=p,whoops+=p;
		}
		if(nedu[i]!=0 && cntl[i]!=0)
		{
			int p=min(nedu[i],cntl[i]);
			nedu[i]-=p,cntl[i]-=p,whoops+=p;
		}
	}
	cout<<yay<<' '<<whoops<<endl;
	return 0;
}
