#include <stack>
#include <queue>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int anscnt=0;

int sums(string s)
{
	anscnt++;
	int cnt=0;
	for(int i=0;i<s.length();i++)
	{
		cnt+= s[i]-'0';
	}
	return cnt;
}

int onedigit (int x)
{
	if(x/10==0) return x;
	else 
	{
		anscnt++;
		int xnxt=0,xtmp=x;
		while(xtmp)
		{
			xnxt+= xtmp%10;
			xtmp/= 10;
		}
		return onedigit(xnxt);
	}
}

int main()
{
	string s; cin>>s;
	if(s.length()!=1)
	{
		int x=sums(s);
		int ans=onedigit(x);
	}
	cout<<anscnt;
	return 0;
} 
