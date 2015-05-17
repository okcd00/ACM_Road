#include <cstdio>  
#include <algorithm>
using namespace std;  
  
int main()  
{  
    char s[3][3];  
    char a;  
    for(int i=0;i<3;i++)  
    {   
        for(int j=0;j<3;j++)  
            scanf("%c",&s[i][j]);  
        scanf("%c",&a);  
    }   
    printf((s[0][0]==s[2][2]&&s[0][1]==s[2][1]&&s[0][2]==s[2][0]&&s[1][0]==s[1][2])?"YES":"NO");  
    return 0;   
}  
