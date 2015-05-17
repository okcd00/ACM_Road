#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
#define maxn 500010
typedef long long ll;
ll a[maxn], n, ls[maxn], rs[maxn], l[maxn], r[maxn], s;

int main()
{
	cin>>n; 
	for(int i=1; i<=n; i++) cin>>a[i], s+=a[i];
    if(s%3) 
	{
        cout<<0<<endl;
        return 0;
    }
    s/=3;
    for(int i=1; i<=n; i++) 
	{
        ls[i] = ls[i-1] + a[i];
        if(ls[i]==s) l[i] = l[i-1] + 1;
        else l[i] = l[i-1];
    }
    ll ans = 0;
    for(int i=n; i>0; i--) 
	{
        rs[i] = rs[i+1] + a[i];
        if(rs[i]==s&&i>2) ans += l[i-2];
    }
    cout<<ans<<endl;
	return 0;
}
