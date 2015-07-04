#include <iostream>  
#include <cstring>  
using namespace std;  
//http://blog.csdn.net/okcd00/article/details/22695739
int main()  
{  
    char s[8][8];  
    int sum=0;  
    for(int i=0;i<8;i++) 
        for(int j=0;j<8;j++) 
        	cin>>s[i][j];  
    int sum2=0;  
    int sum3=0;  
    for(int i=0;i<8;i++)  
    {  
        int sum1=0;  
        for(int j=0;j<8;j++)  
        {  
            if(s[i][j]=='B')  
            sum1++;  
        }  
        if(sum1==8)  
        sum2++;  
        else  
        sum3=sum1; //优化关键：横刷刷完了之后看看剩下点啥全是纵刷 虽然个人觉得为了不被Hack要不要加一个 (if sum1>sum3) sum3=sum1   
    }  
    cout<<sum2+sum3<<endl;  
    return 0;  
}  
