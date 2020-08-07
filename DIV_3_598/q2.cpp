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

	int T;
	cin>>T;

	while(T--) {
			int n;
			cin>>n;

			int arr[n];
			bool isVis[n];
			memset(isVis, false, sizeof(isVis));
			unordered_map<int,int> mp;

			for(int i=0;i<n;++i) {
				cin>>arr[i];

				mp.insert(make_pair(arr[i],i));
			}

			int __x = n-1;

			for(int i=1;i<=n;++i) {

				if(mp[i] !== i-1) {					
					while((mp[i]!=i-1)&&__x>0) {
						int pos = mp[i];

						if(!isVis[pos-1]) {
							mp[arr[pos-1]]+=1;
							mp[arr[pos]]-=1;
							swap(arr[pos], arr[pos-1]);
							__x--;
						} else{
							break;
						}

					}

				}

				if(__x<=0) break;
			}

			for(int i=0;i<n;++i) {
				cout<<arr[i]<<" ";
			}

			cout<<endl;
	}


	return 0;
}