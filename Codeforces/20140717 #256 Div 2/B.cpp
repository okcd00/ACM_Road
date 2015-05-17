#include <cmath>   
#include <vector>  
#include <cctype>  
#include <cstdio>  
#include <string>  
#include <cstdlib>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
using namespace std;
int mark[26];

int main()
{	
	memset(mark,0,sizeof mark);
	string s,t;
	cin>>s>>t;
	if(s.length()==t.length())
	{
		for(int i=0;i<s.length();i++)
		{
			mark[s[i]-'a']++;
			mark[t[i]-'a']--;
		}
		
		int flag=0;
		for(int i=0;i<26;i++)
		{
			if(mark[i]!=0) flag=1;
		}
		
		if(flag==0)
		{
			puts("array");
			return 0;
		}
		else
		{
			puts("need tree");
			return 0;
		}
	}
	else if(s.length()<t.length())
	{
		puts("need tree");
		return 0;
	}
	else
	{
		int pos=0,flag=0;
		for(int i=0;i<t.length();i++)
		{
			while(s[pos]!=t[i])
			{
				pos++;
				if(pos>=s.length()) 
				{
					flag=1;
					break;
				}
			}
			pos++;
			if(flag==1)break;
		}
		if(flag==0)
		{
			puts("automaton");
			return 0;
		}
		else
		{
			for(int i=0;i<s.length();i++)
			{
				mark[s[i]-'a']++;
			}
			for(int i=0;i<t.length();i++)
			{
				mark[t[i]-'a']--;
			}
			for(int i=0;i<26;i++)
			{
				if(mark[i]<0)
				{
					puts("need tree");
					return 0;
				}
			}
			puts("both");
			return 0;
		}
	}
	return 0;
}
