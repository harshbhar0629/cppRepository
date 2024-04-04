#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// https://www.interviewbit.com/problems/painters-partition-problem/

bool isPossible(ll A, ll mid, vector<int>& c){
    int cnt=1;    
    ll sum=0;
    
    for(int i=0; i<c.size(); i++){
        if(sum + c[i] <= mid){
            sum += c[i];
        }
        else{
            sum = c[i];
            cnt++;
        }
    }
    
    return cnt<=A;
}

int paintPartition(int A, int B, vector<int> &C) {
    ll ans=0;
    ll lo = 0;
    ll hi = 0;
    int n = C.size();
    for(int i=0; i<n; i++){
        lo = max(lo, C[i]*1ll);
        hi += C[i];
    }
    
    if(n<=A){
        return (lo*B)%10000003;
    }
    
    while(lo<=hi){
        ll mid = lo +(hi-lo)/2;
        if(isPossible(A, mid, C)){
            ans = (mid*B)%10000003;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }

    return ans % 10000003;
}


int main(){
    

    return 0;
}