#include <iostream>
#include <algorithm>
using namespace std;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int main()
{
	int n;	cin>>n;
	if(n%2==0)cout<<4<<" "<<n-4<<endl;
	else cout<<9<<" "<<n-9<<endl;
	return 0;
}
