#include <bits/stdc++.h>
using namespace std;
// 

#define ll long long int

ll minCostToConnect(vector<int>& sticks){
    int n = sticks.size();
    ll cost = 0;
    priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());

    while(pq.size()>1){
        int top1 = pq.top();
        pq.pop();
        int top2 = pq.top();
        pq.pop();
        pq.push(top1 + top2);
        cost += top1 + top2;
    }
    
    return cost;
}

int main(){
    int n;
    cin>>n;

    vector<int>sticks(n);
    for (int i = 0; i<n; i++){
        cin >> sticks[i];
    }

    cout << minCostToConnect(sticks);

    return 0;
}