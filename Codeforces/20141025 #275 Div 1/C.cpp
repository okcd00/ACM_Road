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

int usd[51]={0};
bool usdl[51][26]={false};//[0~n-1][a-z]
bool usdu[51][26]={false};//[0~n-1][A-Z]
string str[51];

int main()
{
	int n;	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
		for(int j=0;j<str[j].length();j++)
		{
			char now=str[i][j];
			if(islower(now) && usdl[i][now-'a']==false) usdl[i][now-'a']=true,usd[i]++;
			else if(isupper(now) && usdu[i][now-'A']==false) usdu[i][now-'A']==true,usd[i]++;
		}
	}
	
	
	
	
	
	return 0;
}
