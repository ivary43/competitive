#include "/Users/manishkumar/Work/stdc++.h"
//#include <iostream>
using namespace std;
int main() {
    int n ;
    cin>>n;
    while(n) {
        int arr[n];
        for(int i=0;i<n;++i) {
            cin>>arr[i];
        }
        stack<int> height ;
        stack<int> pos;
        long long int res = 0;
        int i;
        for( i=0;i<n;++i) {
            
            if(!height.empty() && height.top()<=arr[i]) {
                height.push(arr[i]);
                pos.push(i);
            } else if(height.empty()) {
                height.push(arr[i]);
                pos.push(i);
            } else {
                while(!height.empty()) {
                    if(height.top()<=arr[i]) {
                        break;
                    }
                    int h = height.top();
                    height.pop();pos.pop();
            
                    res=max(res, 1LL*h*((pos.empty())?i:(i-pos.top()-1)));
                    
                }
                
                height.push(arr[i]);
                pos.push(i);
            }
        
        }
        
        while(!height.empty()) {
            int h = height.top();
            height.pop();pos.pop();
            
            res=max(res, 1LL*h*((pos.empty())?i:(i-pos.top()-1)));
            
        }
        
        cout<<res<<endl;
    
        cin>>n;
    
    }

    return 0;
}
