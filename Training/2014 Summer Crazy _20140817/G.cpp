#include<map>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
map<string,int> m;

int main()
{
	bool flag;
	string s,str="XX-XX-XXXX";	cin>>s;
	for(int i=0;i<s.length()-str.length()+1;i++)
	{
		str=s.substr(i,10),flag=true;
		for(int ii=0;ii<=9;ii++) { if(ii!=2 && ii!=5 && !isdigit(str[ii])) flag=false;}
		if(str[2]=='-' && str[5]=='-' && flag==true)
		{
			int year=str[6]-'0';
			year=year*10+(str[7]-'0');
			year=year*10+(str[8]-'0');
			year=year*10+(str[9]-'0');
			if(2013>year || year>2015) continue;
			int month=str[3]-'0';
			month=month*10+(str[4]-'0');
			if(1>month || month>12) continue;
			int day=str[0]-'0';
			day=day*10+(str[1]-'0');
			if(1>day || day>days[month])continue;
			if(m.find(str)->second > 0) {m[str]++;}
			else m.insert(make_pair(str,1));
		}
	}
	map<string,int>::iterator mit=m.begin();
	for(map<string,int>::iterator it=m.begin();it!=m.end();++it)
	if(it->second > mit->second) mit=it;
	cout<<mit->first;
    return 0;
}
