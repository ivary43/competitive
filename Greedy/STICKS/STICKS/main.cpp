#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin>>T ;
    while(T--) {
        int N ,x;
        cin>>N ;
        int arr[1001] = {0};
        
        for(int i=0;i<N;++i){
            cin>>x;
            arr[x]++;
        }
        
        int l= -1;
        int b = -1;
        for(int i=1000;i>0;--i) {
            if(arr[i]>=2 && l == -1) {
                l = i;
                break;
            } else if(arr[i]>=2 && b ==-1) {
                b = i;
                break;
            }
        }
        
        if(l==-1 || b==-1) {
            cout<<-1<<endl;
        } else {
            cout<<l*b<<endl;
        }
        
    }
    
    
    return 0;
}
