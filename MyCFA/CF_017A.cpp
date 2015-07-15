#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
//Update Lower_bound() Solution on May 18th. 
//http://blog.csdn.net/okcd00/article/details/25230097
int Advanced[]={13,19,31,37,43,53,61,79,101,113,139,163,173,199,211,223,241,
269,277,331,353,373,397,457,463,509,521,541,577,601,619,631,727,773,787,811,
829,853,883,907,919,947,967,991,65536};  
//The last is limited_MaxValue, in order to solve cases of n>991 

int main()
{
	int n,k;
	int cnt1=0;
	scanf("%d%d",&n,&k);
	cnt1=lower_bound(Advanced,Advanced+45,n)-Advanced;
	printf(cnt1>=k?"Yes":"No");
	
//	int cnt=0;
//	for(int i=0;Advanced[i]<=n;i++) cnt++;	
//	printf(cnt>=k?"Yes":"No");
	return 0;
} 
