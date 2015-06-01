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
    freopen("A.in","r",stdin);
    int T; scanf("%d",&T);
    int a[1111];
    for(int _T=0;_T<T;_T++)
    {
        int balance=0;
        memset(a,0,sizeof a);
        int n;  scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]%2==1) balance++;
            else balance--;
        }
        if(balance==0) printf("B\n");
        else printf("U\n");
    }
    return 0;
}
