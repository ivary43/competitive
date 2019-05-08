#include "/Users/manishkumar/Work/stdc++.h"
//#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n ;
    while(n) {
        vector<int> arr(n);
        for(int i=0;i<n;++i) {
            cin>>arr[i];
        }
        stack<int> side_road;
        vector<int> res;
        
        int next = 1;
        for(int i=0;i<n;++i) {
            if(arr[i]==next) {
                res.push_back(next);
                next++;
            } else if(  (!side_road.empty() && side_road.top() == next)) {
                res.push_back(next);
                next++;i--;
                side_road.pop();
            } else {
                side_road.push(arr[i]);
            }
        }
        
        while(!side_road.empty()) {
            if(side_road.top()!=next) break;
            res.push_back(next);
            next++;
            side_road.pop();
        }
        
        if(res.size() == n) {
            cout<<"yes"<<endl;
        } else {
            cout<<"no"<<endl;
        }
        
        cin>>n;
    }
    
    return 0;
}
