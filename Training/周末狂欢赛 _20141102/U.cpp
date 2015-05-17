#include<cstdio>  
#include<algorithm>  
using namespace std;  
  
int main()  
{  
    int n,m;  
    scanf("%d%d",&n,&m);  
    int left=m-1,up=n-1,right=0,down=0;  
    char graph[n][m+1];//+1 for endl;  
    char end_l;  
    scanf("%c",&end_l);  
    for(int i=0;i<n;)  
    {  
        for(int j=0;j<=m;)//j=m for endl;  
        {  
            scanf("%c",&graph[i][j]);  
            if(graph[i][j]=='*')  
            {  
                if(i<up) up=i;  
                if(i>down)   down=i;  
                if(j<left)   left=j;  
                if(j>right)  right=j;   
            }  
            j++;  
        }  
        //scanf("%c",&end_l);//read 'endl'  
        i++;  
    }  
  
    for(int i=up;i<=down;i++)  
    {  
        for(int j=left;j<=right;j++)  
        printf("%c",graph[i][j]);  
        printf("\n");  
    }  
      
    return 0;  
}   
