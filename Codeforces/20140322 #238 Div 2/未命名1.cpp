#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

    int val[1001][1001];
    int n;
    
int valunusl()
{
    int ans = 0;
    for(int i=0;i<n;i++)
    if(val[i][i]==1) ans++;
    
    return ans%2;
}

int main()
{
    int vali=0,n=0,q=0,tmp;
    cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)cin>>val[i][j];
    cin>>q;
    for(int k=1;k<=q;k++)
    {
            cin>>tmp;
            if(tmp==1){
                       cin>>vali;
                       for(int i=0;i<n;i++)  val[vali-1][i]=(val[vali-1][i]+1)%2;
                       }
            else if(tmp==2){
                            cin>>vali;
                            for(int i=0;i<n;i++) val[i][vali-1]=(val[i][vali-1]+1)%2;
                            }
            else if(tmp==3){cout<<valunusl();}
            
    }
    
    return 0;
}
