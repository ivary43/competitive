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
 
	SYNC;
	int n;
	cin>>n ;
	set<int> no_send ;
 
	int arr[n] ;
 
	bool is_rec[n];
 
	memset(is_rec, false, sizeof(is_rec));
 
	for(int i=0;i<n;++i) {
		cin>>arr[i];
		arr[i]--;
 
		if(arr[i]>=0 ) {
			is_rec[arr[i]] = true;
		} else {
			no_send.insert(i);
		}
	}
 
	for(int i=n-1;i>=0;--i) {
		if(!is_rec[i]) {
			auto it = no_send.begin() ;
			if(*it == i) ++it;
			
		//	cout<<*it<<"-\n";
			arr[*it] = i;
			no_send.erase(it);
			is_rec[i] = true;
		}
 
	}
 
	for(int i=0;i<n;++i) {
		cout<<arr[i]+1<<" ";
	}
 
	cout<<"\n";
	return 0;
}