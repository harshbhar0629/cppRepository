// https://leetcode.com/problems/maximum-number-of-alloys/description/
#include <iostream>
#include <vector>
using namespace std;


#define ll long long int
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        ll ans = 0;
        for(int i=0; i<k; i++){
            int start =0 ,end = 3*1e8;
            ll mid = start + (end-start)/2;
            while(start<=end){
                ll bud = budget;
                for(int j=0; j<n; j++){
                    ll req = composition[i][j];
                    req*=mid;
                    req-=stock[j];
                    req = max(0ll , req);
                    if(req==0ll) continue;
                    req = req* cost[j];
                    if(req > bud){
                        bud=-1;
                        break;
                    }
                    bud-=req;
                }
                if(bud!=-1){
                    ans = max(ans , mid);
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
                mid = start + (end-start)/2;    
            }
        }
        return ans;
    }
};


int main(){
    

    return 0;
}