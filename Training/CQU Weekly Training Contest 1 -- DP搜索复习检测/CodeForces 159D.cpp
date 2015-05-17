#include <cstdio>
#include <string>
#include <cstring> 
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

char a[2005];
ll dps[2005],dpe[2005];
int main()
{
    while(scanf("%s",&a)!=EOF)
    {
        int len=strlen(a);
        for(int i=0;i<=len;i++) dps[i]=dpe[i]=1;
        for(int now=0;now<=1;now++)
        {
			for(int i=now;i<len;i++)
        	{
            	for(int j=now;j<(len/2+1);j++)
            	{
            	    if((i-j)<0||(i+j+1-now)>=len) break;
            	    if(a[i-j]==a[i+1+j-now])
            	    {
            	        dps[i-j]++;
            	        dpe[i+j+1-now]++;
            	    }
            	    else break;
            	}
        	}
    	}
        ll ans=0;
        for(int i=0;i<len;i++)
        {
            ll sum=0;
            for(int j=i+1;j<len;j++)
            sum+=dps[j];
            ans+=sum*dpe[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
