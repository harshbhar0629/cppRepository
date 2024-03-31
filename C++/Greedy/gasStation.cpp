#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(int x,int y){
        return x<y;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n =cost.size();
        int idx = 0,balance=0,deficiency=0;
        for(int i=0;i<n;i++){
           
            balance += gas[i] - cost[i];
            if(balance < 0){
                deficiency += balance;
                balance=0;
                idx = i+1;
            }
        }
     
        if(balance+deficiency >= 0) return idx;
        return -1;
    }
};

int main(){
    vector<int> gas = {2,3,4};
    vector<int> cost = {3,4,3};
    Solution s;
    cout<<s.canCompleteCircuit(gas,cost);

    return 0;
}