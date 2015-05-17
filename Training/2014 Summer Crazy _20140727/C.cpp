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
typedef pair<int,int> pii;
priority_queue <pii> pq;
int n,k,kind=0,wcnt[26],mrk[26];
pii chr[26];
string s;

void init()
{
	memset(wcnt,0,sizeof wcnt);
	memset(mrk,0,sizeof mrk);
	memset(chr,0,sizeof chr);
	for(int i=0;i<n;i++)
	{
		if(wcnt[s[i]-'a']==0)kind++;
		wcnt[s[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		pq.push(make_pair(wcnt[i],i));
	}
}

void print()
{
	cout<<kind<<endl;
	for(int i=0;i<n;i++)
	{
		if(wcnt[s[i]-'a']!=0) 
		{
			cout<< s[i];
			wcnt[s[i]-'a']--;
		}
	}
}

void solve()
{

		for(int i=0;i<26;i++)
		{
			chr[i]=pq.top();
			pq.pop();
			//cout<<chr[i].first<<" "<<chr[i].second<<endl;
		}
	
	for(int i=25;i>=0;i--)
	{
		int numb=chr[i].first;
		if(numb==0)continue;
		if(k-numb<0)break;
		else
		{
			//cout<<"del:"<<chr[i].first<<endl;
			k-=numb;
			chr[i].first=0;
			wcnt[chr[i].second]=0;
			kind--;
		}
	}
}

void test()
{
	cout<<"---------------------"<<endl;
	for(int i=0;i<26;i++)
	{
		cout<<chr[i].first<<"\t"<<chr[i].second<<endl;
	}
}

int main()
{
	cin>>s; n=s.length();
	cin>>k;	init();
	//cout<<n<<endl;
	if(k>=n)
	{
		cout<<"0"<<endl;
		return 0;
	}
	else if(k==0)
	{
		cout<<kind<<endl;
		cout<<s;
		return 0;
	}
	solve();
	print();
	return 0;
} 
