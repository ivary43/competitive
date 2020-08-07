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

const int N = 200004;
vector<int> qr ;

int greq(int key) {

	int l = 0;
	int r = qr.size()-1;

	while(l<r) {
		int mid = (l+r)>>1;
		if(qr[mid] >= key) {
			r = mid;
		} else {
			l = mid+1;
		}
	}
	return r;
}

int leq(int key) {

	int l = 0;
	int r = qr.size() -1;

	while(l<r) {
		int mid  = (l+r+1)>>1;

		if(qr[mid]<= key) {
			l = mid ;
		} else {
			r= mid -1;
		}
	}
	return l;
}

int main() {

	int n, k, q;

	cin>>n>>k>>q ;
	vector<int>(N, 0) pre;

	int x, y;
	for(int i=0;i<n;++i) {
		cin>>x>>y;
		pre[x]++;
		--pre[y+1];
	}

	for(int i=1;i<N;++i) {
		pre[i]+=pre[i-1];

		if(pre[i]>=k) qr.push_back(i) ;
	}

	int _n = qr.size();

	for(int i=0;i<q;++i) {
		cin>>x>>y ;

		if(_n == 0) {
			cout<<0<<"\n";
			continue;
		}

		int l = greq(x);
		int r = leq(y);

		if(qr[l]< x || qr[r] > y) {
			cout<<0<<"\n";
			continue;
		}
		cout<<r-l+1<<"\n";
	}

	return 0;
}