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

	int T;
	cin>>T;

	while(T--) {
		int n ;
		cin>>n>>k ;
		string s ;

		cin>>s ;

		int _n = s.length();

		queue<int> qu ;

		string res = "";

		for(int i=0;i<_n;++i) {
			if(s[i] == '0') {
				qu.push(i);
			}
			res+="1";
		}

		int ptr = 0;

		while(!qu.empty()) {
			int pos = qu.front();
			qu.pop();

			if(pos != ptr && k>0) {
				int diff = pos - ptr ;

				pos-=min(diff, k);
				k-=min(diff,k);

				res[pos] = '0';
				ptr++;
			}  else if(pos == ptr){
				res[pos] = '0';
				ptr++;
			} else {
				res[pos] = '0';
			}
		}


		cout<<res<<"\n";

	}
	return 0; 
}