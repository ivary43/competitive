#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
string s1, s2 ;
map<pair<int,int>,bool> mp ;

bool isPoss(int x, int y, int prev_x , int prev_y) {
    
    pair<int,int> pr = {x,y};
    
    if(mp.find(pr) !=mp.end()) {
        return mp[pr];
    }    
    
    if(x == -1 && y!=1 ) {
        return false;
    }
    
	if(x == -1 && y == 1) {
		return true ;
	} else {

		if( y== 1) {
			if(s1[x]-'0'>=3 && prev_y == 1) {
				bool temp = isPoss(x,y+1,x,y);
				mp[pr] = temp;     
				return temp;
			} else if(s1[x]-'0'<=2 &&  prev_y== 1) {
				bool temp =  isPoss(x-1, y,x,y);
				mp[pr] = temp;     
				return temp;
			} else if(s1[x]-'0'>=3 && prev_y ==2){
				bool temp = isPoss(x-1,y,x,y);
				mp[pr] = temp;     
				return temp;
			} else {
				return false;
			}

		} else {

			if(s2[x]-'0'>=3 && prev_y == 2) {
				bool temp = isPoss(x,y-1, x,y);
				mp[pr] = temp;     
				return temp;
			} else if(s2[x]-'0'>=3 && prev_y == 1 ) {
				bool temp = isPoss(x-1, y, x, y);
				mp[pr] = temp;     
				return temp;
			} else if( s2[x]-'0' <=2 && prev_y == 2) {
				bool temp = isPoss(x-1,y,x,y);
				mp[pr] = temp;     
				return temp;
			} else {
				return false;
			}

		}
	}
}


int main() {

	int T;
	cin>>T;

	while(T--) {
		int n;
		cin>>n ;

		cin>>s1>>s2 ;
		if(isPoss(n-1,2, n, 2)) {
		    cout<<"YES\n";
		} else {
		    cout<<"NO\n";
		}
		mp.clear();
	}


	return 0;

}
