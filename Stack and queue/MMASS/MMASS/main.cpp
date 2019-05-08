#include "/Users/manishkumar/Work/stdc++.h"
//#include <iostream>
using namespace std;
#define CMASS 12
#define OMASS 16
#define HMASS 1
int start = 0 ;
bool isNextInt(char c){
    int val = c - '0';
    if( val>=2 && val<=9 ){
        return true;
    }
    return false;
}

int findVal( int len, string s){
    int res = 0 ;
    for(;start<len;++start) {
        int mf=1;
        if(s[start] == ')') {
            if(start+1<len && isNextInt(s[start+1])) {
                ++start;
                return res*(s[start]-'0');
            }
            return res;
        } else if(s[start] == 'C') {
            if(start+1<len && isNextInt(s[start+1])) {
                ++start;
                mf = s[start] - '0';
            }
            res+=(CMASS*mf);
        } else if(s[start] == 'O') {
            if(start+1<len && isNextInt(s[start+1])) {
                ++start;
                mf = s[start] - '0';
            }
            res+=(OMASS*mf);
        } else if(s[start] == 'H' ) {
            if(start+1<len && isNextInt(s[start+1])) {
                ++start;
                mf = s[start] - '0';
            }
            res+=(HMASS*mf);
        } else if (s[start] == '('){
            ++start;
            res+=findVal( len, s);
        }
    }
    return 0;
}

int main() {
    
    string s;
    cin>>s ;
    int res = 0 ;
    for(start=0;start<s.length();++start) {
        int mf = 1;
        if(s[start] == 'C') {
            if(start+1<s.length() && isNextInt(s[start+1])) {
                ++start;
                mf = s[start]- '0';
            }
            res+=(CMASS*mf);
        } else if(s[start] == 'O') {
            if(start+1<s.length() && isNextInt(s[start+1])) {
                ++start;
                mf = s[start]- '0';
            }
            res+=(OMASS*mf);
        } else if(s[start] == 'H' ) {
            if(start+1<s.length() && isNextInt(s[start+1])) {
                ++start;
                mf = s[start]- '0';
            }
            res+=(HMASS*mf);
        } else if (s[start] == '('){
            ++start;
            res+=findVal( (int)s.length(), s);
        }
    }
    
    cout<<res<<endl;
    
    
    return 0;
}
