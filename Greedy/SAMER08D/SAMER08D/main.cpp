#include "/Users/manishkumar/Work/stdc++.h"
//#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
#define mp make_pair
bool isStringCont(int i1, int i2 , string s1 ,string s2, int k ) {
    
    bool isEqual = true;
    
    for(int j=0;j<k;++j) {
        if(s1[i1-j]!=s2[i2-j]) {
            isEqual = false;
            break;
        }
    }
    return isEqual;
}

//int maxMatch(int i1,int i2, string s1, string s2){
//    int m_ = min((int)s1.length(), (int)s2.length());
//    int i;
//    for(i=0;i<m_;++i) {
//        if(s1[i1-i]!=s2[i2-i]) {
//            return i;
//        }
//    }
//    return i;
//}

int main() {
    
    int k;
    cin>>k ;
    while(k!=0) {
        string s1, s2 ;
        cin>>s1;
        cin>>s2;
        int n = (int)s1.length();
        int m = (int)s2.length();
        int res[1005][1005] = {0};
        int chunk[1005][1005] = {0};
      
        for(int i=1;i<=m;++i) {
            for(int j=1;j<=n;++j) {
                if(s2[i-1] == s1[j-1]) {
                    chunk[i][j] = chunk[i-1][j-1]+1;
                } else {
                    chunk[i][j] = 0;
                }
                
                if(i<k || j<k){
                    res[i][j]=max(res[i-1][j], res[i][j-1]);
                } else {
                    bool isEq = false ;
                    isEq = isStringCont(j-1, i-1, s1, s2, k);
                    if(isEq) {
                        int temp =chunk[i-k][j-k];
                        if(temp>=k) {
                            temp = 0 ;
                        }
                        res[i][j] = res[i-k][j-k]+k+temp;
                    } else {
                        res[i][j]=max(res[i-1][j], res[i][j-1]);
                    }
                }
               
            }
        }
        
        for(int i=0;i<=m;++i) {
            for(int j=0;j<=n;++j) {
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<"----------------------"<<endl;
        for(int i=0;i<=m;++i) {
            for(int j=0;j<=n;++j) {
                cout<<chunk[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<res[m][n]<<endl;
        cin>>k;
}
 return 0;
}
