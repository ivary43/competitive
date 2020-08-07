#include "/Users/manishkumar/Work/stdc++.h"
//#include<bits/stdc++.h>

using namespace std ;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
#define mp make_pair

int prec( char c ){
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s){
    
    int n = (int)s.size() ;
    
    stack<char> st ;
    string out_str = "";
    for(int i=0;i<n;++i){
        if(s[i] == '('){
            st.push(s[i]);
        } else if(s[i] == ')'){
            while(st.top() != '('){
                out_str+=st.top();
                st.pop();
            }
            st.pop();
        } else if( (s[i]>= 'a' && s[i]<='z' ) || (s[i]>= 'A' && s[i]<='Z') ){
            out_str+=s[i];
        } else {
            
            if(st.empty() || prec(s[i]) > prec(st.top()) ) {
                st.push(s[i]);
            } else {
                while(!st.empty() && prec(s[i]) <= prec(st.top())){
                    out_str+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            
        }
        
    }
    
    while(!st.empty()){
        out_str+=st.top();
        st.pop();
    }
    
    cout<<out_str<<"\n";
}

void postfixToInfix(string s){
    
    stack<string> operand ;
    
    int n  = (int) s.size() ;
    
    for(int i =0 ;i<n;++i){
        if( (s[i]>= 'a' && s[i]<='z' ) || (s[i]>= 'A' && s[i]<='Z') ){
            string temp = "";
            temp+=s[i];
            operand.push(temp) ;
        } else {
            string b = operand.top();
            operand.pop() ;
            string a = operand.top() ;
            operand.pop();
            string out_str = "";
            out_str+=("("+a+s[i]+b+")");
            operand.push(out_str);
//            out_str+="(";
//            out_str+=a ;
//            out_str+=s[i];
//            out_str+=b;
//            out_str+=")";
            
        }
        
    }
    
    cout<<operand.top()<<"\n";
    
    
    
    
}


void infixToPrefix(string s){
    
    int n = (int)s.size();
    string out_str = "";
    stack<char> st ;
    for(int i =n-1;i>=0;--i){
        
        if(s[i] == ')') {
            st.push(s[i]);
        } else if(s[i] == '('){
            
            while(st.top()!=')'){
                out_str = st.top()+out_str ;
                st.pop() ;
            }
            st.pop() ;
        } else if ((s[i]>= 'a' && s[i]<='z' ) || (s[i]>= 'A' && s[i]<='Z')){
            out_str= s[i]+out_str ;
        } else {
            
            if(st.empty() || prec(s[i]) > prec(st.top())) {
                st.push(s[i]);
            } else {
                
                while(!st.empty() && prec(s[i]) <= prec(st.top())) {
                    out_str=st.top()+out_str;
                    st.pop();
                }
                
                st.push(s[i]);
            }
            
        }

    }
    
    
    while (!st.empty()) {
        out_str=st.top()+out_str;
        st.pop();
    }
    
    cout<<out_str<<"\n";
}



int main() {
    
    string s ;
    cin>>s ;
    
    postfixToInfix(s);
//    infixToPrefix(s);
//    infixToPostfix(s);
    
    return 0;
}
