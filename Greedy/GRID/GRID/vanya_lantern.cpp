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

bool isOk(int arr[], double d, int _l,int n) {
	if(1.0*arr[0]>d) {
		return false ;
	} 

	for(int i=1;i<n;++i) {
		if( (double)(arr[i] - arr[i-1]) > (2.0)*d ) {
			return false;
		}
	}

	if(_l - arr[n-1]>d) {
		return false;
	}

	return true;

}



int main() {

	int n , _l ;
	cin>>n>>_l;

	int arr[n];
	rep(i,n) cin>>arr[i];

	sort(arr, arr+n);

	double l = 0.0 ;
	double r = _l ; 

	for(int i=0;i<50 ;++i) {
		double mid = (l+r)>>1 ;

		if(isOk(arr, mid,_l, n)){
			r = mid;
		} else {
			l = mid;
		}
	}

	printf("%.9d\n", r);
	return 0;
}