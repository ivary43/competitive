#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
#define mp make_pair
map<pair<int,int>, int> ump;
vector<int> config ;
vector<int> temp_c ;
vector<pair<int,int>>  arr;
int __n ;
 
int solve(int n, int ind, int grp_no) {
    
    if(ump.find(make_pair(n, ind))!=ump.end()) {
        return ump[make_pair(n,ind)];
    }
    
	if(n == 0) {
		return 0;
	} else {
 
		int res = INT_MAX ;
		for(int i=3;i<=5;++i) {
			if(n-i>=3 || n-i==0) {
			    
			    int x = (arr[ind].first -arr[ind-i+1].first)+solve(n-i, ind-i, grp_no+1) ;
				
				if(x<res) {
				    res = x;
				    for(int l=ind-i+1; l<=ind;++l) {
				            temp_c[l] = grp_no;
				    }
				    
				    if(n == __n) {
				        config = temp_c;
				    }
				}
				
			}
		}
        
        pair<int,int> temp = {n, ind};
        ump[temp] = res ;
		return res;
	}
}
 
int main() {
    SYNC
    
	int n ;
	cin>>n ;
    __n = n ;
    
	arr = vector<pair<int,int>>(n);
	
    config = vector<int>(n,0);
    temp_c = vector<int>(n,0);
    
	for(int i=0;i<n;++i) {
	    
	    cin>>arr[i].first ;
	    arr[i].second = i;
	}
 
	sort(arr.begin(), arr.end());
	int x = solve(n,n-1, 1);
	
	vector<int> resx(n);
	
	for(int i=0;i<n;++i) {
	    resx[arr[i].second] = config[i];        
	}
	
	cout<<x<<" "<<config[0]<<endl;
	
	for(int i=0;i<n;++i) {
	    cout<<resx[i]<<" ";
	}
	
	return 0;
}