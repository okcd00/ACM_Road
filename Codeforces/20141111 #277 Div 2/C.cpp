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
//(if i?=?n, the cursor appears at the beginning of the string)
//dead

int main()
{
	int n,p;	cin>>n>>p;	p--;
	p=min(p,n-p-1);
	string s;	cin>>s;
	//if(n==1){cout<<0;return 0;}
	int cnt=0,l=100086,r=0;
	//memset(chg,0,sizeof chg);
	for(int i=0;i<s.length()/2;i++)
	{
		//cout<<i<<endl; 
		if(s[i]==s[s.length()-1-i])continue;
		int dist=abs(s[i]-s[s.length()-1-i]);
		dist=min(dist,26-dist);
		cnt+=dist;
		//cout<<i<<":"<<cnt<<endl;
		l=min(l,i);
		r=max(r,i);
	}
	//cout<<cnt<<l<<r<<p;
	if(p<=l && p<=r){cout<<cnt+r-p;return 0;}
	else if(p>=l && p>=r){cout<<cnt+p-l;return 0;}
	//if(p<l && p>r)cout<<impossible;
	else if(p>=l && p<=r)
	{
		if(p-l<=r-p) cout<<cnt+p+r-l-l;
		else cout<<cnt+r+r-l-p;
	}
	return 0;
}
