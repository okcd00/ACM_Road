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

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

struct Trie
{
	int flag;
	struct Trie *next[3];
	struct Trie *suffix;
	Trie()
	{
		flag=0;
		memset(next,NULL,sizeof(next));
		suffix=NULL;
	}
};

void build(Trie *root, string &s)
{
	Trie *cur=root;
	int len=s.length();
	for(int i=0;i<len;++i)
	{
		int id=s[i]-'a';
		if(!cur->next[id])
		{
			Trie *nn=new Trie();
            cur->next[id]=nn;
		}
		cur=cur->next[id];
	}
	cur->flag=1;
}


int main()
{
	int n;	cin>>n;
	string s;
	Trie *root=new Trie();
	while(n--)
	{
		cin>>s;
		build(root,s);
	}
	root->suffix=root;
	queue<Trie*> qt;
	for(int i=0;i<3;++i)
	{
		if(!root->next[i])
			root->next[i]=root;
		else
		{
			root->next[i]->suffix=root;
			qt.push(root->next[i]);
		}
	}
	
	Trie *cur, *suf;
	while(!qt.empty())
	{
		cur=qt.front();
		suf=cur->suffix;
		qt.pop();
		for(int i=0;i<3;++i)
		{
			if(!cur->next[i])
			{
				cur->next[i]=suf->next[i];
			}
			else
			{
				cur->next[i]->suffix=suf->next[i];
				qt.push(cur->next[i]);
			}
		}
	}
	
	int qnum=0;	cin>>qnum;
	while(qnum--)
	{
		cin>>s;
		int len=s.length(),flag=0;
		cur=root;
		for(int i=0;i<len;++i)
		{
			int id=s[i]-'a';
			cur=cur->next[id];
			if(cur->flag) 
			{
				cout<<"YES"<<endl;
				flag=1; break;
			}
		}
		if(!flag) cout<<"NO"<<endl;	
	}
	return 0;
}
