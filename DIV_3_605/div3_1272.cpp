#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int T;
	cin>>T;

	while(T--) {
		int arr[3];

		for(int i=0;i<3;++i) {
			cin>>arr[i];
		}

		sort(arr, arr+3);
		int a[] = {arr[0], arr[0]-1, arr[0]-2} ;
		int b[] = {arr[1], arr[1]-1, arr[1]-2} ;
		int c[] = {arr[2], arr[2]-1, arr[2]-2} ;

		long long int res = LLONG_MAX;

		for(int a_:a) {
			for(int b_:b) {
				for(int c_:c) {
					long long int temp = (ll)abs(a-b)+(ll)abs(a-c)+(ll)abs(c-b);
					res = min(res, temp);
				}
			}
		}

		cout<<res<<"\n";


	}

	return 0;
}