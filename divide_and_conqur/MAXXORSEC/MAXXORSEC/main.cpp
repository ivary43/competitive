#include "/Users/manishkumar/Work/stdc++.h"
//#include <iostream>
using namespace std;
int main() {
    int n ;
    cin>>n ;
    int arr[n];
    
    for(int i=0;i<n;++i) {
        cin>>arr[i];
    }
    
    for(int i=0;i<n;++i){
        cout<<bitset<3>(arr[i]).to_string()<<endl;
    }
    
    return 0;
}
