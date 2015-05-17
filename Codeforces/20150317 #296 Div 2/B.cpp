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
typedef pair<char,char> pcc;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

map <pcc,int> mpi;
map <char,int> mci,mcii;

int main()
{
	int flag=0,x=-1,y=-1;
	int n=0,cnt=0;	cin>>n;
	string s,t;	cin>>s>>t;
	mpi.clear(); mci.clear(); mcii.clear();
	for(int i=0;i<n;i++)
	{
		if(s[i]!=t[i])
		{
			cnt++;
			if(flag<2 && mpi[make_pair(t[i],s[i])]!=0) flag=2,x=mpi[make_pair(t[i],s[i])],y=i+1;
			mpi[make_pair(s[i],t[i])]=i+1;
			if(flag<1 && mci[s[i]]!=0) flag=1,x=mci[s[i]],y=i+1;
			mci[t[i]]=i+1;
			//why forget a half ,my god...
			if(flag<1 && mcii[t[i]]!=0) flag=1,x=mcii[t[i]],y=i+1;
			mcii[s[i]]=i+1;
		}
	}
	cout<<cnt-flag<<endl<<x<<' '<<y<<endl;
	return 0;
}
