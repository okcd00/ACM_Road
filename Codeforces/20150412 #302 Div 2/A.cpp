#include <map>
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

map<char,int> mci;

int main()
{
	int tk=0;
	string s;
	cin>>tk>>s;
	mci.clear();
	if(tk>s.length())
	{
		cout<<"NO"<<endl;
		return 0;
	}
	else 
	{
		int k=tk;
		for(int i=0;i<s.length();i++)
		{
			if(mci[s[i]]==0) mci[s[i]]=1,k--;
		} 
		if(k<=0)
		{
			cout<<"YES";
			for(int i=0;i<s.length();i++)
			{
				if(mci[s[i]]==0) printf("%c",s[i]);
				else
				{
					if(tk){printf("\n");tk--;}
					printf("%c",s[i]);
					mci[s[i]]=0;
				} 
			}
		} 
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
