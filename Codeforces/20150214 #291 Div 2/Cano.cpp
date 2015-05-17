#include <map>
#include <cmath> 
#include <queue>
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
map<string,int> mp;
int lenr[333333]={0};
string s,qry;

int main()
{
	int n,m;	cin>>n>>m;
	mp.clear();
	for(int i=0;i<n;i++)
	{
		cin>>s;
		mp[s]=s.length();
	}
	for(int i=0;i<m;i++)
	{
		cin>>s;
		int reverse=strcmp(s,dic[j])
	}
}
