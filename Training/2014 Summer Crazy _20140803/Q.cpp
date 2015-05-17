#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,s[1002],ans=9999;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];    s[0]=s[1], s[n+1]=s[n];
    for(int i=0;i<=n;i++) ans=min(ans,max(s[i],s[i+1]));
    cout<<ans;
    return 0;
}
