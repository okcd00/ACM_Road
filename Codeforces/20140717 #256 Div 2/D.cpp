#include <cmath>   
#include <cstdio>  
#include <string>  
#include <cstring>  
#include <iostream>  
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e6 + 6;

ll f(ll x, int n, int m)//f: there are f() less than x in nxm blanks 
{
    ll res = 0;
    --x;
    for(int i=1;i<=n;++i) res+=min((ll)m, x/i);
    return res;
}

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll l=1, r=1LL*n*m+1, x; 
    while(l<r)				//binary 
	{
        x = (l+r)>>1;	
        if(f(x,n,m)<k) l=x+1; else r=x;
    }
    cout<<l-1<<endl;		
    return 0;
}
