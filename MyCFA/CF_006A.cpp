#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
//http://blog.csdn.net/okcd00/article/details/22694925
int main()
{
	int a[4];
	for(int i=0;i<4;i++) scanf("%d",&a[i]);
	sort(a,a+4);
	if( a[0]+a[1]<a[2] && a[0]+a[2]<a[3] && a[1]+a[2]<a[3] )printf("IMPOSSIBLE");  
    else if( a[0]+a[1]>a[2] || a[0]+a[2]>a[3] || a[1]+a[2]>a[3] )printf("TRIANGLE");  
    else printf("SEGMENT"); 
	return 0;
}
