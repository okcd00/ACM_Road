#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	char c;
	int now = 0;
	//freopen("in.txt","r",stdin);
	while(1)	
	{
		if(scanf("%c",&c)==EOF)break;
		if(isdigit(c))
		{
			now=now*10 + (c-'0');
			now=now%4;
		}
		else break;
	}
	if(!now)cout<<"4";
	else cout<<"0";
	return 0;
}
