#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
int findFarthest(set<int> p_table, int arr[], int offset,int m) {
    set<int>::iterator it;
    int pos=-1, maxPos = -1;
    for(it=p_table.begin();it!=p_table.end();++it) {
        
        bool isFound = false;
        for(int i=offset+1;i<m;++i) {
            if(arr[i]==*it) {
                pos=i;
                isFound=true;
                break;
            }
        }
        
        if(!isFound) {
            return *it;
        }
        
        if(pos>maxPos) {
            maxPos = pos;
        }
    }
    
    return arr[maxPos];
}



int main() {
    int T ;
    cin>>T ;
    while(T--) {
        int n , m ;
        cin>>n>>m ;
        set<int> p_table;
        int arr[m];
        for(int i=0;i<m;++i) {
            cin>>arr[i];
        }
        
        int faults = 0 ;
        bool isFound = false;
        for(int i=0;i<m;++i) {
            if(p_table.find(arr[i]) != p_table.end()) {
                isFound = true;
            } else {
                isFound = false;
            }
            int table_size = (int)p_table.size();
            
            if(!isFound && table_size<n) {
                faults++;
                p_table.insert(arr[i]);
            } else if(!isFound && table_size == n) {
                faults++;
                int farther = findFarthest(p_table, arr, i, m);
                p_table.erase(farther);
                p_table.insert(arr[i]);
            }
        }
        cout<<faults<<endl;
        
    }
    
    return 0;
}
