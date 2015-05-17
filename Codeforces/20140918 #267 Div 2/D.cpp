#include <map>
#include <cmath> 
#include <queue>
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<string,int> psi;
typedef pair<psi,psi> pss;
typedef map<psi,psi> mss;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define MP(a,b) make_pair(a,b)

bool cmp(const int a, const int b)
{
	return a > b;
}

mss m;
queue<psi> q;

int main()
{
	ios::sync_with_stdio(false);
	int n;	cin>>n;
	int cntR=0,cntl=0;
	m.clear();
	while(!q.empty())q.pop();
	string s,s1,s2;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		int cr=0;
		for(int i=0;i<s.length();i++) 
		{
			s[i]=tolower(s[i]);
			if (s[i]=='r') cr++;
		}
		//cout<<s<<cr<<endl;
		q.push(MP(s,cr));
	}
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s1>>s2;
		int cr1=0;
		for(int i=0;i<s1.length();i++)
		{
			s1[i]=tolower(s1[i]);
			if (s1[i]=='r') cr1++;
		}
		int cr2=0;
		for(int i=0;i<s2.length();i++)
		{
			s2[i]=tolower(s2[i]);
			if (s2[i]=='r') cr2++;
		}
		psi t(s1,cr1),tt(s2,cr2);
		//cout<<s1<<cr1<<s2<<cr2<<endl;
		if(m.count(t)) 
		{
			int msec=m[t].second;
			if(cr2<msec) m[t]=tt;
			else if(cr2==msec && s2.length()<m[t].first.length()) m[t]=tt;
			else;	
		}
		else m.insert(pss(MP(s1,cr1),MP(s2,cr2)));
	}
	while(!q.empty())
	{
		psi tmp=q.front();
		q.pop();
		if(m.count(tmp))
		{
			int cntr1 =tmp.second;
			int cntr2 =m[tmp].second;
			int len1  =tmp.first.length();
			int len2  =m[tmp].first.length();
			
			if(cntr2<cntr1) cntR+=cntr2,cntl+=len2;
			else if(cntr2==cntr1) cntR+=cntr2,cntl+=Min(len1,len2);
			else cntR+=cntr1,cntl+=len1; 
			//cout<<cntr1<<cntr2<<cntR<<endl;
			//cout<<len1<<len2<<cntl<<endl;
		}
		else
		{
			cntl+=tmp.first.length();
			cntR+=tmp.second;
		}
	}
	cout<<cntR<<" "<<cntl<<endl;
	return 0;
}
