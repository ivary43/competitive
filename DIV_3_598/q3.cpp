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


int main() {
    SYNC
    
	int n, m, d;

	cin>>n>>m>>d ;

	int arr[m];
	int sm = 0;

	for(int i=0;i<m;++i) {
		cin>>arr[i];
		sm+=arr[i];
	}

	bool isWood[n];
	bool isPlaced[n];
	
	memset(isWood, false, sizeof(isWood));
    memset(isPlaced, false, sizeof(isPlaced));
	vector<int> res(n,0);

	int ptr = 0;

	int __diif = n-sm ;

	int k = n-1;

	for(int i=m-1;i>=0;--i) {
		int start = k ;
		int end = k - arr[i];

		for(int j=start; j>end;--j) {
			isWood[j] = true;
			res[j] = i+1;
			k--;
		}		

	}

	int currPos = - 1;
	bool isPoss = true ;

	for(int i=0;i<n;++i) {

		if(currPos+d>= n) {
			break ;
		}


		if(!isWood[currPos+d] && ptr<m) {
			//add a log there
			int strt = currPos+d;
			int end = currPos+d+arr[ptr];

			currPos = currPos+d-1;

			for(int j=strt;j<end;++j) {
				res[j] = ptr+1;
				isPlaced[j] = true;
				currPos++;
			}

			// remove the log from last
			strt = __diif ;
			end = __diif+arr[ptr];

			for(int j=strt;j<end;++j) {
			    
			    if(!isPlaced[j]) {
			       isWood[j] = false;
				   res[j] = 0; 
			    }
				
				__diif++;
			}

			ptr++;
		} else if(!isWood[currPos+d] && ptr>=m) {
			isPoss = false ;
			break;
		}
	}

	if(isPoss) {
		cout<<"YES\n";
		for(int i=0;i<n;++i){
			cout<<res[i]<<" ";
		}
	} else {
			cout<<"NO\n";
	}

	return 0;
}