#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
int main() {
    int C;
    cin>>C;
    int c_=1;
    while(C--) {
        int N,K,B,T ;
        cin>>N>>K>>B>>T ;
        int x[N];
        float t[N];
        for(int i=0;i<N;++i) {
            cin>>x[i];
        }
        int dummy ;
        for(int i =0;i<N;++i) {
            cin>>dummy;
            t[i] = (float)(B-x[i])/dummy;
        }
        
//        for(int i=N-1;i>=0;--i) {
//            cout<<t[i]<<" ";
//        }
//        cout<<endl;
        
        int last_occupied = 0 ;
        long int count = 0 ;
        for(int i=N-1,j=0;i>=0;--i,j++) {
            if(t[i]<=T) {
                count+=(j-last_occupied);
                last_occupied++;
            }
            if(last_occupied == K) {
                break;
            }
        }
        
        if(last_occupied == K) {
            cout<<"Case #"<<c_<<": "<<count<<endl;
        } else {
            cout<<"Case #"<<c_<<": IMPOSSIBLE"<<endl;
        }
        
        
        
        
        c_++;
    }
    
    
    return 0;
}
