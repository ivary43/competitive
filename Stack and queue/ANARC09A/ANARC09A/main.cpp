#include "/Users/manishkumar/Work/stdc++.h"
//#include <iostream>
using namespace std;
int main() {
    
    string s;
    cin>>s;
    int k=1;
    while(s.find("-") == string::npos) {
        int n = (int)s.size();
        int close =0 ;
        stack<int> st;
        for(int i=0;i<n;++i){
            if(!st.empty() && s[i] == '}') {
                st.pop();
            } else if(s[i]== '{'){
                st.push(s[i]);
            } else {
                ++close;
            }
        }
        int open = (int)st.size();
        int res = (open/2)+(close/2)+((open%2)*2);
        cout<<k<<". "<<res<<endl;
        cin>>s;
    }
    
    return 0;
}
