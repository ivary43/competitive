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

long long int val ;
long long int diff ;


void changeLaterDig(string &str , int index , bool val){
    int n = (int) str.length() ;
    if(val) {
        for(int i=index;i<n;++i) {
            str[i]='8';
        }
    } else {
        for(int i=index;i<n;++i) {
            str[i]='0';
        }
    }
}

void addCarry(string &s, int index) {
    int  carry = 2;
    for(int i=index ;i>=0 ;--i) {
        int val = s[i] -'0' ;
        if(val == 8 ) {
            s[i] = '0';
        } else {
            val+=2 ;
            s[i]='0'+val;
            return;
        }
    }
    
    if(carry) {
        s="2"+s;
        return;
    }
    
}


int main() {
    SYNC
    int T ;
    cin>>T ;
    int i = 1;
    while(T--) {
        diff = 0 ;
        string s ;
        cin>>s ;
        string M = s;
        string P = s;
        vector<int> x ;
        x.push_back(12);
        int n = s.length();
        for(int i=0;i<n;++i) {
            int val = s[i] - '0';
            if(val%2 == 1) {
                if(val == 9) {
                    M[i]='0'+(val-1);
                    changeLaterDig(M, i+1,true);
                    P[i]='0';
                    addCarry(P, i-1);
                    changeLaterDig(P, i+1, false);
                } else {
                    M[i]='0'+(val-1);
                    P[i]='0'+(val+1);
                    changeLaterDig(M, i+1,true);
                    changeLaterDig(P, i+1, false);
                }
                break;
            }
        }
        
        long long int M_val = stoll(M);
        long long int P_val = stoll(P);
        long long int main_val = stoll(s);
        
//        cout<<M_val<<"m_Val"<<endl;
//        cout<<P_val<<"p_val"<<endl;
//
        
        diff = min(main_val- M_val, P_val- main_val);
        cout<<"Case #"<<i<<": "<<diff<<"\n";
        i++;
        
    }
    
    
    
}
