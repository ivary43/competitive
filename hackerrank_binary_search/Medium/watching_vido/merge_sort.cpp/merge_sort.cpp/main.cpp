#include<iostream>
using namespace std;
void mergeArray(int arr[],int ar1_start, int ar1_end, int ar2_start, int ar2_end) {
    int n = ar1_end - ar1_start + 1;
    int m = ar2_end -ar2_start + 1;
    
    int arr1[n];
    int arr2[m];
    int j=0;
    for(int i=ar1_start;i<=ar1_end;++i) {
        arr1[j++]=arr[i];
    }
    
    j=0;
    for(int i=ar2_start;i<=ar2_end;++i) {
        arr2[j++]=arr[i];
    }
    
    int start = ar1_start;
    int ptr1 =0, ptr2 =0;
    for(int i=0;i<n+m;++i) {
        
        if(ptr2>=m ) {
            arr[start++]=arr1[ptr1++];
        } else if(ptr1>=n) {
            arr[start++]=arr2[ptr2++];
        } else {
            if((arr1[ptr1] < arr2[ptr2]) ) {
                arr[start++]=arr1[ptr1++];
            } else {
                arr[start++]=arr2[ptr2++];
            }
        }
        
    }
}

void mergeSort(int arr[],int low, int high) {
    int mid = (high+low)>>1;
    
    if(low<high) {
        mergeSort(arr, low, mid) ;
        mergeSort(arr, mid+1,high);
        mergeArray(arr,low,mid,mid+1,high);
    } else {
        return;
    }
    
    
}

int main() {
    int n;
    cin>>n ;
    int arr[n];
    
    for(int i=0;i<n;++i) {
        cin>>arr[i];
    }
    
    mergeSort(arr, 0,n-1);
    
    for(int i=0;i<n;++i) {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
