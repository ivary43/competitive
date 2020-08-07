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

	map<int,vector<int>> mp;
	vector<int> v1 {1,2,3,4,5,6,7,8,9,0};
	vector<int> v2 {2,4,6,8,0};
	vector<int> v3 {3,6,9,2,5,8,1,4,7,0};
	vector<int> v4 {4,8,2,6,0};
	vector<int> v5 {5,0};
	vector<int> v6 {6,2,8,4,0};
	vector<int> v7 {7,4,1,8,5,2,9,6,3,0};
	vector<int> v8 {8,6,4,2,0};
	vector<int> v9 {9,8,7,6,5,4,3,2,1,0};

	for (int i=1;i<v1.size();++i ){
		v1[i]+=v1[i-1];
	}
	for (int i=1;i<v2.size();++i ){
		v2[i]+=v2[i-1];
	}
	for (int i=1;i<v3.size();++i ){
		v3[i]+=v3[i-1];
	}
	for (int i=1;i<v5.size();++i ){
		v5[i]+=v5[i-1];
	}
	for (int i=1;i<v6.size();++i ){
		v6[i]+=v6[i-1];
	}
	for (int i=1;i<v7.size();++i ){
		v8[i]+=v8[i-1];
	}
	for (int i=1;i<v9.size();++i ){
		v9[i]+=v9[i-1];
	}
	for (int i=1;i<v4.size();++i ){
		v4[i]+=v4[i-1];
	}
	for (int i=1;i<v8.size();++i ){
		v8[i]+=v8[i-1];
	}				
	mp[1] = v1;
	mp[2] = v2;
	mp[3] = v3;
	mp[4] = v4;
	mp[5] = v5;
	mp[6] = v6;
	mp[7] = v7;
	mp[8] = v8;
	mp[9] = v9;



	while(T--) {
		long long int n,m ;

		cin>>n>>m;

		int l_d = m%10;
		if(l_d == 0) {
			cout<<0<<"\n";
			continue;
		}

		vec<int> temp = mp[l_d];
		long long int div = n/m;
		
		long long int dv = div/(temp.size());
		int rem = div%(temp.size());

		

		long int res = 0;
		res+=((ll)temp[temp.size()-1]*dv);
		if(rem) {
			res+=temp[rem-1];
		}
		cout<<res<<"\n";

	}

	return 0;
}