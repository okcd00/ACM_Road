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
	string s;	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		int now=s[i]-'0';
		if(i==0 && (now==0 || now==9)) cout<<9;
		else cout<<Min(now,9-now);
	}
	return 0;
}
