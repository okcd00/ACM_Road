#include <iostream>
using namespace std;
long long n,lst,bst,ttl,ar[200000];	

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>lst;
	for (int i=1; i<=n; i++)	cin>>ar[i];	bst=ar[1];
	for (int i=1; i<=n; i++)	bst=min( bst, ar[i] );
	if (bst>5)	for (int i=1; i<=n; i++){ ar[i]-=bst-3; ttl+=bst-3; }
	while (ar[lst])	{
		--ar[lst]; --lst; ++ttl;
		if (lst==0)	lst=n;
	}	ar[lst]=ttl;
	for (int i=1; i<=n; i++) {
    	if(i!=1) cout<<" ";
    	cout<<ar[i];
	}	return 0;
}
