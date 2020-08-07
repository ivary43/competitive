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

int main() {


	int T;
	cin>>T;


	while(T--) {
		int n ;

		bool isPoss = true;
		stack<int> st;
		cin>>n;

		int dup = n;

		while(dup!=0) {
			int x = dup%3 ;

			if(x ==2) {
				isPoss = false;
			}

			st.push(x);
			dup/=3;
		}

		if(isPoss) {
			cout<<n<<"\n";
			continue;
		}

		int carry = 0 ;
		int res = 0;

		int i = 0 ;

		while(!st.empty()) {
			int x = st.top();
			st.pop();

			int y = x;

			if(x==2 || carry+x ==2) {
				y = 0;
				carry = 1;
			} else {
				y = x+carry;
			}

			res+=(y*(int)powl(3,i));
			i++;
		}

		if(carry) {
			res+=(int)powl(3,i);
		}

		cout<<res<<endl;
	}

	return 0;
}