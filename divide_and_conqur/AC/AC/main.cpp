#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s ;
    stack<char> st ;
    for(char ch: s) {
        if(!st.empty() && st.top() == ch) {
            st.pop();
        } else {
            st.push(ch);
        }
    }
    if(st.empty()) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    
    return 0;
}
