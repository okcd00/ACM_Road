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

string s[100];
int ss[100],a[100];

bool f(int a,int b){ return a>b; }

int main()
{
	int n,m,c;	cin>>n>>m;
	int s1=0,s2=0,t=0;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++)
	{
		c=0;
		string stmp;	cin>>stmp;
		for (int j=0;j<t;j++) if (stmp==s[j])
		{
			ss[j]++, c=1;
			break;
		}
		if (!c){s[t]=stmp;ss[t++]++;}
	}
	sort(ss,ss+t,f);
	
	sort(a,a+n);
	for (int i=0;i<t;i++) s1+=a[i]*ss[i];
	cout<<s1;
	
	sort(a,a+n,f);
	for (int i=0;i<t;i++) s2+=a[i]*ss[i];
	cout<<' '<<s2<< endl;
	
	return 0;
}
