#include "/Users/manishkumar/Work/stdc++.h"
//#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
#define mp make_pair

bool cmp( pair<int, int> a, pair<int, int> b )
{
    if( a.first == b.first ) return  a.second < b.second ;
    else return a.first < b.first;
}

int main()
{
    SYNC
    int t;
    scanf("%d", &t);
    
    while(t--) {
        int n;
        scanf("%d", &n);
        vector< pair<int, int> > dolls;
        for(int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            dolls.push_back(make_pair(x, y));
        }
        
        sort( dolls.begin(), dolls.end(), cmp );
        
        vector< pair<int, int> > v2;
        v2.push_back( dolls[n - 1] );
        
        for(int i=n-2;i>=0;--i) {
            
            int low = 0 ;
            int high = (int)v2.size()-1;
            
            while(low<high) {
                int mid = (low+high)>>1;
                if( (dolls[i].first <= v2[mid].first) && (dolls[i].second <= v2[mid].second)) {
                    high=mid ;
                } else {
                    low = mid+1;
                }
            }
            
            if( (dolls[i].first <= v2[low].first) && (dolls[i].second <= v2[low].second)) {
                v2[low].first = dolls[i].first ;
                v2[low].second = dolls[i].second ;
            } else {
                v2.push_back(dolls[i]);
            }
            
        }
        cout<<v2.size()<<endl;
        
    }
    
    return 0;
}
