#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
//http://blog.csdn.net/okcd00/article/details/22693127
int score[1010];
string name[1010];
map<string, int> p1,p2;
int main()
{
    int n,i,j;
    while(cin>>n)
    {
        int m = 0;
        for(i = 0;i < n;i ++)
        {
            cin>>name[i]>>score[i];
            p1[name[i]] += score[i];
        }
        for(i = 0;i < n;i ++)
        if(p1[name[i]] > m) m = p1[name[i]];
        for(i = 0;i < n;i ++)
        {
            p2[name[i]] += score[i];
            if(p2[name[i]] >= m&&p1[name[i]] == m)
            {
                cout<<name[i]<<endl;
                break;
            }
        }
    }
	return 0;
}
