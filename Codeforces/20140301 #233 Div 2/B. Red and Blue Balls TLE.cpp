#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <stack> //Add stack
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define RD(a) scanf("%d",&a)
#define PT(a) printf("%d",a)
using namespace std;

     stack<char> mystack;
     stack<char> stk;
void test(stack<char> &stk);

int main()
{
     int n;
     RD(n);
     char Redc='R',Bluec='B';
     for(int i=0;i<n;++i) 
     {
             char Tmp;
             cin>>Tmp;
             mystack.push(Tmp);
     }
     for(int i=n-1;i>=0;--i)
     {
             stk.push(mystack.top());
             mystack.pop();
     }
     int count=0;
     int cur=0;//reduce amount
     while(1)
     {        
              while(!stk.empty()&&stk.top()=='R')
                                                 {
                                                  stk.pop();
                                                  cur++;
                                                 }
              if(stk.empty()) break;
              if(stk.top()=='B')
                                {
                                    stk.pop(); 
                                    stk.push(Redc);
                                }
              if(cur>0)
              {
               for(int i=1;i<=cur;i++)stk.push(Bluec);
               cur=0;
              // printf("%d",stk.size());
              }
              count++;
              //test(stk);
     }
     PT(count);
     return 0;
     
}

void test(stack<char> &stk)
{   
     while(!stk.empty())
     {
     cout<<' '<<stk.top();
     stk.pop();
     }
}    
