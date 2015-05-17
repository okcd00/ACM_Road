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
	string s,ans,st="*";	cin>>s;
	int len=s.length();
	for(int i=0;i<=len;i++)
	{
		bool f=true;
		ans=s.substr(0,i)+st+s.substr(i,len-i);
		for(int j=0;j<=ans.length()/2;j++)
		{
			if(ans[j]==ans[ans.length()-1-j]) continue;
			else if(ans[j]=='*') {ans[j]=ans[ans.length()-1-j];continue;}
			else if(ans[ans.length()-1-j]=='*') {ans[ans.length()-1-j]=ans[j];continue;}
			else
			{
				f=false;
				break;
			}
		} 
		if(f) {cout<<ans;return 0;} 
	} 
	cout<< "NA";
	return 0;
}
