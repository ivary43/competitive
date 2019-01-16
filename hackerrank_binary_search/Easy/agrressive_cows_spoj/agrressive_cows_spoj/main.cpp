//
//  main.cpp
//  agrressive_cows_spoj
//
//  Created by Manish Kumar on 15/12/18.
//  Copyright © 2018 Manish Kumar. All rights reserved.
//

//#include<bits/stdc++.h>
#include "/Users/manishkumar/Downloads/Header/stdc++.h"
#define pb push_back
using namespace std;
bool isArrangementPos(int dist, vector<int>v, int c) {
    int n = (int)v.size();
    int prev= v[0];
    int count= 1, prev_index=0;
    for(int i=0;i<c-1;++i) {
        for(int j= ++prev_index;j<n;++j) {
            if(v[j]- prev>= dist) {
                prev = v[j];
                count++;
                prev_index=j;
                break;
            }
        }
    }
    if(count==c) {
        return true;
    }
    return false;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n, c ,x;
        cin>>n>>c;
        vector<int> stall_pos;
        for(int i=0;i<n;++i) {
            cin>>x;
           // stall_pos.push_back(x);
            stall_pos.pb(x);
        }
        sort(stall_pos.begin(), stall_pos.end());
        
       // high = ceil((stall_pos[n-1]- stall_pos[0])/(c-1))
        int low = 0, high = (stall_pos[n-1]- stall_pos[0]), mid, res=-1;
       
        while(low<=high) {
             mid = (high+low)/2 ;
            if(isArrangementPos(mid, stall_pos, c)) {
                res=mid;
                low = mid+1;
            } else {
                high =mid-1;
            }
        }
        cout<<res<<endl;
    }
    
    return 0 ;
    
}
