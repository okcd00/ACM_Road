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

int dist[2048]={0};
int ans[2048]={0};

int main()
{
	string s,p;
	cin>>s>>p;
	bool in=false;
	int rest=s.length();
	int maxcnt=0,pos=0,now=0,pass=0;
	for(int i=0;i<s.length();i++)
	{
		if(in) pass++;
		if(s[i]==p[pos])
		{
			pos++;
			if(!in) in=true,pass++;
			if(p.length()==1)
			{
				pos=0;
				//cout<<pass<<endl;
				ans[0]++;
				rest-=pass;
				pass=0;
				maxcnt++;
				in=false;
			}
			else if(pos>=p.length())
			{
				pos=0;
				//cout<<pass<<endl;
				if(pass==2) ans[0]++;
				else dist[now++]=pass-2;
				rest-=pass;
				pass=0;
				maxcnt++;
				in=false;
			}
		}
		//cout<<ans[0]<<" ";
	}
	//for(int i=0;i<now;i++) cout<<dist[i]<<" ";
	//cout<<endl;
	sort(dist,dist+now);
	int wcp=0;//which char in p
	int pst=0,psp=0;//present beginning,present pointer in dist
	for(int i=1;i<=s.length();i++)
	{
		if(psp<now)
		{
			if(i-pst<dist[psp]) ans[i]=ans[i-1];
			else
			{
				ans[i]=ans[i-1]+1;
				pst=i;
				psp++;
			}
			//cout<<psp<<":"<<now<<endl;
		}
		else if(rest>0)
		{
			rest--;
			ans[i]=ans[i-1];
		}
		else
		{
			if(wcp==0) ans[i]=ans[i-1]-1;
			else if(wcp<p.length()) ans[i]=ans[i-1];
			wcp++;
			if(wcp==p.length()) wcp=0;
		}
	}
	printf("%d",ans[0]);
	for(int i=1;i<=s.length();i++) printf(" %d",ans[i]);
	return 0;
}
