#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
     
        long long ans=0;
        priority_queue<int> pq;
        for(int ele: nums){
            pq.push(ele);
        }

        while(k-- and pq.size()){
            int x = pq.top();
            pq.pop();            
            ans += x;
            if(x%3==0){
                x = x/3;
            }
            else{
                x = x/3 + 1;
            }
            pq.push(x);
        }
        return ans;
    }
};

int main(){
    int x = 10;
    x = ceil((double)x/3);
    cout<<x;
}