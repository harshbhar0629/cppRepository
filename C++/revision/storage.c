class Solution {
public:
    bool f(vector<int>&v,int mid,int h){
        int n=v.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(mid>=v[i]) count++;
            else if(v[i]%mid==0)
                count+=v[i]/mid;
            else count+=v[i]/mid+1;
            if(count>h) return false;
        }
        if(count>h) return false;
        else return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=-1;
        int n=piles.size();
       
        for(int i=0;i<n;i++){
            ans = max(piles[i],ans);
       
        }
        int low=1,high=ans;
        ans=0;
        // if(n==h) return high;
        while(low<=high){
            int mid=(low+high)/2;
            if(f(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};