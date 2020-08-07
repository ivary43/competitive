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
			cin>>n;
			vector<int> arr(n);
			vector<int> pre(n);

			for(int i=0;i<n;++i) {
				cin>>arr[i];

			}	

			pre[n-1]=arr[n-1];

			int res = 0;	
			for(int i=n-2;i>=0;--i) {

				if(arr[i]<pre[i+1]) {
					pre[i] = arr[i];
				} else if(arr[i]>pre[i+1]){
					res++;
					pre[i] = pre[i+1];
				} else {
					pre[i] = arr[i];
				}
			}

			cout<<res<<endl;
	}

	return 0;
}