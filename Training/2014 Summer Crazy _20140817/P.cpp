#include <iostream>

using namespace std;
int arr[35][2];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][0]==arr[j][1]) ans++;
        }
    }
    cout<< ans;
}
