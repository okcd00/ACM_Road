#include <cstdio>
#include <algorithm>
using namespace std;

int main ()
{
    int n,d[105],s,t;

    scanf ("%d",&n);
    for (int i=0; i<n; i++)	scanf ("%d",&d[i]);

    scanf ("%d %d",&s,&t);
    s--,t--;

    int mn = min( s, t );
    int mx = max( s, t );
    int sum1 = 0;
    int sum2 = 0;

    for (int i=mn; i<mx; i++)	sum1 += d[i];
    for (int i=mx; i<n ; i++)	sum2 += d[i];
    for (int i=0 ; i<mn; i++)	sum2 += d[i];
    int ret = min( sum1, sum2 );
    printf ("%d\n",ret);
    
    return 0;
}
