#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
//#include "~/Downloads/Header/stdc++.h"
#define pb push_back
#define ll long long int
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);
#define REP(i , n) for(int i =0 ; i < n ;i++)
#define ALL(v) v.begin(), v.end()
int modi =  998244353;
using namespace std;
void modify(vector<int> &filt, int l, int r) {
    for(int i=l-1;i<r;++i) {
        --filt[i];
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    int arr[n];
    vector<int> filt(n,0);
    REP(i,n) {
        cin>>arr[i];
    }
    int x,y;
    vector<pair<int,int>>  ci ;
    vector<pair<int,int>> :: iterator it;
    REP(i,m) {
        cin>>x>>y ;
        ci.pb(make_pair(x, y));
        modify(filt, x, y);
    }
    
    int index_val ;
    int max_val =INT_MIN;
    REP(i, n) {
        if(arr[i]-filt[i]>max_val) {
            max_val=arr[i]-filt[i];
            index_val=i;
        }
    }
    int q = abs(filt[index_val]);
    vector<pair<int,int>> res;
    REP(i, m) {
        if((index_val+1)>=ci[i].first &&(index_val+1)<=ci[i].second) {
            res.pb(ci[i]);
        }
    }
    cout<<max_val<<"\n"<<q<<endl;
    for(pair<int,int> p:res) {
        cout<<p.first<<" "<<p.second<<endl;
    }
    
    
    return 0;
}
