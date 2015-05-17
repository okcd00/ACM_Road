#include<stdio.h>
#include<string.h>
typedef __int64 ll;
ll pre[5005],cur[5005],sum[5005],a[5005];
int n,m,k;

int main(void){
	int i,j;
	while(~scanf("%d%d%d",&n,&m,&k)){
		sum[0]=0;
		for(i=1;i<=n;i++){
			scanf("%I64d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		memset(pre,-1,sizeof(pre));
		for(i=m;i<=n;i++)
			pre[i]=cur[i]=sum[i]-sum[i-m];
		for(i=2;i<=k;i++){
			memset(cur,0,sizeof(cur));
			ll temp=0;
			for(j=m;j+m<=n;j++){
				if(pre[j]==-1) continue;
				if(pre[j]>temp) temp=pre[j];
				cur[j+m]=temp+sum[j+m]-sum[j];
			}
			memcpy(pre,cur,sizeof(pre));
		}
		ll ans=0;
		for(i=1;i<=n;i++) if(cur[i]>ans) ans=cur[i];
		printf("%I64d\n",ans);
	}
	return 0;
}