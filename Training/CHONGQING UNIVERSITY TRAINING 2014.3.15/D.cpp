#include <iostream>
#include <cstdio>
#include <algorithm>
//好讨厌！ strlen到底是哪个头文件！！！ 
/*
#include <string>
#include <string.h>
#include <cstring>
*/

//回文序列判定？  1st Up 
//...看来是判定是否可以全回文抵消…… 2nd Up 
//读回车大坑！ 3rd Up 
#include <stack>
using namespace std;
/* 
int main()
{
    char st[100001];
    cin>>st;
    int len = strlen(st);
    if (len%2) {
                       cout<<"No";
                       return 0;
               }
    char c1,c2;
    for(int i=0;i<len/2;i++)
    {
            c1=st[i];
            c2=st[len-1-i];
     if(c1!=c2){
                       cout<<"No";
                       return 0;
               }
     else continue;
    }
    cout<<"Yes";
    return 0;
}
*/


char tmp;
stack<char> s;

void solve()
{
	while (scanf("%c", &tmp) != EOF && tmp!='\n') //坑！ 
    {
		if (s.empty())
			s.push(tmp);
		else {
			char t = s.top();
			if (t == tmp)
				s.pop();
			else
				s.push(tmp);
		     }
	}
}

int main() 
{
    solve();
	if (s.size())
		cout<<"No";
	else
		cout<<"Yes";
	return 0;
}
