#include<iostream>    
#include<algorithm>
using namespace std;
//http://blog.csdn.net/okcd00/article/details/22693717
int main()    
{  
    int w;  cin>>w;
    cout<< (w==2?"NO":(w%2==1?"NO":"YES"));
    return 0;  
}    
