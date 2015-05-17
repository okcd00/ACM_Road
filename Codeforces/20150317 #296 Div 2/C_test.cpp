#include <cmath> 
#include <vector> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define maxt 200000<<2
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<n; ++i)
#define repD(i,n) for (int i=n-1; i>=0; --i)

struct Node{
	ll sz;
	Node(){sz=0;}
}; 

Node operator+(Node &l,Node &r)
{
	Node t;
	if(l.sz==-1){t=r;return t;}
	if(r.sz==-1){t=r;return l;}
	t.sz=l.sz+r.sz;
	return t;
}

struct SegTree{
	int h;
	Node a[maxt];
	void init(int n)
	{
		for(h=1;(i<<h)<n+2;++h);
		rep(i,n) a[i+(1<<h)+1].sz=1;
		repD(i,(1<<h))ref(i);
	}
	void relax(int x){
		int y=x<<1,z=(x<<1)+1;
	}
	void ref(int x){a[x]=a[x<<1]+a[(x<<1)+1];}
	void pass_down(int x){repD(i,h) relax(x>>(i+1));}
	void upd(int x){for (x>>=1;x;x>>=1) ref(x);}
	void add(int x,int y,ll k)
	{
		int l=x+(1<<h)-1,r=y+(1<<h)+1;
		pass_down(l),pass_down(r);
		l=x+(1<<h)-1,r=y+(1<<h)+1;
		upd(l),upd(r);
	}
	Node query(int l,int r){
		l+=(1<<h)-1,r+=(1<<h)+1;
		pass_down(l),pass_down(r);
		Node L,R;L.sz=R.sz=-1;
		while(l+1<r){
			if(!(l&1))L=L+a[l^1];
			if(r&1) R=a[r^1]+R;
			l>>=1,r>>=1;
		}
		return L+R;
	}
}tr_w,tr_h;

int main()
{
	ll w,h,n,maxw=-1,maxh=-1;	cin>>w>>h>>n;
	tr_w.init(); tr_h.init();
	for(int i=0;i<n;i++)
	{
		string s;
		ll c=0;
		cin>>s>>c;
		if(s[0]=='H')
		{
			
		}
		else
		{
			
		}
		cout<<(ll)tr_w.query(0,n)*(ll)tr_h.query(0,n)<<endl; 
	}
	return 0;
}
