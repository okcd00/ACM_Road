#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
//dichotomy
using namespace std;
typedef long long int_64;

int_64 h[100010],p[100010]; //harddrive, pointer
int n, m;

bool judge(int_64 t) //
{
	int cur = 1;
	int_64 final;
	for(int i=1;i<=n;i++){
        //especially,
		if(abs(p[cur]-h[i])>t) continue;
		
		if(p[cur]==h[i]) cur++;
		if(p[cur]< h[i]) final= max(h[i]+ t- 2 * (h[i] - p[cur]),
                                    h[i]+(t-(h[i] - p[cur]) ) /2);
		else final = h[i]+t;
		while(p[cur]<=final&&cur<=m) cur++;
	}
	return (cur>m);
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;i++) scanf("%I64d",&h[i]);
		for(int i=1;i<=m;i++) scanf("%I64d",&p[i]);
		int_64 l=0,r=abs(p[1]-h[1])*2+abs(p[m]-h[1]),mid;
		while(l<=r){
			mid = (l+r)>>1;
			if(judge(mid)) r=mid-1;
			else l=mid+1;
		}
		printf("%I64d\n",l);
	}
}
