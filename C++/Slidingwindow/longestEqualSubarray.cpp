class Solution {

    int findLongestSubarray(vector<int>& v,int k){
        
        int n =v.size();
        int ans =0,len =0,start=0;
        for(int i=0;i<n;++i){
         
            if(i==0) len++;
            else{
                int diff = (v[i]-v[i-1]) -1;
                k-=diff;
                while(k<0){
         
                    start++;
                    k += (v[start]-v[start-1]) -1;
                    len--;
                }
                
                len++;
            }

            ans = max(ans,len);
        }
        return ans;
    }

public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        
        map<int,vector<int>>mp;
        for(int i=0 ; i<nums.size(); ++i){
            mp[nums[i]].push_back(i);
        }

        int ans=1;
        for(auto &it: mp){
           
            int val =findLongestSubarray(it.second,k) ;
            if(val > ans){
                ans = val;
            }
        }

        return ans;
    }
};