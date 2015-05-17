#include <cmath> 
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	char f,s;
	int flag=0;
	string a,b;	cin>>a>>b;
	if(a.length()!=b.length()) flag=-1;
	else
	{
		for(int i=0;i<a.length();i++)
		{
			if(a[i]!=b[i])
			{
				if(flag==0)
				{
					flag=1;
					f=a[i],s=b[i];
				}
				else if(flag==1)
				{
					if(f==b[i] && s==a[i]) flag=2;
					else break;
				} 
				else if(flag==2)
				{
					flag=3;
					break;
				}
			}
			//cout<<f<<"\t"<<s<<endl;
		}
	}
	if(flag==2) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
