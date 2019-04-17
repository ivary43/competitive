#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
//char findLowest(vector<int> arr) {
//    for(int i=0;i<26;++i) {
//        if(arr[i]!=0) {
//            return (char)(97+i);
//        }
//    }
//    return 'a';
//}

int main() {
    
    string s;
    cin>>s ;
    stack<char> st;
    for(char c:s) {
        if(!st.empty() && c < st.top()) {
            while(!st.empty() && c < st.top() ) {
                st.pop();
            }
        }
            st.push(c);
    }
    string res = "";
    while(!st.empty()) {
        res=st.top()+res;
        st.pop();
    }
    string residual = "";
    int i=0 ; int n = (int)res.size();
    for(char c:s) {
        if( (i<n) && c == res[i]) {
            ++i;
        } else {
            residual+=c;
        }
    }
    reverse(residual.begin(), residual.end());
    res+=residual;
    cout<<res<<endl;
    
    
    
//
//    vector<int> arr(26);
//    for(char ch:s) {
//        arr[ch-'a']++;
//    }
//
//    char nextSmallest = findLowest(arr);
//    string residual = "";
//    string res = "";
//    for(char ch: s) {
//        if(arr[nextSmallest- 'a'] == 0 ) {
//            nextSmallest = findLowest(arr);
//        }
//
//        if(ch == nextSmallest) {
//            res+=nextSmallest;
//            arr[nextSmallest-'a']--;
//        } else {
//            residual+=ch;
//        }
//    }
//    reverse(residual.begin(), residual.end());
//    res+=residual;
//    cout<<res<<endl;
    
    return 0;
}
