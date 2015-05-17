#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int pos[8]={0};
string str[100086];
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	string now,last;
	int n=0;	cin>>n>>last;
	for(int i=0;i<last.length();i++)
	{
		if(i==0 && last[i]=='?')last[i]='1';
		else if(last[i]=='?')last[i]='0';
	}
	str[0]=last;
	for(int i=1;i<n;i++)
	{
		cin>>now;
		if(now.length()>last.length())
		{
			for(int i=0;i<now.length();i++)
			{
				if(i==0 && now[i]=='?')now[i]='1';
				else if(now[i]=='?')now[i]='0';
			}
		}
		else if(now.length()<last.length())
		{
			cout<<"NO"<<endl;
			return 0;
		}
		else
		{
			int vpos=0;
			memset(pos,0,sizeof pos);
			for(int j=0;j<now.length();j++)
			{
				if(now[j]=='?') pos[vpos++]=j;
				if(j==0 && now[j]=='?')	now[j]='0'+max(1,last[j]-'1');
				else if(now[j]=='?')
				{
					now[j]='0'+max(0,last[j]-'1');
				}
			}
			if(vpos==0 && now>last){str[i]=last=now;continue;}
			else if(vpos==0 && now<=last) {cout<<"NO"<<endl;return 0;}
			while(1)
			{
				if(now>last)break;
				//if(now[pos[0]]=='0'){cout<<"NO"<<endl;return 0;}
				// ***
				if(now[pos[vpos-1]]=='9')
				{
					now[pos[vpos-1]]='0';
					for(int k=vpos-2;k>=0;k--)
					{
						if(k==0 && now[pos[k]]=='9'){cout<<"NO"<<endl;return 0;}
						else if(k!=0 && now[pos[k]]=='9') now[pos[k]]='0';
						else 
						{
							now[pos[k]]++;
							break;
						}
					}
				}
				else now[pos[vpos-1]]++;
				
			}
			
		}
		str[i]=last=now;
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++)
		cout<<str[i]<<endl; 
	return 0;
}
