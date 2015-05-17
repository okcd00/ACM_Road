#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <memory>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 10086
using namespace std;
int hash[MAXN];
int main()
{
	int T;	cin>>T;
	for(int tcnt=1;tcnt<=T;tcnt++)
	{
		int n;	cin>>n;
		bool flag=false;
		memset(hash,0,sizeof hash);
		int j=n;	while(j--)
        {
        	int t;	cin>>t;
        	hash[t]=1;//the end mark
        	for(int i=1; !flag && (i<t) && t+i<=n ;i++)
           	if(hash[t-i]+hash[t+i]==1)		flag=true;
    	}    
		puts(flag?"Y":"N");
	}
	return 0;
}

