#include "/Users/manishkumar/Work/stdc++.h"
//#include <iostream>
using namespace std;
int main() {
    int T;
    cin>>T ;
    while(T--) {
        string in;
        cin>>in ;
        stack<char>  alpha ;
        stack<char> sym ;
        string res = "";
        for(char x:in){
            if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' ) {
                sym.push(x);
            } else if (x == ')') {
                alpha.pop();
                if(!sym.empty()) {
                    res+=sym.top();
                    sym.pop();
                }
            } else if (x == '('){
                alpha.push(x);
            } else {
                res+=x;
            }
        
        }
        
        while (!sym.empty()) {
            res+=sym.top();
            sym.pop();
        }
        
        cout<<res<<endl;
        
        
    }
    
    return 0;
}
