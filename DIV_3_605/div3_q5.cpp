#include<bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin>>n;

	int arr[n];

	int l[n], r[n];

    
    for(int i=0;i<n;++i){
            cin>>arr[i];
            r[i] = 1 ;
            l[i] = 1;
    }
    
    int res = 1;

    for(int i=1;i<n;++i) {
    	if(arr[i]>arr[i-1]) {
    		r[i]=r[i-1]+1;
    		res = max(res, r[i]);
    	}
    }

    for(int i=n-2;i>=0;--i) {
    	if(arr[i]<arr[i+1]) {
    		l[i]=l[i+1]+1;
    		res = max(res, l[i]);
    	}
    }

    for (int i = 0; i < n - 2; ++i) {
		if (arr[i] < arr[i + 2]) res = max(res, r[i] + l[i + 2]);
	}

	

	cout<<res<<endl;
	
	return 0;
}