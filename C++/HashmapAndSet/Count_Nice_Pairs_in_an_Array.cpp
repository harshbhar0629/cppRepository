class Solution {
public:
    int rev(int n){
        int rev =0;
        while(n){
            rev = rev*10 +n%10;
            n/=10;
        }
        return rev;
    }
    int fact(int n){
        int fact =1;
        for(int i=2;i<=n;i++){
            fact*= i;
        }
        return fact;
    }

    int combi(int n , int r){
        return fact(n)/fact(r)*fact(n-r);
    }

    int countNicePairs(vector<int>& nums) {
        int count=0;
        int N =1e9+7;
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            nums[i] = nums[i] - rev(nums[i]);
            mp[nums[i]]++;
        }
        for(auto it: mp){
            if(it.second > 1){
                count += combi(it.second,2);
            }
        }
      
        return count;
    }
};



class Solution {
public:
    int rev(int n){
        int rev =0;
        while(n){
            rev = rev*10 +n%10;
            n/=10;
        }
        return rev;
    }

    int countNicePairs(vector<int>& nums) {
        int count=0;
        int N =1e9+7;
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            nums[i] = nums[i] - rev(nums[i]);
            if(mp[nums[i]] > 0){
                count += mp[nums[i]];
                count %= N; // V.IMP
            }
            mp[nums[i]]++;
        }
    
        return count;
    }
};