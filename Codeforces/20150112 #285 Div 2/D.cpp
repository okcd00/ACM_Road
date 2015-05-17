#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int anum[200086]={0};
int bnum[200086]={0};
int tnum[200086]={0};
int ans [200086]={0};
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define lson l, mid, root<<1
#define rson mid+1, r, root<<1|1
const int N = 200012;
struct node
{
    int l, r, sum;
} a[N<<2];

bool cmp(const int a, const int b)
{
	return a > b;
}

void PushUp(int root) //把当前节点的信息更新到父节点
{
    a[root].sum = a[root<<1].sum + a[root<<1|1].sum;
}

void build_tree(int l, int r, int root)
{
    a[root].l = l;
    a[root].r = r;
    if(l == r)
    {
        a[root].sum = 1; 
        return ;
    }
    int mid = (l + r) >> 1;
    build_tree(lson);
    build_tree(rson);
    PushUp(root);
}

void update(int l, int r, int root, int k)
{
    if(l == a[root].l && r == a[root].r)
    {
        a[root].sum += k;
        return ;
    }
    int mid = (a[root].l + a[root].r) >> 1;
    if(r <= mid) update(l, r, root<<1, k);
    else if(l > mid) update(l, r, root<<1|1, k);
    else
    {
        update(lson, k);
        update(rson, k);
    }
    PushUp(root);
}

int Query(int l, int r, int root)
{
    if(l == a[root].l && r == a[root].r)
        return a[root].sum;
    int mid = (a[root].l + a[root].r) >> 1;
    int ans = 0;
    if(r <= mid) ans += Query(l, r, root<<1);
    else if(l > mid) ans += Query(l, r, root<<1|1);
    else
        ans += Query(lson) + Query(rson);
    return ans;
}

int main()
{
	int n=0;	cin>>n;
	build_tree(1, n, 1); 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&anum[n-i]);	//n~1
		tnum[n-i-1]+=Query(1, n-i-1, 1);//比n-i-1小的有多少个
		a[n-i-1+n]=0;
	} 
	build_tree(1, n, 1); 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&bnum[n-i]);	//n~1 
		tnum[n-i-1]+=Query(1, n-i-1, 1);//比n-i-1小的有多少个
		a[n-i-1+n]=0;
	}
	
	return 0;
}

