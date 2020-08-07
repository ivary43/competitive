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

	while(T--) {
		int n;
		cin>>n ;


		int pos_one  = -1;
		vector<int>temp(n);

		for( int i=0;i<n;++i) {
			cin>>arr[i];
			if(arr[i] == 1) {
				pos_one = i;
			}
		}

		if(n==1) {
			cout<<"YES\n";
			continue;
		}


		int next = (pos_one+1)%n;

		bool isForward = false;

		if(arr[next] == 2) {
			isForward = true;
		}

		bool isPoss = true;
		int expected = 1;
		int pos = pos_one;

		if(isForward) {
			for(int i=0;i<n;++i){
				if(arr[pos] != expected) {
					isPoss = false;
					break;
				}
				pos=(pos+1)%n;
				expected++;
			}
		} else {
			for(int i=0;i<n;++i){
				if(arr[pos] != expected) {
					isPoss = false;
					break;
				}

				pos=(pos-1);
				if(pos<0) pos = n-1;
				expected++;
			}
		}


		if(!isPoss) {
			cout<<"NO\n";
		} else {
			cout<<"YES\n";
		}

	}
	return 0;
}