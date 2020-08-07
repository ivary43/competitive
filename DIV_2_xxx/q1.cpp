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

	int n,m ;
	cin>>n>>m ;

	vector<string> s1(n);
	vector<string> s2(m);

	for(int i=0;i<n;++i) {
		cin>>s1[i];
	}

	for(int i=0;i<m;++i) {
		cin>>s2[i];
	}


	int q;
	cin>>q ;

	while(q--) {
		int t;
		cin>>t ;

		int n_ = (t)%n ;
		int m_ = (t)%m;

		n_ = (n_ == 0)?n:n_;
		m_ = (m_ == 0)?m:m_;

		n_--;
		m_--;

		cout<<s1[n_]+s2[m_]<<"\n";
	}

	return 0;
}