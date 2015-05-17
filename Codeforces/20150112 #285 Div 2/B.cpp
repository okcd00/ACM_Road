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
typedef map<string, string> mss;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	int n=0;	cin>>n;
	mss mp;
	while(!mp.empty()) mp.clear();
	for(int i=0;i<n;i++)
	{
		int flag=1;
		string a,b;		cin>>a>>b;
		for (map<string,string>::iterator it=mp.begin(); it!=mp.end(); ++it)
		{
			if(it->second==a)
			{
				mp[it->first]=b;
				flag=0;
				break;
			}
		}
		if(flag) mp[a]=b;
	}
	cout<<mp.size()<<endl;
	for (map<string,string>::iterator it=mp.begin(); it!=mp.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}

