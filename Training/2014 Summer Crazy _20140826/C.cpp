#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

long long sum;
const int Maxn=200010;
int i,a,b,n,q,p[Maxn],v[Maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(i=1;i<=n;i++) cin>>v[i];
	sort(v+1,v+n+1);
	for (i=1;i<=q;i++)
	{
		cin>>a>>b;
		p[a]++, p[b+1]--;
	}
	for (i=2;i<=n;i++) p[i]+=p[i-1];
	sort(p+1,p+n+1);
	for (i=1;i<=n;i++) sum+=(long long)p[i]*v[i];
	cout<<sum<<endl;
}
