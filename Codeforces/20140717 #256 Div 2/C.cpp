#include <cmath>   
#include <cstdio>  
#include <string>  
#include <cstring>  
#include <iostream>  
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 5005
int a[N];
int n;

int solve(int l,int r){
  int ans=r-l+1;
  int m=a[l],i,j;
  if (l>r) return 0;						//stop
  for (i=l+1;i<=r;++i) m=min(m,a[i]);		//find m=min
  for (i=l;i<=r;++i) a[i]-=m;				//All decrease m
  for (j=l;j<=r;++j) if (a[j]!=0) break;	//find first segment's left
  for (i=j;i<=r;++i) if (a[i]==0)			//find first segment's right
					{
      					m+=solve(j,i-1);	//solve it
      					if (m>ans) return ans;//specially,if reach the end
      					else j=i+1;			//go ahead to next segment
    				}
  if (j<=r) m+=solve(j,r);					//reach the r:right
  return min(m,ans);						//m can not beyond ans
}

int main()
{
  int i,j;
  cin>>n; 
  for (i=0;i<n;++i) cin>>a[i];
  cout<<solve(0,n-1);
  return 0;
}
