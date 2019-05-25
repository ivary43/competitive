#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;

bool compareTo1(pair<int,int> a1,pair<int,int> a2) {
    if(a1.first == a2.first) {
        return a1.second < a2.second;
    } else {
      return a1.first < a2.first;
    }
}

int main() {
    
    int T ;
    cin>>T ;
    while(T--) {
        int N ;
        cin>>N ;
        vector<pair<int,int>> arr(N);
        int x,y ;
        for(int i=0;i<N;++i) {
            cin>>x>>y;
            arr[i] = {x , y};
        }
        
        sort(arr.begin(), arr.end(), compareTo1);
        long int res = 0;
        int count = 0 ;
        int prev = -1;
        vector<int> arr2;
        vector<int> arr1;
        for(int i=0;i<N;++i) {
            if(arr[i].first!=prev) {
                count++;
                prev = arr[i].first;
                arr1.push_back(arr[i].second);
            } else {
                arr2.push_back(arr[i].second);
            }
        }
        sort(arr1.begin(), arr1.end());
        
        for(int i=0;i<arr1.size();++i) {
            cout<<arr1[i]<<endl;
            res+=(1ll*(i+1)*arr1[i]);
        }
        
        for(int i=0;i<arr2.size();++i) {
            res+=(1ll*count*arr2[i]);
        }
        
        cout<<res<<endl;
    }
    
    return 0;
}
