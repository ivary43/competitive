    #include "/Users/manishkumar/Work/stdc++.h"
    //#include <iostream>
    using namespace std;
    template<typename It>
    bool nextPermutation( vector<int> arr) {
        It i = arr.begin();
        if(arr.begin() == arr.end()) return false;
        if((i+1) == arr.end()) return false; // only one element present
        
        It begin = arr.begin();
        It end = arr.end();
        
        i = arr.end();
        --i;
        
        while(true){
            It j = i;
            --i;
            if(*i < *j){
                It k = end;
                // find the next greater element
                while(!(*(--k) > *i)) ;
                iter_swap(k, i);
                reverse(j, end);
                string res="";
                for(It x=arr.begin();x!=arr.end();++x) {
                    res+=('0'+*x);
                }
                cout<<res<<endl;
                return true;
            }

            if(i==begin) {
                return false;
            }
            
        }
    }


    int main() {
        
        int T;
        cin>>T;
        while(T--) {
            int n ;
            cin>>n ;
            vector<int> arr(n);
            for(int i=0;i<n;++i){
                cin>>arr[i];
            }
            bool result = nextPermutation<vector<int>::iterator>(arr);
            if(!result) cout<<-1<<endl;
        }
        return 0;
    }
