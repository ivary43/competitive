#include "/Users/manishkumar/Downloads/Header/stdc++.h"
//#include<bits/stdc++.h>
using namespace std ;
#define pb push_back
#define INF 1e5
#define ll long long int
#define f(i,a,b) for(int i=a;i<b;i++)
#define rep(n) f(i,0,n)
#define vs vector<string>

void swap( string *xp, string *yp)
{
    string temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main() {
    
    int T ;
    cin>>T;
    
    while (T--) {
        
        string str ;
        cin>>str;
        
        // Vector of string to save tokens
        vector <string> tokens;
        
        // stringstream class check1
        stringstream check1(str);
        
        string intermediate;
        
        // Tokenizing w.r.t. space ' '
        while(getline(check1, intermediate, '.'))
        {
            tokens.push_back(intermediate);
        }
        
        int s = (int)tokens.size();
        rep(s/2) {
            
            swap(&tokens[i],&tokens[s-i-1]);
        }
        
        rep(s) {
            cout<<tokens[i];
            if(i!=s-1) {
                cout<<'.';
            }
        }
        cout<<endl;
    }
    
    
    return 0 ;
}
