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
	string s,t; cin>>s>>t;
	int l=s.length()-1;
	while(s[l]=='z')
	{
		s[l]='a';
		l--;
	}
	s[l]=s[l]+1;
	if(s==t) cout<<"No such string";
	else cout<<s;
	return 0;
}
