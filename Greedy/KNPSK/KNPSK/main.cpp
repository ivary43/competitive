#include "/Users/manishkumar/Work/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
int main() {
    
    vector<int> ar1 ;
    vector<int> ar2 ;
    int N ,wt,c;
    cin>>N ;
    int sum = 0 ;
    for(int i=0;i<N;++i) {
        cin>>wt>>c ;
        if(wt == 1) {
            ar1.push_back(c);
        } else {
            ar2.push_back(c);
        }
        sum+=wt;
    }

    sort(ar1.begin(), ar1.end(), greater<int>());
    sort(ar2.begin(), ar2.end(), greater<int>());
    int odd_prev = 0;
    int even_prev = 0 ;
    
    int even_sum_prev_1_pointer = 0 ;
    int even_sum_prev_2_pointer = 0 ;
    int odd_sum_prev_1_pointer = 0 ;
    int odd_sum_prev_2_pointer = 0 ;
    
    if(ar1.size()>0) {
        odd_prev = ar1[0];
        odd_sum_prev_1_pointer++;
    }
    cout<<odd_prev<<" ";
    int ar1_size = (int)ar1.size();
    int ar2_size = (int)ar2.size();
    if(ar1.size()>=2 && ar2.size() == 0) {
        even_prev=ar1[0]+ar1[1];
        even_sum_prev_1_pointer+=2;
    } else if(ar1.size()>=2 && ar2.size() >=1) {
        if(ar1[0]+ar1[1] > ar2[0]) {
            even_prev = ar1[0]+ar1[1];
            even_sum_prev_2_pointer++;
        } else {
            even_prev = ar2[0];
            even_sum_prev_2_pointer++;
        }
    }
//    else if (ar1_size>=1 && ar2_size == 0  ) {
//
//
//    } else if(ar1_size >= 1 && ar2_size == 1) {
//
//    }
    else {
        even_prev = ar2[0];
        even_sum_prev_2_pointer++;
    }
    cout<<even_prev<<" ";
    
    for(int i=3;i<=sum;++i) {
        if(i%2==1) {
            if(odd_sum_prev_1_pointer+1< ar1_size && odd_sum_prev_2_pointer < ar2_size) {
                if(ar1[odd_sum_prev_1_pointer]+ar1[odd_sum_prev_1_pointer+1] > ar2[odd_sum_prev_2_pointer]) {
                    odd_prev+=(ar1[odd_sum_prev_1_pointer]+ar1[odd_sum_prev_1_pointer+1]);
                    odd_sum_prev_1_pointer+=2;
                } else {
                    odd_prev+=(ar2[odd_sum_prev_2_pointer]);
                    odd_sum_prev_2_pointer++;
                }
            } else if(odd_sum_prev_1_pointer+1< ar1_size && odd_sum_prev_2_pointer >= ar2_size) {
                odd_prev+=(ar1[odd_sum_prev_1_pointer]+ar1[odd_sum_prev_1_pointer+1]);
                odd_sum_prev_1_pointer+=2;
            } else if(odd_sum_prev_1_pointer+1 == ar1_size && odd_sum_prev_2_pointer>= ar2_size) {
                odd_prev+=ar1[odd_sum_prev_1_pointer];
                odd_sum_prev_1_pointer++;
            } else if (odd_sum_prev_1_pointer+1 == ar1_size && odd_sum_prev_2_pointer +1 == ar2_size) {
                if(ar1[odd_sum_prev_1_pointer]> ar2[odd_sum_prev_2_pointer]) {
                    odd_prev+=(ar1[odd_sum_prev_1_pointer]);
                    odd_sum_prev_1_pointer++;
                } else {
                     odd_prev+=(ar1[odd_sum_prev_2_pointer]);
                       odd_sum_prev_2_pointer++;
                }
            } else {
                odd_prev+=(ar2[odd_sum_prev_2_pointer]);
                odd_sum_prev_2_pointer++;
            }
            cout<<odd_prev<<" ";
        } else {
            
            if(even_sum_prev_1_pointer+1< ar1_size && even_sum_prev_2_pointer < ar2_size) {
                if(ar1[even_sum_prev_1_pointer]+ar1[even_sum_prev_1_pointer+1] > ar2[even_sum_prev_2_pointer]) {
                    even_prev+=(ar1[even_sum_prev_1_pointer]+ar1[even_sum_prev_1_pointer+1]);
                    even_sum_prev_1_pointer+=2;
                } else {
                    even_prev+=(ar2[even_sum_prev_2_pointer]);
                    even_sum_prev_2_pointer++;
                }
            }  else if(even_sum_prev_1_pointer+1< ar1_size && even_sum_prev_2_pointer >= ar2_size) {
                even_prev+=(ar1[even_sum_prev_1_pointer]+ar1[even_sum_prev_1_pointer+1]);
                even_sum_prev_1_pointer+=2;
            } else if(even_sum_prev_1_pointer+1 == ar1_size && even_sum_prev_2_pointer>= ar2_size) {
                even_prev+=ar1[even_sum_prev_1_pointer];
                even_sum_prev_1_pointer++;
            } else if (even_sum_prev_1_pointer+1 == ar1_size && even_sum_prev_2_pointer+1 == ar2_size) {
                if(ar1[even_sum_prev_1_pointer]> ar2[even_sum_prev_2_pointer]) {
                    even_prev+=(ar1[even_sum_prev_1_pointer]);
                    even_sum_prev_1_pointer++;
                } else {
                    even_prev+=(ar1[even_sum_prev_2_pointer]);
                    even_sum_prev_2_pointer++;
                }
            }else {
                even_prev+=(ar2[even_sum_prev_2_pointer]);
                even_sum_prev_2_pointer++;
            }
            cout<<even_prev<<" ";
            
        }
        
    }
    
    
    
    
    
    return 0;
}
