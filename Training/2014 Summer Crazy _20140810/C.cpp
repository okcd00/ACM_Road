#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long>  ans;

int main()
{
    long long q;
    while(cin >> q)
	{
        ans.clear();
        for(long long i=2;i*i<=q;i++)
            while(q%i==0) ans.push_back(i), q/=i;
    
        if(q>1) ans.push_back(q);
        if(ans.size()<2) cout << "1" <<endl << "0" <<endl;
        else if(ans.size()==2) cout << "2" <<endl;
        else cout << "1" <<endl << ans[0]*ans[1] <<endl;
    }
    return 0;
}
