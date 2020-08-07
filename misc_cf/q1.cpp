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


	int n ,a , b;
	cin>>n>>a>>b ;

	bool isL = (b<0)?true:false ;

	b= abs(b);
	b = b%n;

	if(!isL) {
		int x = (a+b)%n;
		x = (x == 0)?n:x;
		cout<<x<"\n";
	} else {
		int x = a-b;
		if(x >0) {
			cout<< x<<"\n";
		} else {
			cout<<x+n<<"\n";
		}
	}

	return 0;
}