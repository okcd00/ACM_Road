#include <stack>
#include <queue>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

bool islucky(int n)
{
	while(n)
	{
		int t=n%10;
		if(t==4 || t==7) n/=10;
		else return false;
	}
	return true;
}

int main()
{
	int num=0;
	string s; cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='4'||s[i]=='7')num++;
	}
	//cout<<num<<endl;
	if(!num)cout<<"NO"<<endl;
	else cout<< (islucky(num)?"YES" :"NO") <<endl;
	return 0;
} 
