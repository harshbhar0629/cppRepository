#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
       
        priority_queue<int>pq;
        int mini = INT_MAX,ans = INT_MAX;
     
        for(int ele: nums){
            if(ele % 2 !=0) ele *=2;
            mini = min(mini,ele);
            pq.push(ele);
        }

        while(pq.top() % 2 ==0){
            int val = pq.top();
            pq.pop();
            ans = min(ans, val - mini);
            mini = min(mini,val/2);
            pq.push(val/2);
          
        } 
        ans = min(ans,pq.top() - mini);
        return ans;
    }
};
int main(){
    vector<int>arr={2,10,8};
    int n = arr.size();
    int deviation=INT_MAX;
   
    for(int i=0;i<n;i++){
        int mini=INT_MAX,mIdx=0;
        int maxi = INT_MIN,idx=0;
      
        for(int j=0;j<n;j++){
       
            if(mini>arr[j]){
                mIdx=j;
                mini = arr[j];
            }
            if(maxi<arr[j]){
                maxi = arr[j];
                idx =j;
            }
        }
     
        deviation = min(deviation,maxi-mini);
        int prevMaxi = maxi;
        int prevMini = mini;
        if(maxi%2==0){
            while(maxi%2==0){
                maxi/=2;
            }
        }
        if(mini%2==1){
            mini *=2;
        }
        arr[mIdx] = mini;
        arr[idx]=maxi;
        if(maxi>mini)
        deviation=min(deviation,maxi-mini);
        if(prevMaxi==maxi and mini == prevMini) break;
    }
    cout<<deviation;
}
