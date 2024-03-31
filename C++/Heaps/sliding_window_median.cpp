// // https://leetcode.com/problems/sliding-window-median/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {

    double getMedian( priority_queue<int,vector<int> ,greater<int> > minHeap,priority_queue<int> maxHeap,int x,int y){
        if(x==y){
            return 1.0*(minHeap.top()+maxHeap.top())/2.0;
        }
        else return 1.0*maxHeap.top();
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        int x =0,y=0;
        int n = nums.size();
        priority_queue<int,vector<int> ,greater<int> > minHeap;
        priority_queue<int> maxHeap;
        
        // iterate in first window
        for(int i=0; i<k; i++){
           
            int ele = nums[i];
            // first push the element 
            if(maxHeap.empty() || ele <= maxHeap.top()){
                maxHeap.push(ele);
                x++;
            }else {
                minHeap.push(ele);
                y++;
            }
 
            // providing balancing
            if(x > y+1){
                int a = maxHeap.top();
                minHeap.push(a);
                maxHeap.pop();
                x--; y++;
            }
            else if(y > x){
                int a = minHeap.top();
                maxHeap.push(a);
                minHeap.pop();
                y--; x++;
            }
    
        }
        
        vector<double> ans;
        ans.push_back(getMedian(minHeap,maxHeap,x,y));
        unordered_map<int,int> mp;

        for(int i=k;i<n;i++){
    
            int deletedEle = nums[i-k];
            int curr = nums[i];

            if(curr <= maxHeap.top()){
                x++;
                maxHeap.push(curr);
            }
            else{
                y++;
                minHeap.push(curr);
            }

            // check is it balanced or not
            if(x>y+1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                x--; y++;
            }
            else if(y > x){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                x++; y--;
            }

            // now worked on minHeap for deletion 
            mp[deletedEle]++;

            while(!minHeap.empty() and mp.count(minHeap.top()) > 0){
                
                int ele = minHeap.top();
                int freq = mp.count(ele);
                minHeap.pop();
                // y--; 
                freq--;
                
                if(freq==0){
                    mp.erase(ele);
                }
                else{
                    mp[ele]--;
                }

                // providing balancing
                // if(x > y+1){
                //     minHeap.push(maxHeap.top());
                //     maxHeap.pop();
                //     x--; y++;
                // }
            }

            // working on maxHeap for deletion
            while(!maxHeap.empty() and mp.count(maxHeap.top()) > 0){
                    
                int ele = maxHeap.top();
                int freq = mp.count(ele);
                maxHeap.pop();
                // x--;
                 freq--;
                    
                if(freq==0){
                    mp.erase(ele);
                }
                else{
                    mp[ele]--;
                }

                // providing balancing
                // if(y > x){
                //     maxHeap.push(minHeap.top());
                //     minHeap.pop();
                //     x++; y--;
                // }
            }

            if(ans.back() <= maxHeap.top()){
                x--;
            }
            else{
                y--;
            }

            // // providing balancing
            if(x>y+1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                x--; y++;
            }
            else if(y > x){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                x++; y--;
            }
            double a = getMedian(minHeap,maxHeap,x,y);
            ans.push_back(a);
        }
        return ans;  
    }
};

int main(){

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // string n;
    // cin >> n;
    // cout << n;
    vector<int> v ={1,2,3,4,2,3,1,4,2};
    int k =3;
    Solution s;
    vector<double> ans = s.medianSlidingWindow(v,k);
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i] <<" ";
    }cout<<endl;
    // 1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000
    // 2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <set>

// using namespace std;

// vector<double> medianSlidingWindow(vector<int>& nums, int k) {
//     vector<double> medians;
//     multiset<int> window(nums.begin(), nums.begin() + k);
//     auto mid = next(window.begin(), k / 2);
//     medians.push_back((double)*mid);

//     for (int i = k; i < nums.size(); i++) {
//         window.erase(window.find(nums[i - k]));
//         window.insert(nums[i]);
//         mid = next(window.begin(), k / 2);
//         if (k % 2 == 0) {
//             medians.push_back((double)(*mid + *prev(mid)) / 2);
//         } else {
//             medians.push_back((double)*mid);
//         }
//     }

//     return medians;
// }

// int main() {
//     vector<int> nums = {1,3,-1,-3,5,3,6,7};
//     int k = 3;
//     vector<double> medians = medianSlidingWindow(nums, k);
//     for (double median : medians) {
//         cout << median << " ";
//     }
//     cout << endl;

//     return 0;
// }
