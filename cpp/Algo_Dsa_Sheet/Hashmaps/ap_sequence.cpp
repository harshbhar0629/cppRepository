#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/check-arithmetic-progression1842/1

class Solution
{
public:
    bool checkIsAP(int arr[], int n)
    {
        // sort(arr, arr+n);
        // int diff = arr[1] - arr[0];
        // for(int i=2; i<n; i++){
        //     if(arr[i] - arr[i-1] != diff){
        //         return false;
        //     }
        // }

        unordered_map<int, int> mp;
        int first_small = INT_MAX, second_small = INT_MAX;
        for (int i = 0; i < n; i++){
            if (arr[i] < first_small){
                second_small = first_small;
                first_small = arr[i];
            }
            else if (arr[i] != first_small and arr[i] < second_small){
                second_small = arr[i];
            }
            mp[arr[i]]++;
            // for duplicates like if d=0 then it have all same number
            if (mp[arr[i]] != i + 1 and mp[arr[i]] > 1){
                return false;
            }
        }
        if (mp[arr[0]] == n){
            return true;
        }
        int diff = second_small - first_small;

        for (int i = 0; i < n; i++){
            if (mp.find(first_small) == mp.end()){
                return false;
            }
            first_small += diff;
        }

        return true;
    }
};

int main(){
    

    return 0;
}