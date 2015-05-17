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
string tin,fst,snd;
//char suit[4]={'S','H','D','C'}; 
//char rank[9]={'6','7','8','9','T','J','Q','K','A'};

int main()
{
	string s,s1,s2;
	int i,pos1,pos2;
	char a[10]="6789TJQKA";
	cin>>s>>s1>>s2;
	if(s1[1]==s[0])
	{
		if(s2[1]==s[0])
		{
			for(i=0;i<9;i++)
			{
				if(s1[0]==a[i]) pos1=i;
				if(s2[0]==a[i])	pos2=i;
			}
			if(pos1<=pos2) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
		else cout<<"YES"<<endl;
	}
	else 
	{
		if(s1[1]==s2[1])
		{
			for(i=0;i<9;i++)
			{
				if(s1[0]==a[i])	pos1=i;
				if(s2[0]==a[i]) pos2=i;
			}
			if(pos1<=pos2) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
} 

