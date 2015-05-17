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

int stoi(string s)
{
	int ret=0;
	for(int i=0;i<s.length();i++)
	{
		ret*=10;
		ret+=s[i]-'0';
	}
	return ret;
}

int main()
{
	string sn,sm;	cin>>sn>>sm;
	int n=stoi(sn),m=stoi(sm),t=0;
	//cout<<n<<" "<<m<<endl;
	int cnt[10]={0}; //0-9;
	while(n)
	{
		cnt[n%10]++;
		n/=10;
	}
	for(int i=1;i<=9;i++)
	{
		if(cnt[i])
		{
			//cout<<i;
			t+=i;
			cnt[i]--;
			//cout<<t<<endl;
			break;
		}
	}
	for(int i=0;i<=9;i++)
	{
		while(cnt[i])
		{
			//cout<<i;
			t*=10;
			t+=i;
			cnt[i]--;
			//cout<<t<<endl;
		}
	}
	//cout<<t<<" "<<m<<endl;
	if(sn.length()!=sm.length())cout<<"WRONG_ANSWER";
	else if(t==m)cout<<"OK";
	else cout<<"WRONG_ANSWER";
	return 0;
}
