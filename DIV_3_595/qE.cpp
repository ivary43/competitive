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


int dp(int a[],int b[], int c,int n, bool is_str) {

	if(n == 0) {
		return 0;
	} else {
		int ext = (is_str)?c:0;
		return min(a[n-1]+dp(a,b,c,n-1), b[n-1]+ext+dp(a,b,c,n-1));
	}

}

int main() {

	int n, c;

	cin>>n>>c ;

	int a[n-1];
	int b[n-1]

	for(int i=0;i<n-1;++i) {
		cin>>a[i];
	}

	for(int i=0;i<n-1;++i) {
		cin>>b[i];
	}


	for(int i=1;i<=n;++i) {
		cout<<min(dp(a,b,c,i,false), c+dp(a,b,c,i,true));
	}

 	return 0;
}