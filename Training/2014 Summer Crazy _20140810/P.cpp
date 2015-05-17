#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,k,curr,ak=0;	cin>>n>>k;
    for(int i=0;i<n;i++)
	{
        scanf("%d", &curr);
        if (curr==0) {cout<<i; return 0;}
        if (k==(i+1)){ak=curr;}
        if (curr<ak) {cout<<i; return 0;}
    }
    cout<<n;    return 0;
}
