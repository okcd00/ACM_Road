#include<iostream> 
#include<algorithm>
using namespace std;

long long n,k,c1,c2,ar[200000],p1,p2;

int main()
{	
	cin>>n>>k;
	for (int i=0;i<n;i++)    cin>>ar[i];
	sort(ar,ar+n); --k; p1=k/n;
	for (int i=0;i<n;i++)
	{
	    if (ar[i]<ar[p1])c1++;
	    if (ar[i]==ar[p1])c2++;
	}
	p2=k-n*c1;	p2/=c2;
	cout<<ar[p1]<<" "<<ar[p2]<<endl;
	return 0;
}
