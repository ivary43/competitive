#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
map<int,long long int> fact_d;

long long int factorial(int val, int prime) {
	if(fact_d.find(val)!=fact_d.end()) return fact_d[val];

	if(val == 0) {
		return 1;
	} else {
		long long int temp =  (1ll*val*(factorial(val-1, prime)%prime))%prime;
		fact_d[val] = temp ;
		return temp;	 
	}
}


int main() {
	int n , m;

	cin>>n>>m ;

	long long int res = 0;

	for(int l=1;l<=n;++l) {
		res+=(((1ll)(n-l+1))*factorial(l,m)*factorial(n-l+1))%m;
		res%=m;
	}

	cout<<res<<"\n";
	return 0;
}