#include <cstdio>  
using namespace std;  
//http://blog.csdn.net/okcd00/article/details/24502393

char a, s[3][3]; 
inline bool judge(){return (s[0][0]==s[2][2]&&s[0][1]==s[2][1]&&s[0][2]==s[2][0]&&s[1][0]==s[1][2]);}

int main()  
{   
    for(int i=0;i<3;i++)  
    {   
        for(int j=0;j<3;j++)  
            scanf("%c",&s[i][j]);  
        scanf("%c",&a);  
    }   
    printf(judge()?"YES":"NO");  
    return 0;   
}  
