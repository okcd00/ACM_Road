#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
	ll m, n, a;
	cin>>m>>n>>a;
	ll i=m/a; if(m%a)i++;
	ll j=n/a; if(n%a)j++;
	cout<<i*j<<endl;
	return 0;
}
