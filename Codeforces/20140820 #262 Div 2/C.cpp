#include <cmath> 
#include <queue>
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define TEST while(!pq.empty()){cout<<pq.top().pos<<'\t'<<sum[pq.top().pos]<<endl;pq.pop();}

int a[100086];
long long sum[100086];

struct node
{
    friend bool operator< (const node &n1,const node &n2)
    {
        return sum[n1.pos] > sum[n2.pos];
    }
    int pos;
    //long long sum;
};

priority_queue <node> pq;  

int main()
{
	int n,m,w,_min=(int)1e9+1;	cin>>n>>m>>w;
	memset(a,0,sizeof a);
	memset(sum,0,sizeof sum);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=Max(i-w+1,0);j<=i;j++) sum[j]+=a[i];
		if(i<=n-w)
		{
			node temp;
			temp.pos=i;
			pq.push(temp);
		}
		if(a[i]<_min) _min=a[i];
	}
	if(w==n){cout<< (_min+m) <<endl;return 0;}
	for(int i=1;i<=m;i++)
	{
		node head=pq.top(); pq.pop();
		int hpos=head.pos;
		for(int j=hpos;j<hpos+w;j++) a[j]++;
		for(int j=Max(hpos-w+1,0);j<=Min(hpos+w-1,n-1);j++) sum[j]+=abs(hpos-j);
		pq.push(head);
	}
	TEST
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	return 0;
}
