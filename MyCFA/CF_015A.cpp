#include<iostream>    
#include<algorithm>    
#include<list>    
#include<cstdio>    
#include<cstdlib>    
using namespace std;    
    
typedef pair<int,int> house;    
typedef list<house> infov;    
    
bool cmp(const house& p1, const house& p2) {   return p1.first < p2.first;   }    

int main()    
{    
    int n,cnt=0;    
    int t;  
    scanf("%d%d", &n, &t);    
    infov info;    
    for(int i=0;i<n;i++)    
    {    
        int x_tmp, a_tmp;    
        scanf("%d%d", &x_tmp, &a_tmp);    
        info.push_back(make_pair(x_tmp,a_tmp));    
    }    
    info.sort();    
    //info.unique();  如果需要去重的话    
    infov::iterator it,itemp;    
    for(it=info.begin();it!=info.end();++it)    
    {    
        //cout<<it->first<<"\t"<<it->second<<endl;  
        if(it!=info.begin())    
            if( (it->first - itemp->first)*2  
                < (it->second + itemp->second) +t*2 );
            else if( (it->first - itemp->first)*2  
                    ==(it->second + itemp->second +t*2 ) )  
                    {  
                        //cout<<"n2:"<<testcnt<<endl;                           
                        cnt++;  
                    }  
            else if( (it->first - itemp->first)*2  
                    >(it->second + itemp->second) +t*2 )   
                    {  
                        //cout<<"n3:"<<testcnt<<endl;   
                        cnt+=2;   
                    }  
        itemp=it;    
    }     
    cout<< cnt+2;    
    return 0;    
}     