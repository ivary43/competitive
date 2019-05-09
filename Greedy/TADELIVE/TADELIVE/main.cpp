#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
bool compareTo(pair<pair<int,int>,int> a1, pair<pair<int,int>,int> a2) {
    return (a1.second>a2.second);
}

int main() {
    int N,n1,n2;
    cin>>N>>n1>>n2;
    int arr1[N], arr2[N];
    for(int i=0;i<N;++i) {
        cin>>arr1[i];
    }
    
    for(int i=0;i<N;++i) {
        cin>>arr2[i];
    }
    
    vector<pair<pair<int,int>,int>> arr(N);
    for(int i=0;i<N;++i) {
        pair<int,int> temp = {arr1[i], arr2[i]} ;
        int diff = arr1[i] - arr2[i] ;
        pair<pair<int, int>,int> temp2= {temp, diff};
        arr[i] = temp2;
    }
    
    sort(arr.begin(),arr.end(),compareTo);
    long int sum  = 0;

    for(int i=0;i<N;++i) {
        
        if(arr[i].second >= 0 && n1>0) {
            sum+=(arr[i].first.first);
            n1--;
        } else if(arr[i].second <= 0 && i<N-n2 && n1>0) {
            sum+=(arr[i].first.first);
            n1--;
        } else {
            sum+=(arr[i].first.second);
            n2--;
        }
    }
    
    cout<<sum<<endl;
}
