#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int sum[30]= {0};
    string s; cin>>s;
    for(int i=0; i<s.length(); i++)	sum[s[i]-'a']++;
    int f=0;
    for(int i=0; i<26; i++)
        if(sum[i]%2==1)	f++;
    if(f%2==1||f==0)	printf("First\n");
    else	printf("Second\n");
    return 0;
}
