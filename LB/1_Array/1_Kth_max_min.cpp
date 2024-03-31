#include <bits/stdc++.h>
using namespace std;


int solve(vector<int>&v, int k){
    
    int n = v.size();
    priority_queue<int,vector<int>,greater<int>>pq;
    k = k%n;
    for(int i=0; i<n; i++){
        if(pq.size()<k){
            pq.push(v[i]);
        }
        else if(pq.top()<v[i]){
            pq.pop();
            pq.push(v[i]);
        }
    }
    return pq.top();
}

// int solve2(vector<int>&v, int k){
//     int n = v.size();
//     p
    
// }


int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int k;
    cin>>k;

    cout<<solve(v,k);

    return 0;
}