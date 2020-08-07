#include<bits/stdc++.h>
using namespace std;

int main() {

	int n , k;
	cin>>n>>k ;

	int arr[n];
	int maxx = 0 ;

	for(int i=0;i<n;++i) {
		cin>>arr[i];
	}

	if(n%2 == 1) {
		maxx = arr[n-1];
		n--;
	}

	int offset = k - (n/2) ;

	for(int i=n-1;i>n-i-1 ;--i){
			maxx = max(maxx, arr[i]);
	}

	for()







	return 0;
}