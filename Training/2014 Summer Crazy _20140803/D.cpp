#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int S,a,b,c;    cin>>S>>a>>b>>c;
    if( a+b+c==0 ){ cout<<S<<" 0 0"; return 0;}
    	double x = double(a*S)/(a+b+c);
    	double y = double(b*S)/(a+b+c);
		double z = double(c*S)/(a+b+c);
    printf("%.18lf %.18lf %.18lf", x, y, z);
    return 0;
}
