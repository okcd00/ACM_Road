#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n=0,cnt=0,ans=0,flag=0,firstflag;//flag=-1 left,1 right
    scanf("%d",&n);
    char sta[3001];
    char huiche;
    scanf("%c",&huiche);
    for(int i=0;i<n;i++)    scanf("%c",&sta[i]);
    for(int i=0;i<n;i++)
    {
            if(flag==0)
            {
                        
                       if(sta[i]=='.')
                                      {
                                                cnt++;
                                                if(i==n-1) ans+=cnt;
                                                continue;
                                      }
                       if(sta[i]=='L')
                                      {    
                                           cnt=0;
                                           flag=-1;
                                      }
                       if(sta[i]=='R')
                                      {
                                           ans+=cnt;
                                           cnt=0;
                                           flag=1;
                                      }
            }
            else if(flag==-1)
            {
                        if(sta[i]=='.')
                                       {
                                           cnt++;
                                           if(i==n-1) ans+=cnt;    
                                           continue;
                                       }
                        if(sta[i]=='L')cnt=0;
                        if(sta[i]=='R')
                                       {
                                             ans+=cnt;
                                             cnt=0;
                                             flag=1;
                                       }
            }
            else if(flag==1)
            {
                       if(sta[i]=='.')cnt++;
                       if(sta[i]=='R')cnt=0;
                       if(sta[i]=='L')
                                      if(cnt%2==1)
                                                  {
                                                           ans++;
                                                           cnt=0;
                                                           flag=-1;
                                                  }
                                      else {
                                            cnt=0;
                                            flag=-1;
                                            }
            }
    }
    
    printf("%d",ans);
    return 0;
}
