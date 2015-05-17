#include <set>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define i insert

char ch;
int n,w,h,t;
set<int> x,y,*s;
set<int>::iterator l,r;
multiset<int> lx,ly,*ls;

int main()
{
	cin>>w>>h>>n; x.i(0);x.i(w);y.i(0);y.i(h);lx.i(w);ly.i(h);
    for (int j=1; j<=n; ++j)
	{
		cin>>ch>>t;
        if (ch=='H') 
		{s=&y; ls=&ly;} 
		else 
		{s=&x; ls=&lx;}
		s->i(t); l=r=s->find(t); l--; r++; 
		ls->erase(ls->find(*r-*l));
		ls->i(t-*l);
		ls->i(*r-t);
		cout<<(ll)*lx.rbegin() * (ll)*ly.rbegin()<<endl;
	}
	return 0;
}
