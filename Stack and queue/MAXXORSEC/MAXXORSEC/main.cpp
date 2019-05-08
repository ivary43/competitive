#include "/Users/manishkumar/Work/stdc++.h"
using namespace std;
int solve(vector<int> arr, int n ) {
    stack<int> s;
    int res = -1;
    for(int i=0;i<n;++i) {
        while(!s.empty()&& s.top()<arr[i]) {
            s.pop();
        }
        s.push(arr[i]);
        if(s.size() >=2 ) {
            int x = s.top(); s.pop();
            res = max(res, x^s.top());
            s.push(x);
        }
    }
    
    return res;
}

int main () {
    int n;
    cin>>n ;
    vector<int> arr(n);
    for(int i=0;i<n;++i) {
        cin>>arr[i];
    }
    
    int maxVal = solve(arr, (int)arr.size());
    reverse(arr.begin(), arr.end());
    cout<<max(maxVal, solve(arr, (int)n))<<endl;

    return 0;
}
