#include <iostream>  
#include <algorithm>
using namespace std;  
//http://blog.csdn.net/okcd00/article/details/23312691
int main()
{  
    int n,m;  
    cin>>n>>m;// max one  
    if(n<m) n=m;  
    cout<<(7-n)/__gcd(7-n,6)<<'/'<<6/__gcd(7-n,6)<<endl;
    return 0;  
}  
