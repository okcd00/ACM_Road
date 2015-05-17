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

typedef long long ll;

int main()
{
    ll n, k;
    int p;
    cin>>n>>k>>p;
    if (n&1)   n--, k--;
    for (int i=0; i<p; i++)
	{
        ll pos; cin>>pos;
        //enum start:
        if (pos%2==0 && (n/2-pos/2)+1 <= k) printf("X");
        else if ( ( pos==n+1 && k >= 0) )   printf("X");
		else if (pos&1 && n-(pos-1)/2 <= k) printf("X");
        else printf(".");
    }
    cout<<endl;
    return 0;
}
