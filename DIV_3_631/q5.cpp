#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>

const int N = 200005;

int main() {

	vector<int> cnt(N,0);

	int n,x;
	cin>>n ;

	for(int i=0;i<n;++i) {
		cin>>x;
		cnt[x]++;
	}

	int min_val = 0;
	for(int i=0;i<N;++i) {
		if(cnt[i] != 0) {
			min_val++;
			i+=2;
		}
	}

	int max_val = 0;
	int carry = 0;

	for(int i=1;i<N-1;++i) {
		
		if(carry == 1 && cnt[i] == 0) {
			max_val++;
			carry = 0;
		} else if(cnt[i]!=0) {

			if(cnt[i-1]!=0) {
				cnt[i]--;
				max_val++;
			}

			if(cnt[i]+carry>1) {
				carry = 1;
			}
			if(cnt[i]) {
				max_val++;
			}

		} 	

	}

	cout<<min_val<<" "<<max_val<<"\n";


	return 0;
}