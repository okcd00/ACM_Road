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

int main()
{
	string str;	cin>>str;
	long long a,b;	cin>>a>>b;
	long long now=0,tmp=0;
	for(int i=0;i<str.length()-1;i++)
	{
		now=now*10+(str[i]-'0');
		now=(now%a+a)%a;
		if(now==0 && str[i+1]!='0')
		{
			for(int j=i+1;j<str.length();j++)
			{
				tmp=tmp*10+(str[j]-'0');
				tmp=(tmp%b+b)%b;
			}
			if(tmp==0)
			{
				cout<<"YES"<<endl<<str.substr(0,i+1)<<endl<<str.substr(i+1,str.length()-i)<<endl;
				return 0;
			}
			else tmp=0;
		}
	}
	cout<<"NO";
	return 0;
}
