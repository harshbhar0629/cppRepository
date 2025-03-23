#include <bits/stdc++.h>
using namespace std;
// ques print subset
// 3 terms 1. subset
// 2. subsequence 
// 3. subarray -> array 
// 4. string -> substring

// {0,1, 2, 3,4} => {4,3} // subset order not matters
// {0,1, 2, 3,4} => {3, 4} // subseq order not matters
// {0,1 2, 3,} => subarray continuous order {0,1} right
// {0,2}

void printSubset(int i, vector<int>&v, vector<int>extra){
    if(i==v.size()){
        for(int i=0; i<extra.size(); i++){
            cout << extra[i] << " ";
        }
        cout<<"\n";
        return;
    }

    // pick notpick strategy
    printSubset(i+1, v, extra); //skip
    extra.push_back(v[i]);
    printSubset(i+1, v, extra); //pick wala case
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    vector<int> extra;

    printSubset(0, v, extra);

    return 0;
}