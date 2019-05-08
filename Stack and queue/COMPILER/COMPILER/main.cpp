#include "/Users/manishkumar/Work/stdc++.h"
//#include <iostream>
//#include<bits/stdc++.h>
using namespace std;
int main() {
    
    int T;
    cin>>T;
    while(T--) {
        string s ;
        cin>>s;
        stack<int> ch ;
        
        int res = 0 ;
        for(char x:s) {
            if(x=='<') {
                ch.push(x);
            } else {
                if(!ch.empty()) {
                    ch.pop();
                    res+=2;
                }
            }
        }
        cout<<res<<endl;
        
    }
    
    
    
    return 0;
}
