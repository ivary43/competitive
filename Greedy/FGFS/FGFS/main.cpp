#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
bool compareTo(pair<int,int>a1 , pair<int,int>a2) {
    return (a1.second < a2.second);
}


int main() {
    int T ;
    cin>>T;
    while(T--) {
        int n, k;
        cin>>n>>k ;
        int arr[n], dep[n], p[n];
        
        set<int> diff_k;
        for(int i=0;i<n;++i) {
            cin>>arr[i]>>dep[i]>>p[i];
            diff_k.insert(p[i]);
        }
        
        int diff_k_size = (int)diff_k.size();
        vector<pair<int,int>> dist_pair[diff_k_size];
        map<int,int> p_ind;
        int count_b = 0 ;
        for(int i=0;i<n;++i) {
            if(p_ind.find(p[i]) == p_ind.end()) {
                p_ind.insert(make_pair(p[i],count_b));
                dist_pair[count_b].push_back(make_pair(arr[i], dep[i]));
                count_b++;
            } else {
                int temp = p_ind.find(p[i])->second;
                dist_pair[temp].push_back(make_pair(arr[i], dep[i]));
            }
        }
        int res = 0;
        for(int i=0;i<diff_k_size;++i) {
            sort(dist_pair[i].begin(), dist_pair[i].end(), compareTo);
            vector<pair<int,int>>::iterator it;
            int prev = - 1;
            for(it=dist_pair[i].begin();it!=dist_pair[i].end();++it) {
                if(prev == -1 || it->first>=prev) {
                    res++;
                    prev=it->second;
                }
            }
        }
        
        cout<<res<<endl;
        
    }
    
    return 0;
}
