#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
 
 int main() {

 	int T;
 	cin>>T;

 	int m = 24*60 ;
 	while(T--) {

 		int h, m;
 		cin>>h>>m ;

 		int r = h*60 + m;
 		cout<<m-r<<"\n";
 	}
 	return 0;
 }