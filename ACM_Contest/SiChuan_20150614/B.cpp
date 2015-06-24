#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll ans=0;
int a[100086], b[100086];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int tmp=1; ans=0;
        for(int i=0;i<9;i++)
        {
            tmp*=10;
            for(int j=0;j<n;j++) b[j]=a[j]%tmp;
            sort(b,b+n); int r=n;
            for(int j=0;j<n;j++)
            {
                while(r && b[j]+b[r-1]>=tmp) r--;
                if(r<=j) ans+=(n-r-1);
                else ans+=(n-r);
            }
        }
        printf("%lld\n",ans/2LL);
    }
    return 0;
}


