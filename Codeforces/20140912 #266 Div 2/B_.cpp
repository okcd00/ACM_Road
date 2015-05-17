#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

ll n, a, b, s, x, y, t;

int main()
{
    cin>>n>>a>>b;
    n*=6;  s = -1;
    if(a*b>=n) 
	{
        s = a*b;
        x = a; y = b;
    }
    else 
	{
    	if(a<b) 
		{
			for(ll i=a; i*i<=n; i++) 
			{
        	    t = max(n%i==0?n/i:n/i+1,b);
        	    if(i*t<s||s<0) {x=i; y=t; s=x*y;}
        	}
    	}
    	else 
		{
        	for(ll i=b; i*i<=n; i++) 
			{
        	    t = max(n%i==0?n/i:n/i+1,a);
        	    if(t*i<s||s<0) {y=i; x=t; s=x*y;}
        	}
      	}	
    }
    cout<<s<<endl<<x<<' '<<y<<endl;
	return 0;
}
