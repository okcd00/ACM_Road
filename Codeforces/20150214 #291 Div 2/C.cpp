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
		memset(next,NULL,sizeof next);
		suffix=NULL;
	}
};

int qlen;
Trie *qcur;
string qstr;

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
			nn->flag=1;
            cur->next[id]=nn;
		}
		cur=cur->next[id];
	}
	cur->flag=2;
}

bool bfs(int level, int change)
{
	if(level>=qlen) return false;
	int id=qstr[level]-'a';
	Trie* tcur=qcur->next[id];
	//cout<<"now is level "<<level<<" change is "<<change<<" tcur->flag is "<<tcur->flag<<endl;
	if(tcur->flag==2)
	{
		qcur=tcur->next[id];
		if(change==0 && level==qlen-1) return true;
		else if(level==qlen) return false;
		else return bfs(level+1,change);
	} 
	else if(tcur->flag==1) 
	{
		qcur=tcur->next[id];
		if(level!=qlen) return bfs(level+1,change);	
		else return false;
	}
	else 
	{
		if(change==0)return false;
		bool ansf=false;
		for(int i=0;i<3;i++)
		{
			if(i==id)continue;
			qcur=tcur->next[i];
			bool bnow = bfs(level+1,0);
			//cout<<"bnow is "<<bnow<<endl;
			ansf= ansf||bnow;
		}
		//cout<<"ansf is "<<ansf<<endl; 
		return ansf;
	}
}

int main()
{
	int n;	cin>>n;
	int qnum=0;	cin>>qnum;
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
	
	while(qnum--)
	{
		cin>>qstr;
		qlen=qstr.length();
		qcur=root;
		bool ansb=bfs(0,1);
		if(ansb) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
