#include "/Users/manishkumar/Work/stdc++.h"
//#include<bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
#define mp make_pair
// Function to compute num (mod a)
//int mod(string num, int a)
//{
//    // Initialize result
//    int res = 0;
//
//    // One by one process all digits of 'num'
//    for (int i = 0; i < num.length(); i++)
//        res = (res*10 + (int)num[i] - '0') %a;
//
//    return res;
//}


int main() {
    int T;
    
    cin>>T ;
    int e =0 , o =0 ;
    while(T--) {
        int n ;
        cin>>n ;
        set<long long int> st ;
        set<long long int> ::iterator it ;
        
        while(n--) {
            int x;
            cin>>x ;
            
            if(st.find(x)!=st.end()) {
                cout<<e<<" "<<o<<endl;
                continue;
            }
            
            set<long long int> temp;
            int count ;
            for(it=st.begin();it!=st.end();++it){
                int val = x xor *it ;
                count = __builtin_popcount(val);
                if(count%2 == 0) {
                    e++;
                } else {
                    o++;
                }
                temp.insert(val);
            }
            
            for(it=temp.begin();it!=temp.end();++it) {
                st.insert(*it);
            }
            
            count = __builtin_popcount(x);
            if(count%2 == 0) {
                e++;
            } else {
                o++;
            }
            st.insert(x);
            cout<<e<<" "<<o<<endl;
        }
        
    }
    

    return 0;
}











//int main() {
//    int T ;
//    cin>>T ;
//
//    while(T--) {
//        int n;
//        cin>>n ;
//        map<int,int> val;
//        int temp ;
//        long int res = 0 ;
//        rep(i, n) {
//            cin>> temp ;
//            res+=temp;
//            if(val.find(temp) == val.end())
//            val.insert(make_pair(temp, i+1));
//        }
//
//        temp = res % n ;
//
//        if(temp != 0) {
//            cout<<"Impossible"<<endl;
//        } else {
//            if( val.find((int) (res/n) ) == val.end()) {
//                cout<<"Impossible"<<endl;
//            } else {
//                cout<<val[(int)(res/n)]<<endl;
//            }
//        }
//
//    }
//
//}




//vector<string> stringSpilt(string str, string delimeter) {
//    vector<string> res ;
//    int n = (int)str.length();
//    char ch_arr[n+1];
//    strcpy(ch_arr, str.c_str());
//    const char* temp_delimeter = delimeter.c_str();
//    char* token = strtok(ch_arr, temp_delimeter);
//
//    while (token != NULL)
//    {
//        string temp(token);
//        res.push_back(temp);
//        token = strtok(NULL, "-");
//    }
//    return res ;
//}
//class Node {
//    public:
//    int data ;
//    Node* next ;
//};
//
//
//
//int main() {
//
//    Node* head = new Node();
//    head->data = 1;
//    head->next= NULL ;

    
//    string s, delimeter ;
//    cin>>s ;
//    cin>>delimeter;
//
//    vector<string> tok = stringSpilt(s, delimeter);
//    vector<string>:: iterator it ;
//    for(it=tok.begin(); it!=tok.end();++it){
//        cout<<*it<<endl;
//
//    }
    
    
    
//
//    return 0;
//}
