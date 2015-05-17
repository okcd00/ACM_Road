#include <iostream>
using namespace std;
int main()
{
    int x,y;    cin>>x>>y;
    cout<<min(x,y)+1<<endl;
    for(int i=min(x,y);i>=0;i--)
		cout <<i<<" "<<min(x,y)-i<<endl;
    return 0;
}