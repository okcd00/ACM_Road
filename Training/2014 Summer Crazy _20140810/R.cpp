#include <iostream>                                                                                                                               
#include <vector>  
#include <string>  
   
using namespace std;  
   
vector <string> v;  
string s, t;  
   
int main ( ) {  
    int n, i;  
    cin >> n;  
    while ( n-- ) {  
        cin >> s;  
        if ( s == "pwd" ) {  
            for ( int i = 0; i < v.size ( ); ++i ) cout << "/" << v[i];  
            cout << "/" << endl;  
        }  
        else {  
            cin >> s;  
            i = 0;  
            if ( s[0] == '/' ) { v.clear ( ); i = 1; }  
            for ( ; i < s.size ( ); ++i ) {  
                t="";  
                for ( ; s[i] != '/' && i < s.size ( ); ++i ) t += s[i];  
                if ( t == ".." ) v.pop_back ( );  
                else v.push_back ( t );  
            }  
        }  
    }  
}  
