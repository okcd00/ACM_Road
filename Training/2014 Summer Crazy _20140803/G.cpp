#include <iostream>
using namespace std;
typedef long long ll;
ll solve(ll n)
{
	if(n%2) return (n>>1)*((n>>1)+1);
	return (n>>1)*(n>>1);
}

int main()
{
	ll w,h;	cin>>w>>h;
	cout<<solve(w)*solve(h)<<endl;
	return 0;
}
