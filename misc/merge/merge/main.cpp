#include "/Users/manishkumar/Work/stdc++.h"
//#include<bits/stdc++.h>

using namespace std ;
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ll long long int
#define vi vector<int>
#define mp make_pair

int cnt = 0 ;

void mergeA(int l, int m ,int r, int arr[]){
    
    int n1 = m - l+1 ;
    int n2 = r-m ;
    
    int R[n1] , L[n2] ;
    
    for(int i=0;i<n1;++i){
        L[i] = arr[l+i] ;
    }
    
    for(int i=0;i<n2;++i){
        R[i] = arr[m+1+i] ;
    }
    
    
    int k =l ;
    int ptr1 = 0;
    int ptr2 = 0;
    while(ptr1<n1 && ptr2<n2){
        
        if(L[ptr1] < R[ptr2]){
            arr[k] = L[ptr1] ;
            ptr1++;
        } else {
            cnt+=(n1-ptr1);
            arr[k] = R[ptr2];
            ptr2++;
        }
        k++;
    }
    
    
    while(ptr1<n1){
        arr[k]=L[ptr1];
        ptr1++;
        k++;
    }
    
    while(ptr2<n2){
        arr[k]=R[ptr2];
        ptr2++;
        k++;
    }
    
    
}

void mergeSort(int arr[], int l,int r){
    
    
    if(l == r) {
        return ;
    }
    
    int mid = (l+r)>>1 ;
    mergeSort(arr,l,mid);
    mergeSort(arr, mid+1, r);
    
    
    mergeA(l,mid,r,arr);
    
    
    
}


int main() {
    
    int n ;
    cin>>n ;
    
    int arr[n] ;
    
    for(int i=0;i<n;++i){
        cin>>arr[i] ;
    }
    
    mergeSort(arr, 0, n-1);
    
    
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" " ;
    }
    
    cout<<"\n"<<cnt<<endl;
    
    return 0;
}
