#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

struct testBag
{
	ll r;
	ll e;
	ll l;
}test[100086];

int cmp(const void *_a, const coid *_b)
{
	struct testBag *a = (testBag *)_a;
	struct testBag *b = (testBag *)_b;
	return a->e - b->e;
}

int main()
{
	int T;	cin>>T;
	for(int _T=1;_T<=T;_T++)
	{
		int n=0;
		scanf("%d",&n);
		ll last=0, rest=0;
		int flag=1;	//can pass;
		for(int i=0;i<n;i++)
		{
			scanf("%lld%lld%lld",&test[i].r,&test[i].e,&test[i].l);
		}	qsort(test,n,sizeof(test[0]),cmp);
		for(int i=0;i<n;i++)
		{
			ll r,e,l;	//review,exam,last
			r=test[i].r;
			e=test[i].e;
			l=test[i].l;
			if(flag!=1) continue;
			rest += (e-last);
			if(rest<r) flag=0;
			else
			{
				rest-=r;
				last=e+l;
			}
		}
		printf("Case #%d: ",_T);
		if(flag==1) printf("YES\n");
		else printf("NO\n);
	}
	return 0;
}
