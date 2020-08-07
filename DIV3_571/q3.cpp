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

	int n;
	cin>>n;

	long long int x;	
	long long int gcd_val ;

	cin>>gcd_val;

	for(int i=1;i<n;++i) {
	    cin>>x;
		gcd_val = __gcd(gcd_val,x);
		
	}

	long long int count = 0;
    long long int _n = sqrt(gcd_val);
        
    
    
	for(long long int i=1;i<=_n;++i) {
		if(gcd_val%i==0) {
		       if(gcd_val/i == i) {
		           count++;
		       } else {
		           count+=2;
		       }
		}
	}
	
	cout<<count<<"\n";
	return 0;

}