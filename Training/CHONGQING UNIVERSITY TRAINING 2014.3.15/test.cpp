#include<iostream>
#include"LList.h"
using namespace std;
int main()
{
    LList<int> cycle;
    int n,m,i,count=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
         cycle.append(i);
     }
    cycle.moveToStart();
    for(i=1;;i++)
    {
         if(i==m){int it=cycle.remove();cout<<it<<endl;count++}
         cycle.next();
         if(count==n)break;
              
    }
    return 0;
}
