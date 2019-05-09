#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
int findLowest(char prev , char next, int k) {
    for(int i=0;i<k;++i) {
        if(next == '?' && (prev-'0')!=i) {
            return i;
        } else if((prev-'0')!=i && ((next-'0')!=i) ) {
            return i;
        }
    }
    return -1;
}

bool isStringCorrect(string s) {
    int n = (int)s.length();
    int prev = n-1;
    for(int i=0;i<n;++i){
        if(s[i] == s[prev]) {
            return false;
        }
        prev=i;
    }
    return true;
}


int main() {
    int T ;
    cin >>T ;
    while(T--) {
        int k ;
        cin>>k ;
        string s;
        cin>>s ;
        int n = (int)s.length();
        if(k == 2 && n!=1 ) {
            if(n%2 !=0) {
                cout<<"NO"<<endl;
                continue;
            } else {
                bool turn=true;
                string w = s;
                for(int i=0;i<n;++i) {
                    if(w[i] == '?') {
                        if(turn) {
                            w[i] = '0';
                        } else {
                            w[i] = '1';
                        }
                    }
                    turn=(!turn);
                }
                
                if(isStringCorrect(w)) {
                    cout<<w<<endl;
                    continue;
                }
                
                turn=true;
                w = s;
                for(int i=0;i<n;++i) {
                    if(w[i] == '?') {
                        if(turn) {
                            w[i] = '1';
                        } else {
                            w[i] = '0';
                        }
                    }
                    
                    turn=(!turn);
                }
                
                if(isStringCorrect(w)) {
                    cout<<w<<endl;
                    continue;
                }
                
                
                cout<<"NO"<<endl;
                continue;
            }
            
        }
        
        
        
        
        bool isPoss = true;
        for(int i=0;i<n;++i) {
            int prev = (i-1);
            int next = (i+1)%n;
            prev = (prev<0)?n-1:prev;
            
            if(s[i] == '?') {
                int tempVal = findLowest(s[prev], s[next], k);
                if(tempVal != -1) {
                    s[i]='0'+tempVal;
                } else {
                    isPoss = false;
                    break;
                }
            } else if(s[i] == s[prev] && i!=prev ){
                isPoss = false;
                break;
            }
        }
        
        if(!isPoss) {
            cout<<"NO"<<endl;
        } else {
            cout<<s<<endl;
        }
    }
    
    return 0;
}
