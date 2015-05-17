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

string s;	
string ans;
int zf,digit,sub;
int tzf,td,ts,len; //temp zf,dig,sub
map<int,int> m;

void update(int pos)
{
	zf=tzf;
	digit=td;
	sub=ts;
	ans=s;
	char temp=ans[pos];
	ans[pos]=ans[len-1];
	ans[len-1]=temp;
}

int main()
{
	m.clear();
	cin>>s;
	len=s.length();
	int tail=s[len-1]-'0';
	for(int i=0;i<len;i++)
	{
		int num=s[i]-'0';
		if(num%2==0) m[i]=num;
	}
	if(m.empty())
	{
		cout<<-1;
		return 0;
	}
	zf=-1,digit=100001,sub=99;
	tzf=0,td=0,ts=0; //temp zf,dig,sub
	for (map<int,int>::iterator it=m.begin(); it!=m.end(); ++it)
	{
		//cout << it->first << " => " << it->second << '\n';
		int pos=it->first;
		int now=s[pos]-'0';
		tzf=1;
		ts=tail-now; //*9 ÂÔÈ¥ 
		td=s.length()-pos;
		if(ts<0){tzf=-1;ts=-ts;}
		
		if(tzf>zf) update(pos);
		else if(tzf==1 && zf==1)
		{
			if(td>digit) update(pos);
			else if(td==digit)
			{
				if(ts>sub) update(pos);
			}
		}
		else if(tzf==-1 && zf==-1)
		{
			if(td<digit) update(pos);
			else if(td==digit)
			{
				if(ts<sub) update(pos);
			}
		}
	}
	cout<<ans;
	return 0;
}
