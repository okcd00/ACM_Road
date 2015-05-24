#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const string codec = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int trans(string s)
{
	int ret=0;
	for(int i=0;i<s.length();i++)
	{
		ret=ret<<8;
		int t=(int)s[i];
		ret+=t;
	}
	return ret;
}

string Base64(string str, int k)
{
	if(k==0) return str;
	int i=0,vplus=str.length()%3,zero=0;
	if(vplus) for(int v=0;v<3-vplus;v++) str+=(char)zero;
	string ret="";
	for(i=0; i+3<=str.length(); i+=3)
	{
		int t=trans(str.substr(i,3));
		string tmp="";
		for(int j=0;j<4;j++)
		{
			int code=t%(1<<6);
			t/=(1<<6);
			tmp=codec[code]+tmp;
		}
		ret+=tmp;
	}
	if(vplus==0) return Base64(ret,k-1);
	else if(vplus==1) return Base64(ret.substr(0,ret.length()-2)+"==",k-1);
	else return Base64(ret,substr(0,ret.length()-1+"=",k-1);
}

int main()
{
	int T=0;	cin>>T;
	for(int _T=1;_T<=T;_T++)
	{
		int k;
		string str;
		scanf("%d",&k);
		getchar();
		getline(cin,str);
		cout<<"Case #"<<_T<<": "<<Base64(str,k)<<endl;
	}
	return 0;
}
