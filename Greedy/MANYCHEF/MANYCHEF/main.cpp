#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
bool isAmatch(string str , int offest,int n) {
    if(offest <= 2) {
        return false;
    }
    if((str[offest]=='?' || str[offest] =='F') &&
       (str[offest-1]=='?' || str[offest-1] =='E') &&
       (str[offest-2]=='?' || str[offest-2] =='H') &&
       (str[offest-3]=='?' || str[offest-3] =='C') ) {
        return true;
    }
    return false;
}

int main() {
 
    int T ;
    cin>>T ;
    while(T--) {
        string s;
        cin>>s;
        int n = (int)s.length();
        
        for(int i=n-1;i>=0;--i) {
            if(isAmatch(s, i, n)) {
                s[i] = 'F';s[i-1]='E';s[i-2]='H';s[i-3]='C';
                i=i-3;
            } else {
                s[i] = (s[i] == '?')?'A':s[i];
            }
        }
        
        cout<<s<<endl;
    }
    return 0;
}
