#include "/Users/manishkumar/Work/stdc++.h"
//#include <iostream>
using namespace std;
#define CMASS 12
#define OMASS 16
#define HMASS 1

bool isNextInt(char c){
    int val = c - '0';
    if( val>=2 && val<=9 ){
        return true;
    }
    return false;
}

int main() {
    
    string s;
    cin>>s ;
    int res =0 ;
    stack<int> val;
    int n = s.length();
    for(int i=0;i<s.length();++i){
        char x= s[i];
        int mf=1;
        
        if(x == '(') {
            val.push(res);
            res=0;
        } else if(x=='C') {
            if(i+1<n && isNextInt(s[i+1])) {
                mf = s[i+1] - '0';
            }
            res+=(CMASS*mf);
        } else if(x=='O') {
            if(i+1<n && isNextInt(s[i+1])) {
                mf = s[i+1] - '0';
            }
            res+=(OMASS*mf);
        } else if(x=='H') {
            if(i+1<n && isNextInt(s[i+1])) {
                mf = s[i+1] - '0';
            }
            res+=(HMASS*mf);
        } else if(x == ')') {
            if(i+1<n && isNextInt(s[i+1])) {
                mf = s[i+1] - '0';
            }
            res*=mf;
            if(!val.empty()) {
                res+=val.top();
                val.pop();
            }
        }
    }
    cout<<res<<endl;
    
}
