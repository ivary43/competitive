#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
bool findLowest(vector<int> arr,int c) {
    for(int i=0;i<c;++i) {
        if(arr[i]>0) {
            return true;
        }
    }
    return false;
}

int main() {
    
    string s;
    cin>>s ;
    vector<int> vi(26);
    for(char ch:s) {
        vi[ch-'a']++;
    }
    
    stack<char> st;
    int i=0 ;
    string res = "";
    while(i<s.length()) {
        if(st.empty() || findLowest(vi, st.top()-'a')) {
            st.push(s[i]);
            vi[s[i]-'a']--;
            i++;
            
        } else {
            res+=(st.top());
            st.pop();
        }
    }
    
    while(!st.empty()) {
        res+=(st.top());
        st.pop();
    }
     
    cout<<res<<endl;
    return 0;
}
