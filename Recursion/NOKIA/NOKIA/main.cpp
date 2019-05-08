    #include "/Users/manishkumar/Work/stdc++.h"
    //#include <bits/stdc++.h>
    using namespace std;
    int main() {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int T ;
        cin>>T ;
        vector<pair<int,int>> ref(31);
        ref[0] = {0,0};
        ref[1] = {2,2};
        ref[2] = {5,5};
        for(int i=3;i<31;++i) {
            ref[i].second = (((i+1)*(i+2))/2) - 1; //max
            if(i%2 == 1) {
                ref[i].first  = (i+1)+ (2*ref[i/2].first);
            } else {
                ref[i].first = (i+1) + ref[i/2].first + ref[(i/2)-1].first ;
            }
        }
        
        
        
        
        while(T--) {
            int n , m ;
            cin>>n>>m;
            if(m < ref[n].first ) {
                cout<<-1<<endl;
            } else if (m >= ref[n].first && m <= ref[n].second ){
                cout<<0<<endl;
            } else {
                cout<<m - ref[n].second <<endl;
            }
            
        }
        
        
     
        return 0;
    }
