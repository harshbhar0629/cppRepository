// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
#include<bits/sdtc++.h>
using namespace std;
class Solution{
public:
    vector<int> minPartition(int coin)
    {
        int arr[]={1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        vector<int> ans;
        int n = 10;
        for(int i=n-1; i>=0 ; i--){
            while(coin>=arr[i]){
                ans.push_back(arr[i]);
                coin-=arr[i];
            }
        }
        return ans;
    }
};