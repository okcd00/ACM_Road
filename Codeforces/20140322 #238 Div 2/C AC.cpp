#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
//偷懒得笑死我自己了…… 
    int val[1001][1001];
    int n;
  /*  
int valunusl()
{
    int ans = 0;
    for(int i=0;i<n;i++)
    if(val[i][i]==1) ans++;
    
    return ans%2;
}
   */
int main()
{
    int vali=0,n=0,q=0,tmp,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
            scanf("%d",&val[i][j]); //O(n2)
            if(i==j)ans=(ans+val[i][j])%2;
    }
    
    cin>>q;
    for(int k=1;k<=q;k++)//O(q)
    {
            scanf("%d",&tmp);
            if(tmp==1){
                       scanf("%d",&vali);
                       //for(int i=0;i<n;i++)  val[vali-1][i]=(val[vali-1][i]+1)%2;
                       ans=(ans+1)%2;
                       }
            else if(tmp==2){
                            scanf("%d",&vali);
                            //for(int i=0;i<n;i++) val[i][vali-1]=(val[i][vali-1]+1)%2;
                            ans=(ans+1)%2;
                            }
            else if(tmp==3){
                            //cout<<valunusl();
                            printf("%d",ans);
                            }
            
    }
    
    return 0;
}
//TLE了一次，估计是cincout太慢…… 
