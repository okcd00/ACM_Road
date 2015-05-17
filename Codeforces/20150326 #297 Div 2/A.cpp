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

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

map<char,int> mci;
int main()
{
	mci.clear();
	int n,ans=0; cin>>n;
	string s;	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(islower(s[i])) mci[s[i]]++;
		if(isupper(s[i])) 
		{
			if(mci[tolower(s[i])]==0) ans++;
			else mci[tolower(s[i])]--;
		}
		//cout<<i<<":"<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
